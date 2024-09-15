//
// Created by Javier Carrillo on 9/14/24.
//

#include <cstdlib> //rand
#include <ctime> // time
#include <iostream>
#include "board.h"


Board::Board(int m, int n) {
    int **board = new int *[m];

    for (int i = 0; i < m; i++) {
        board[i] = new int[n];
    }

    // Set class variables
    this->board = board;
    this->rows = std::max(2, m); // At least 2 x 2
    this->cols = std::max(2, n);
    this->t = 0;
    this->population = 0;
}

void Board::fill_random(float p) {
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            float randomFloat = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

            if (randomFloat <= p) {
                board[i][j] = 1;
                population++;
            }
        }
    }
}

void Board::print_state() const {
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
    std::cout << population << " " << t << "\n";
}

void Board::next_state() {
    // Create the new board
    int **new_board = new int*[rows];
    for (int i = 0; i < rows; i++) {
        new_board[i] = new int[cols];
    }

    // Calculate around center i,j
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // Check 8 surrounding cells
            int alive = 0;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    if (a == 0 &&  b == 0) { continue; }

                    alive += this->get(i+a, j+b);
                }
            }

            // Update cell
            new_board[i][j] = this->apply_rules(board[i][j], alive);
        }
    }

    // Set the new board as the board
    delete [] board;
    board = new_board;
    t++;
}

int Board::apply_rules(int current, int alive) {
    if (current) {
        switch (alive) {
            case 2:
            case 3:
                return current;
            default:
                this->population -= 1;
                return 0;
        }
    }

    if (alive == 3) {
        this->population += 1;
        return 1;
    }

    return current;
}


int Board::get(int row, int col) const {
    if (row < this->rows && row >= 0 && col < this->cols && col >= 0) {
        return board[row][col];
    }
    return 0;
}
