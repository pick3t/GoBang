
#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "board.hpp"

#define MAX_ROW_LEN 18
#define MAX_COL_LEN 18

using namespace std;

int main()
{
    cout << "start" << endl;
    Board *board = new Board(MAX_ROW_LEN, MAX_COL_LEN);
    board->BoardDisplay();
    delete board;
    cout << "end" << endl;
    return 0;
}