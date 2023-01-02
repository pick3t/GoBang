
#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "board.hpp"

#define MAX_ROW_LEN 18
#define MAX_COL_LEN 18

using namespace std;
using namespace ChessGame;

typedef enum turn
{
    TURN_BLACK,
    TURN_WHITE,
    TURN_MAX,
} Turn;

Color GetColorFromTurn(Turn turn)
{
    return turn == TURN_BLACK ? Color::COLOR_BLACK : Color::COLOR_WHITE;
}

int main()
{
    cout << "start" << endl;
    Board board = Board(MAX_ROW_LEN, MAX_COL_LEN);
    board.Display();

    while (!board.IsFull())
    {
        int i = TURN_BLACK;
        while (i != TURN_MAX)
        {
            int row, col;
            cout << "row: ";
            cin >> row;
            cout << "col: ";
            cin >> col;

            Color color = GetColorFromTurn((Turn)i);
            uint32_t ret = board.PlaceChess(std::make_shared<Chess>(row, col, color));
            if (ret != CHESS_PLACE_SUCCESS)
            {
                if (ret == CHESS_OUT_OF_BOUNDS) {
                    cout << "Chess is out of board, please input valid index.\n";
                    continue;
                }

                if (ret == CHESS_PLACE_TAKEN) {
                    cout << "This place already has a chess on it, please choose another location.\n";
                    continue;
                }

                return 1;
            }

            board.Display();
            i++;
        }
    }

    cout << "end" << endl;
    return 0;
}