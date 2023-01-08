#include "container.hpp"

using namespace ChessGame;

template <class _Chess>
void ChessContainer<_Chess>::Contain(std::shared_ptr<_Chess> chess)
{
    this->data = std::move(chess);
    this->isOccupied = true;
}

template <class _Chess>
void ChessContainer<_Chess>::Remove()
{
    this->data = nullptr;
    this->isOccupied = false;
}

template <class _Chess_>
std::ostream &operator<<(std::ostream &os, const ChessContainer<_Chess_> &container)
{
    if (container.isOccupied) {
        return os << *container.data;
    }
    
    return os << container.DEFAULT_SYMBOL;
}