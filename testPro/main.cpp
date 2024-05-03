#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


// change CollisionManger.CheckCollsions to return int, maybe 0 for no collision, 1 for ob, 2 for coin, etc
// coin class !!!!!
// fix dynam,ic obstacle hitbox (4 pints on player)
//  ball bouncing should probably be a diuffernt level than the sword
//game class
//dash ability
//ADD MORE COMMENTS
// include organize consult
//levels should be timed
