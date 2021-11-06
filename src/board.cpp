#include <cstdint>
#include <iostream>
#include <vector>

#include "board.hpp"

using namespace std;

Board::~Board()
{
    for (int i = 0; i < BoardRowLen; i++)
    {
        for (int j = 0; j < BoardColLen; j++)
        {
            delete board[i][j];
        }
    }
}

uint8_t Board::BoardGetRowLen()
{
    return BoardRowLen;
}

uint8_t Board::BoardGetColLen()
{
    return BoardColLen;
}

bool Board::BoardIsFull()
{
    return BoardTotalChess >= MAX_CHESS_NUM;
}

uint32_t Board::BoardPlaceChess(Chess *chess)
{
    uint8_t ChessRowIndex = chess->ChessGetRowIndex();
    uint8_t ChessColIndex = chess->ChessGetColIndex();

    if (ChessRowIndex < 0 || ChessRowIndex >= BoardRowLen)
    {
        return CHESS_OUT_OF_BOUNDS;
    }
    else if (ChessColIndex < 0 || ChessColIndex >= BoardColLen)
    {
        return CHESS_OUT_OF_BOUNDS;
    }
    else if (board[ChessRowIndex][ChessColIndex]->ChessGetColor() != COLOR_MAX)
    {
        return CHESS_PLACE_FAIL;
    }

    delete board[ChessRowIndex][ChessColIndex];
    board[ChessRowIndex][ChessColIndex] = chess;
    BoardTotalChess++;

    if (BoardIsFull())
    {
        return CHESS_NO_PLACE;
    }

    return CHESS_PLACE_SUCCESS;
}

void Board::BoardDisplay()
{
    for (int i = 0; i < BoardRowLen; i++)
    {
        for (int j = 0; j < BoardColLen; j++)
        {
            printf("%c ", board[i][j]->ChessConvertColorToIcon());
        }
        printf("\n");
    }
}