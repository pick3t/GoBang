#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstdint>
#include <vector>
#include "chess.hpp"

using namespace std;

#define MAX_CHESS_NUM 18 * 18

enum ChessPlaceStatus {
    CHESS_PLACE_SUCCESS = 0,
    CHESS_PLACE_FAIL,
    CHESS_OUT_OF_BOUNDS,
    CHESS_NO_PLACE,
};

class Board {
    private:
        uint8_t BoardRowLen;
        uint8_t BoardColLen;
        uint16_t BoardTotalChess;
        vector<vector<Chess*>> board;
        bool BoardIsFull();
    public:
        Board(uint8_t maxRowLen, uint8_t maxColLen):BoardRowLen(maxRowLen), BoardColLen(maxColLen),
            board(BoardRowLen, vector<Chess*>(BoardColLen))
        {
            BoardTotalChess = 0;
            for (int i = 0; i < BoardRowLen; i++)
            {
                for (int j = 0; j < BoardColLen; j++)
                {
                    board[i][j] = new Chess(i, j);
                }
            }
        }
        ~Board();
        uint32_t BoardPlaceChess(Chess *chess);
        void BoardDisplay();
        uint8_t BoardGetRowLen();
        uint8_t BoardGetColLen();
};

#endif