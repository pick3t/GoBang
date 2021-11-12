
#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "board.hpp"

#define MAX_ROW_LEN 18
#define MAX_COL_LEN 18

using namespace std;

typedef enum turn {
    TURN_BLACK,
    TURN_WHITE,
    TURN_MAX,
} Turn;

Color GetColorFromTurn(Turn turn)
{
    return turn == TURN_BLACK ? COLOR_BLACK : COLOR_WHITE;
}

int main()
{
    cout << "start" << endl;
    Board *board = new Board(MAX_ROW_LEN, MAX_COL_LEN);

    while (!board->BoardIsFull()) {
        for (int i = TURN_BLACK; i < TURN_MAX; i++) {
            int row, col;
            cin >> row;
            cin >> col;
            Color color = GetColorFromTurn((Turn)i);
            Chess *chess = new Chess(static_cast<uint8_t>(row), static_cast<uint8_t>(col), color);
            uint32_t ret = board->BoardPlaceChess(chess);
            if (ret != CHESS_PLACE_SUCCESS) {
                return 1;
            }
            board->BoardDisplay();
        }
    }
    delete board;
    cout << "end" << endl;
    return 0;
}