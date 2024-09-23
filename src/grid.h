//
// Created by Javier Carrillo on 9/23/24.
//

#ifndef GRID_H
#define GRID_H
#include "board.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <memory>


// Grid class for drawing on canvas
class Grid {
    std::unique_ptr<Board> b;
    int rows;
    int cols;
    int cell_size;
    int margin;
public:
    /**
     *  Constructs a grid object with a Board of the same size
     * @param rows # of rows
     * @param cols # of columns
     * @param cell_size size of rendered cells
     * @param margin size of margins around the grid
     * @param p Probability of a cell of starting filled
     */
    Grid(int rows, int cols, int cell_size, int margin, float p);

    /**
     * Draws the current state of the board to the window
     * @param window Window obj
     */
    void draw(sf::RenderWindow& window);

    /**
     * Advances a step in the simulation
     */
    void advance();


};



#endif //GRID_H
