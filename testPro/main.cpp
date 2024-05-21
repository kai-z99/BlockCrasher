#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


// maybe make it more obvoius there are more pages on level select
//change UI drawing section to use a menuHandler or something
//upload ChooseLevel sound
// press r to restart
//maze level
//make level appear behind menu when hovering maybe
//combine the input handlers!!!
//the storm (diagonal cross screening)
//poke
// matrix
// homing missile
//reset direction on try again
//Update to new non placeholder sounds
//portal item