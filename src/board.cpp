//
// Created by Javier Carrillo on 9/14/24.
//

#include <cstdlib> //rand
#include <ctime> // time
#include <iostream>
#include "board.h"
#include "debug.h"



Board::Board(int m, int n) {
    int ** board = new int*[m];

    for (int i = 0; i < m; i++) {
        board[i] = new int[n];
    }

    // Set class variables
    this->board = board;
    this->rows = m;
    this->cols = n;
}

void Board::fill_random(float p) {
    srand(time(NULL));

    for (int i = 0; i < rows; i++ ) {
        for (int j = 0; j < cols; j++) {
            float randomFloat = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

            if (randomFloat <= p) {
                board[i][j] = 1;
            }
        }
    }
}

void Board::print_state() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

