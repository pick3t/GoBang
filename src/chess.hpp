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
    friend std::ostream& operator<<(std::ostream& os, const Chess& chess)
    {
        return os << chess.Color2Icon();
    }

    public:
        Color color;

        explicit Chess():color(Color::COLOR_DEFAULT) { };
        explicit Chess(Color color):color(color) { };
        const char* Color2Icon() const;
};

// std::ostream& operator<<(std::ostream& os, const Chess& chess);

}

#endif