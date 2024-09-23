//
// Created by Javier Carrillo on 9/23/24.
//

#include "grid.h"

#include "SFML/Graphics.hpp"

Grid::Grid(int rows, int cols, int cell_size, int margin){
    this->b = std::make_unique<Board>(rows, cols);
    this->cols = cols;
    this->rows = rows;
    this->cell_size = cell_size;
    this->margin = margin;

    this->b->fill_random(0.5f);
}

void Grid::draw(sf::RenderWindow& window) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sf::RectangleShape cell(sf::Vector2f(cell_size, cell_size));
            cell.setPosition(margin + j * cell_size, margin + i * cell_size);

            // Set color
            if (this->b->get(i, j)) {
                cell.setFillColor(sf::Color::White);
            } else {
                cell.setFillColor(sf::Color::Black);
            }

            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);
        }
    }
}
