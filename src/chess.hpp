#ifndef CHESS_HPP
#define CHESS_HPP

#include <cstdint>
#include <iostream>

namespace ChessGame {

enum class Color : uint8_t
{
    COLOR_BLACK = 0,
    COLOR_WHITE = 1,
    COLOR_DEFAULT = 2,
    COLOR_MAX,
};

class Chess
{
    public:
        uint8_t row;
        uint8_t col;
        Color color;

        explicit Chess():row(0), col(0), color(Color::COLOR_DEFAULT) { };
        explicit Chess(uint8_t rowIndex, uint8_t colIndex, Color color):row(rowIndex), col(colIndex),
            color(color) { }

        friend std::ostream& operator<<(std::ostream& os, const Chess& chess);

        const char* Color2Icon() const;
};

std::ostream& operator<<(std::ostream& os, const Chess& chess);

}

#endif