#include <SFML/Graphics.hpp>
#include "logic.h"
#include "debug.h"




int main()
{
    debug d;

    int rows = 40;
    int cols = 20;

    int** board = new int*[rows];
    for (int i =0; i < rows; i++) {
        board[i] = new int[cols];
    }

    d.print_state(rows, cols, board);
    // auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    // window.setFramerateLimit(144);
    //
    // while (window.isOpen())
    // {
    //     for (auto event = sf::Event{}; window.pollEvent(event);)
    //     {
    //         if (event.type == sf::Event::Closed)
    //         {
    //             window.close();
    //         }
    //     }
    //
    //     window.clear();
    //     window.display();
    // }

}
