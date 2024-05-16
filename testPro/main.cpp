#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


// move with arrow keys too.
//make tryagain and level complete menus then draw those menus instead of it being hardcoded in game.
//maze level
//make level appear behind menu when hovering maybe
//add sounds!!?
//combine the input handlers
//resolve warnings
//create title screen. maybe multiple menuHandler states
//the vortex
//poke
// matrix
// //homing missile
//"choose level with WASD / arrow keys. Press SPACE / ENTER to play!" in level select menu
//reset direction on try again