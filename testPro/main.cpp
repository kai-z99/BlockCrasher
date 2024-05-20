#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


// we dont need such an advacned Music manager, just use a vector no enums and use song id int
//change UI drawing section to use a menuHandler or something
//upload ChooseLevel sound
// press r to restart
//press space / enter to confirm color
//Time out, retry sounds
// move with arrow keys too.
//maze level
//make level appear behind menu when hovering maybe
//combine the input handlers!!!
//the storm
//poke
// matrix
// homing missile
//reset direction on try again
//Update to new non placeholder sounds
//portal item