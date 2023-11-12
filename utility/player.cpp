#include "player.hpp"

#include <mutex>
#include <string>
#include <stdexcept>

using namespace Utility;

Player::Player(std::string&& name, uint32_t &id) noexcept {
    name = std::move(name);
    id = id;
}

std::unique_ptr<Player> PlayerManager::createPlayer(std::string&& name) {
    std::lock_guard<std::mutex> lock(usedNamesLock);
    if (usedNames.find(name) != usedNames.end()) {
        throw std::runtime_error("Name already in use: " + name);
    }
    usedNames.insert(name);

    uint32_t id = totalPlayers++;

    return std::unique_ptr<Player>(new Player(std::move(name), id));
}

std::unique_ptr<Player> PlayerManager::createPlayer() {
    std::lock_guard<std::mutex> lock(totalPlayerLock);

    const std::string prefix = "Player_";
    std::string name = prefix + std::to_string(totalPlayers);

    return createPlayer(std::move(name));
}
