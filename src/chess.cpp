#include "chess.hpp"

#include <cstdint>
#include <iostream>
#include <unordered_map>

#include "enum_str_map.hpp"

using namespace ChessGame;
using namespace CommonTools;

std::unordered_map<Color, const char*> g_color2Str;
auto g_color2StrMap = map_init(g_color2Str)
    (Color::COLOR_BLACK, "x")
    (Color::COLOR_WHITE, "o")
    (Color::COLOR_DEFAULT, "+")
;

const char* Chess::Color2Icon() const
{
    return g_color2StrMap[this->color];
}

// std::ostream& operator<<(std::ostream& os, const Chess& chess)
// {
//     return os << chess.Color2Icon();
// }