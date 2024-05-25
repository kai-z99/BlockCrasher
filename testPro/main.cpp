#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}

// nerf level 2
// if not making new levels, kick player to level select when press space on level 13 win screen
// also prevent coming soons from being clicked
// maybe make it more obvoius there are more pages on level select (idea, draw Polygon (not lines) insdie the arrow and flash it slowly using a sine wave)
//change UI drawing section to use a menuHandler or something
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