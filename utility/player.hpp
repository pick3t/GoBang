#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdint>
#include <mutex>
#include <unordered_set>
#include <string>
#include <memory>
#include <vector>

namespace Utility {
    class PlayerManager;

    class Player {
        private:
            uint32_t id;
            std::string name;

            explicit Player(std::string&& name, uint32_t &id) noexcept;
            friend class PlayerManager;

        public:
            Player(const Player&&) = delete;
            Player(const Player&) = delete;
            Player &operator=(const Player&&) = delete;
            Player &operator=(const Player&) = delete;
    };

    using TwoPlayers = std::pair<std::unique_ptr<Player>, std::unique_ptr<Player>>;

    class PlayerManager {
        private:
            std::mutex poolLock;
            std::vector<std::unique_ptr<Player>> pool;

            std::mutex usedNamesLock;
            std::unordered_set<std::string> usedNames;

            std::mutex totalPlayerLock;
            uint32_t totalPlayers;
            
        public:
            std::unique_ptr<Player> createPlayer(std::string&& name);
            std::unique_ptr<Player> createPlayer();

            void joinPool(std::unique_ptr<Player> p) {
                std::lock_guard<std::mutex> lock(poolLock);
                pool.push_back(std::move(p));
            }

            uint32_t poolSize() {
                std::lock_guard<std::mutex> lock(poolLock);
                return pool.size();
            }

            TwoPlayers first2FromPool() {
                std::lock_guard<std::mutex> lock(poolLock);
                if (pool.size() < 2) {
                    return std::make_pair(nullptr, nullptr);
                }

                TwoPlayers players = std::make_pair(std::move(pool[0]), std::move(pool[1]));
                pool.erase(pool.begin(), pool.begin() + 2);
                return players;
            }

    };
}

#endif
