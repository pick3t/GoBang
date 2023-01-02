#include <cstdint>
#include <iostream>
#include <vector>
#include <memory>

#include "board.hpp"

using namespace std;
using namespace ChessGame;

Board::Board(uint8_t maxRow, uint8_t maxCol) : maxRow(maxRow), maxCol(maxCol), board(maxRow, vector<std::shared_ptr<Chess>>(maxCol))
{
    totalChess = 0;
    for (auto &row : board)
    {
        for (auto &col : row)
        {
            col = std::make_shared<Chess>();
        }
    }
}

Board::~Board()
{
}

bool Board::IsFull()
{
    return totalChess >= MAX_CHESS_NUM;
}

uint32_t Board::PlaceChess(std::shared_ptr<Chess> chess)
{
    if (IsFull())
    {
        return CHESS_FULL;
    }

    if (chess->row >= maxRow || chess->col >= maxCol)
    {
        return CHESS_OUT_OF_BOUNDS;
    }
    else if (board[chess->row][chess->col]->color != Color::COLOR_DEFAULT)
    {
        return CHESS_PLACE_TAKEN;
    }

    board[chess->row][chess->col] = std::move(chess);
    totalChess++;

    return CHESS_PLACE_SUCCESS;
}

void Board::Display()
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
            printf("%s  ", board[i][j]->Color2Icon());
        }
        printf("\n\n");
    }
}