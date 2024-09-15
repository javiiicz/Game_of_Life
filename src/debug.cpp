//
// Created by Javier Carrillo on 9/14/24.
//

#include "debug.h"
#include "board.h"

void debug::test() {
    Board b (100,200);
    b.fill_random(0.01f);
    b.print_state();
}