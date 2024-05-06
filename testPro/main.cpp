#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


//UI handler class. (DrawLevelCompleteText, DrawTryAgainText, DrawMenu, etc)
// fix dynam,ic obstacle hitbox (4 pints on player) TO DO THIS, MAKE DRAWING THE PLAYER DRAW TO THE CENTER. THEN YOU WONT HAVE TO HAVE SEPRATE COLLISION FOR EACH DIRECTION
// purtple star coins
//levels should be timed
//add a menu
//maze level
