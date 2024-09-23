#include <SFML/Graphics.hpp>
#include "grid.h"

int main() {
    // Parameters
    const int ROWS = 100;
    const int COLS = 200;
    const int CELL_SIZE = 5;
    const int MARGIN = 50;
    const float PROB = 0.3f;

    bool isPlaying = false;

    Grid g(ROWS, COLS, CELL_SIZE, MARGIN, PROB);

    sf::RenderWindow window(sf::VideoMode(COLS * CELL_SIZE + 2*  MARGIN, ROWS * CELL_SIZE + 2 * MARGIN), "Game of Life");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Start / Stop with spacebar
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    isPlaying = !isPlaying;
                }
            }

            // Step with right arrow
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    g.advance();
                }
            }
        }

        window.clear();
        g.draw(window);
        window.display();
        if (isPlaying) {
            g.advance();
        }
    }
}
