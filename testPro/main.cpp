#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


//
//change movemthandler to be calle inputhandler!
// fix dynam,ic obstacle hitbox (4 pints on player)
//  ball bouncing should probably be a diuffernt level than the sword
//dash ability
//ADD MORE COMMENTS
//levels should be timed
