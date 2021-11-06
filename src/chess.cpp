#include <cstdint>
#include <iostream>

#include "chess.hpp"

using namespace std;

void Chess::ChessSetColor(Color color)
{
    ChessColor = color;
}

void Chess::ChessDisplay()
{
    cout << +ChessRowIndex << endl;
    cout << +ChessColIndex << endl;
    cout << ChessColor << endl;
}

Icon Chess::ChessConvertColorToIcon()
{
    Icon icon = '+';
    switch (ChessColor)
    {
    case COLOR_BLACK:
        icon = 'x';
        break;
    case COLOR_WHITE:
        icon = 'o';
        break;
    default:
        break;
    }

    return icon;
}