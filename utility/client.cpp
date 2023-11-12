#include <iostream>
#include <deque>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace Utility {
    class Client {
    public:
        Client(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoints)
            : socket_(io_context) {
            doConnect(endpoints);
        }

        void write(const std::string& msg) {
            boost::asio::post(socket_.get_executor(),
                [this, msg]() {
                    bool writeInProgress = !writeMessages_.empty();
                    writeMessages_.push_back(msg);
                    if (!writeInProgress) {
                        doWrite();
                    }
                });
        }

    private:
        void doConnect(const tcp::resolver::results_type& endpoints) {
            boost::asio::async_connect(socket_, endpoints,
                [this](boost::system::error_code ec, tcp::endpoint) {
                    if (!ec) {
                        doReadHeader();
                    }
                });
        }

        void doReadHeader() {
            // insert your code here to read from the server
        }

        void doWrite() {
            // insert your code here to write to the server
        }

        tcp::socket socket_;
        std::deque<std::string> writeMessages_;
    };
}

int main() {
    try {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "8080");
        Utility::Client client(io_context, endpoints);

        std::thread t([&io_context]() { io_context.run(); });

        std::string line;
        while (std::getline(std::cin, line)) {
            client.write(line);
        }

        t.join();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
