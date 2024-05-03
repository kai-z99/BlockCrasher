#include <raylib.h>
#include <iostream>
#include "Game.h"


int main() {
    Game game = Game();
    game.Run();

    return 0;
}


// 
// coin class
// fix obstaclePosition on rectangle and curcle object (use same idea as dyunamic polygon)
// fix dynam,ic obstacle hitbox (4 pints on player)
// chidlren of obsatcle like rotationg square, large tower roattor, bullet, etc
// //make shapes move. (Make update a pure virtual in Obstacle.h, then add movement to the children.)
//game class
//dash ability
//ADD MORE COMMENTS
// include organize consult
