#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}

//add ~Game destructor
//upload ChooseLevel sound
//Time out, retry sounds
// move with arrow keys too.
//choose color menu (ColorPicker object, currentColor, Draw())
//maze level
//make level appear behind menu when hovering maybe
//combine the input handlers
//the vortex
//poke
// matrix
// homing missile
//"choose level with WASD / arrow keys. Press SPACE / ENTER to play!" in level select menu
//reset direction on try again
//Update to new non placeholder sounds
//portal item