#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


// if not making new levels, kick player to level select when press space on level 13 win screen
// also prevent coming soons from being clicked
//change UI drawing section to use a menuHandler or something6
//maze level
//make level appear behind menu when hovering maybe
//combine the input handlers!!!
//poke
// matrix
// homing missile
// freight train
//reset direction on try again
//Update to new non placeholder sounds
//portal item