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
    int population; // Number of cells alive
    int t; // Time in simulation

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
    void print_state() const;

    /**
     * Applies the following logic to the current board state:
     * 1. Any cell with < 2 live neighbors becomes a 0
     * 2. Any alive cell with 2 or 3 live neighbors stays a 1
     * 3. Any cell > 3 neighbors becomes a 0
     * 4. Any dead cell with exactly 3 live neighbors becomes a 1
     */
    void next_state();

    /**
     * Returns 1 or 0 depending on the Game's rules
     * @param current Current state of cell to switch
     * @param alive Number of neighbors alive
     * @return 1 or 0
     */
    int apply_rules(int current, int alive);

    /**
     * Checks bounds and returns the state of cell in [row][col]. Out of bounds = 0
     * @param row Row of cell to check
     * @param col Column of cell to check
     * @return Integer state of cell
     */
    int get(int row, int col) const;


};



#endif //LOGIC_H
