//
// Created by Javier Carrillo on 9/14/24.
//

#include <iostream>
#include "debug.h"

using namespace std;

void debug::print_state(int rows, int cols, int **board) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
