#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstdint>
#include <vector>
#include <memory>

using namespace std;

namespace ChessGame
{

    enum ChessPlaceStatus
    {
        PLACE_SUCCESS = 0,
        POSITION_OCCUPIED,
        POSITION_OUT_OF_BOUNDS,
        POSITION_INVALID,
    };

    template <class _Container>
    class Board
    {
    private:
        const uint8_t DEFAULT_MAX_ROW = 18;
        const uint8_t DEFAULT_MAX_COL = 18;
        const uint16_t DEFAULT_MAX_MEMBER = DEFAULT_MAX_ROW * DEFAULT_MAX_COL;

        uint8_t maxRow;
        uint8_t maxCol;
        uint16_t maxMember;
        uint16_t totalMember;

        vector<vector<std::shared_ptr<_Container>>> board;
    public:
        inline bool IsFull()
        {
            return totalMember >= maxMember;
        }

        explicit Board();
        explicit Board(uint8_t maxRow, uint8_t maxCol);
        ~Board();

        template<class _Contained>
        uint32_t Place(uint8_t row, uint8_t col, std::shared_ptr<_Contained> member);

        void Display();
    };

}

#endif