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
     */
    Grid(int rows, int cols, int cell_size, int margin);

    /**
     * Draws the current state of the board to the window
     * @param window Window obj
     */
    void draw(sf::RenderWindow& window);


};



#endif //GRID_H
