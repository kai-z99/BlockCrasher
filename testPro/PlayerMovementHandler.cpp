
#include "Player.h"
#include "PlayerMovementHandler.h"


PlayerMovementHandler::PlayerMovementHandler()
{}

void PlayerMovementHandler::HandlePlayerMovement(Player* p)
{
    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
    {
        p->Move(3, -3);
        p->SetDirection(NE);
    }
    else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D))
    {
        p->Move(3, 3);
        p->SetDirection(SE);
    }
    else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A))
    {
        p->Move(-3, 3);
        p->SetDirection(SW);
    }
    else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A))
    {
        p->Move(-3, -3);
        p->SetDirection(NW);
    }
    //change 1 sdfef
    //dsaads
    else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
    {
    }

    else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_S))
    {
    }

    else if (IsKeyDown(KEY_A))
    {
        p->Move(-3, 0);
        p->SetDirection(W);
    }
    else if (IsKeyDown(KEY_W))
    {
        p->Move(0, -3);
        p->SetDirection(N);
    }
    else if (IsKeyDown(KEY_D))
    {
        p->Move(3, 0);
        p->SetDirection(E);
    }
    else if (IsKeyDown(KEY_S))
    {
        p->Move(0, 3);
        p->SetDirection(S);
    }
}
