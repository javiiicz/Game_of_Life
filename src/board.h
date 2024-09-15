//
// Created by Javier Carrillo on 9/14/24.
//

#ifndef LOGIC_H
#define LOGIC_H



class Board {
    int **board; // Stores location of board object
    int rows; // Number of rows in board
    int cols; // Number of columns in board

public:
    /**
     * Creates an empty 2D array of specified dimensions and sets it internally
     * @param m number of rows
     * @param n number of columns
     */
    Board(int m, int n);

    /**
     * Sets randomly cells with 1, where each cell has a probability p of becoming a 1
     * @param p probability. Range between 0 and 1
     */
    void fill_random(float p);

    /**
     * Prints to console the current state of the board
     */
    void print_state();

    int population; // Number of cells alive
    int t; // Time in simulation
};



#endif //LOGIC_H
