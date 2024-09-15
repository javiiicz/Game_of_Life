//
// Created by Javier Carrillo on 9/14/24.
//

#include "debug.h"
#include "board.h"
#include <iostream>


void debug::test() {
    Board b (10,20);
    b.fill_random(0.4f);
    b.print_state();
    for (int i = 0; i < 100; i++) {
        std::cout << "-----------------------------------------------------------------------------------------";
        b.next_state();
        b.print_state();
    }

}