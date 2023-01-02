#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstdint>
#include <vector>
#include <memory>

#include "chess.hpp"

using namespace std;

#define MAX_CHESS_NUM 18 * 18

namespace ChessGame
{

    enum ChessPlaceStatus
    {
        CHESS_PLACE_SUCCESS = 0,
        CHESS_PLACE_TAKEN,
        CHESS_OUT_OF_BOUNDS,
        CHESS_FULL,
    };

    class Board
    {
    private:
        uint8_t maxRow;
        uint8_t maxCol;
        uint16_t totalChess;
        vector<vector<std::shared_ptr<Chess>>> board;

    public:
        explicit Board(uint8_t maxRow, uint8_t maxCol);
        ~Board();

        uint32_t PlaceChess(std::shared_ptr<Chess> chess);
        void Display();
        bool IsFull();
    };

}

#endif