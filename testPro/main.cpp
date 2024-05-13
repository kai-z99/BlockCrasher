#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


// fix dynam,ic obstacle hitbox (4 pints on player) TO DO THIS, MAKE DRAWING THE PLAYER DRAW TO THE CENTER. THEN YOU WONT HAVE TO HAVE SEPRATE COLLISION FOR EACH DIRECTION
//levels should be timed
//maze level
//make level appear behind menu when hovering maybe
//add sounds
//combine the input handlers
//resolve warnings
//create title screen. maybe multiple menuHandler states
//the vortex
//poke