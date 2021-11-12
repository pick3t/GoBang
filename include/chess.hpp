#ifndef CHESS_HPP
#define CHESS_HPP

#include <cstdint>

#define Icon char

typedef enum color
{
    COLOR_BLACK = 0,
    COLOR_WHITE = 1,
    COLOR_MAX,
} Color;

class Chess
{
public:
    Chess(uint8_t rowIndex, uint8_t colIndex, Color color):ChessRowIndex(rowIndex),ChessColIndex(colIndex),
        ChessColor(color) { }

    uint8_t ChessGetRowIndex() const { return ChessRowIndex; }
    uint8_t ChessGetColIndex() const { return ChessColIndex; }
    Color ChessGetColor() const { return ChessColor; }

    void ChessSetColor(Color color);
    void ChessDisplay();

    Icon ChessConvertColorToIcon();

private:
    uint8_t ChessRowIndex;
    uint8_t ChessColIndex;
    Color ChessColor;
};

#endif