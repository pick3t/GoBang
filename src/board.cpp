#include "board.hpp"

#include <cstdint>
#include <iostream>
#include <vector>
#include <memory>

#include "ret_code.hpp"
#include "chess.hpp"
#include "container.hpp"

using namespace std;
using namespace ChessGame;

template <class _Container>
Board<_Container>::Board(uint8_t maxRow, uint8_t maxCol) :
maxRow(maxRow), maxCol(maxCol), maxMember(maxRow * maxCol), totalMember(0), board(maxRow, vector<std::shared_ptr<_Container>>(maxCol))
{
    for (auto i = 0; i < maxRow; ++i)
    {
        for (auto j = 0; j < maxCol; ++j)
        {
            board[i][j] = std::make_shared<_Container>(i, j);
        }
    }
}

template <class _Container>
Board<_Container>::Board() : Board(DEFAULT_MAX_ROW, DEFAULT_MAX_COL)
{
}

template <class _Container>
Board<_Container>::~Board()
{
    for (auto &row : board)
    {
        for (auto &col : row)
        {
            col->Remove();
            col = nullptr;
        }
    }
}

template <class _Container>
template <class _Contained>
uint32_t Board<_Container>::Place(uint8_t row, uint8_t col, std::shared_ptr<_Contained> chess)
{
    if (row >= maxRow || col >= maxCol)
    {
        return POSITION_OUT_OF_BOUNDS;
    }

    std::shared_ptr<_Container> container = board[row][col];
    if (!container)
    {
        return POSITION_INVALID;
    }

    uint32_t ret = container->Contain(chess);
    if (ret != RC_OK) {
        return POSITION_OCCUPIED;
    }

    totalMember++;

    return PLACE_SUCCESS;
}

template <class _Container>
void Board<_Container>::Display()
{
    printf("   ");
    for (int i = 0; i < maxCol; i++)
    {
        printf("%02d ", i);
    }
    printf("\n");

    for (int i = 0; i < maxRow; i++)
    {
        printf("%02d ", i);
        for (int j = 0; j < maxCol; j++)
        {
            std::cout << *board[i][j] << " ";
        }
        printf("\n\n");
    }
}

/* instantiate of needed template class */
template class Board<ChessContainer<Chess>>;
template uint32_t Board<ChessContainer<Chess>>::Place(uint8_t, uint8_t, std::shared_ptr<Chess>);