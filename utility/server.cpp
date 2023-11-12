#include <iostream>
#include <vector>
#include <memory>
#include <boost/asio.hpp>

#include "player.hpp"

using boost::asio::ip::tcp;

namespace Utility {
    class Game {};

    class ChessGame : public Game {
        private:
            std::unique_ptr<Player> player1;
            std::unique_ptr<Player> player2;

        public: 
            ChessGame(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2) :
                player1(std::move(p1)), player2(std::move(p2)) {
                std::cout << "Game start" << std::endl;
            }
    };

    /* Server uses thread-safe singleton pattern */
    class Server {
        using BEndPoint = boost::asio::ip::tcp::endpoint;
    public:

        static Server& getInstance() {
            static Server instance;
            return instance;
        }

        void setEndPoint(BEndPoint& ep) {
            this->ep = ep;
        }

        void setEndPoint(BEndPoint&& ep) {
            this->ep = std::move(ep);
        }

        Server(Server const&) = delete;
        Server &operator=(Server const&) = delete;

        void listen() {
            std::cout << "Listening..." << std::endl;
            acceptor.open(ep.protocol());
            acceptor.bind(ep);
            acceptor.listen();

            acceptConnection();

            ioContext.run();
            std::cout << "Finished handling incoming connections." << std::endl;
        }

    private:
        BEndPoint ep;

        /* hide constructor for singleton */
        Server() { ep = {boost::asio::ip::tcp::v4(), 8080}; }

        boost::asio::io_context ioContext;
        boost::asio::ip::tcp::acceptor acceptor{ioContext};

        PlayerManager pManager;

        std::mutex gamePoolLock;
        std::vector<std::unique_ptr<Game>> gamePool;

        void createGame() {
            TwoPlayers players = pManager.first2FromPool();

            std::lock_guard<std::mutex> lock(gamePoolLock);
            gamePool.push_back(std::make_unique<ChessGame>(std::move(players.first), std::move(players.second)));
        }

        void acceptConnection() {
            acceptor.async_accept([this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
                std::cout << "Incoming new connection." << std::endl;

                if (ec) {
                    std::cerr << "Async accept error: " << ec.message() << std::endl;
                    return acceptConnection();
                }

                std::unique_ptr<Player> player = nullptr;
                try {
                    player = pManager.createPlayer();
                } catch(const std::runtime_error &e) {
                    std::cerr << "Failed creating player: " << e.what() << std::endl;
                    return acceptConnection();
                }

                pManager.joinPool(std::move(player));
                if (pManager.poolSize() < 2) {
                    return acceptConnection();
                }

                createGame();

                acceptConnection();
            });
        }

    };
}

using namespace Utility;

int main() {
    Server::getInstance().setEndPoint({boost::asio::ip::make_address("127.0.0.1"), 8080});
    Server::getInstance().listen();
}
