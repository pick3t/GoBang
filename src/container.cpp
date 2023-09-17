#include "container.hpp"

#include "ret_code.hpp"
#include "chess.hpp"

using namespace ChessGame;

template <class _Chess>
uint32_t ChessContainer<_Chess>::Contain(std::shared_ptr<_Chess> chess)
{
    if (this->isOccupied) {
        return -1;
    }

    this->data = std::move(chess);
    this->isOccupied = true;
    return 0;
}

template <class _Chess>
void ChessContainer<_Chess>::Remove()
{
    this->data = nullptr;
    this->isOccupied = false;
}

/* instantiate of needed template class */
template class ChessContainer<Chess>;