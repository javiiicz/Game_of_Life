#include <SFML/Graphics.hpp>
#include "grid.h"

int main() {
    // Parameters
    const int ROWS = 100;
    const int COLS = 200;
    const int CELL_SIZE = 5;
    const int MARGIN = 50;

    Grid g(ROWS, COLS, CELL_SIZE, MARGIN);

    sf::RenderWindow window(sf::VideoMode(COLS * CELL_SIZE + 2*  MARGIN, ROWS * CELL_SIZE + 2 * MARGIN), "Game of Life");

    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        g.draw(window);
        window.display();
    }
}
