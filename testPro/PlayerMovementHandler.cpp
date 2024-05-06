#include <cmath>
#include "Player.h"
#include "PlayerMovementHandler.h"
#include "Constants.h"


PlayerMovementHandler::PlayerMovementHandler()
{}

void PlayerMovementHandler::HandlePlayerMovement(Player* p)
{
    float moveSpeed = 6.0;
    float dx = 0;
    float dy = 0;

    if (IsKeyDown(KEY_A) && p->GetPosX() > 0)
    {
        dx -= moveSpeed;
    }

    if (IsKeyDown(KEY_D) && p->GetPosX() < screenWidth)
    {
        dx += moveSpeed;
    }

    if (IsKeyDown(KEY_W) && p->GetPosY() > 0)
    {
        dy -= moveSpeed;
    }

    if (IsKeyDown(KEY_S) && p->GetPosY() < screenHeight) 
    {
        dy += moveSpeed;
    }

    // Normalize diagonal speed
    if (dx != 0 && dy != 0)
    {
        float norm = std::sqrt(dx * dx + dy * dy);
        dx = (dx / norm) * moveSpeed;
        dy = (dy / norm) * moveSpeed;
    }
    
    
    if (dx == 0 && dy < 0)
    {
        p->SetDirection(N);
    }

    else if (dx > 0 && dy == 0)
    {
        p->SetDirection(E);
    }

    else if (dx == 0 && dy > 0)
    {
        p->SetDirection(S);
    }

    else if (dx < 0 && dy == 0)
    {
        p->SetDirection(W);
    }

    else if (dx > 0 && dy < 0)
    {
        p->SetDirection(NE);
    }

    else if (dx < 0 && dy > 0)
    {
        p->SetDirection(SW);
    }

    else if (dx > 0 && dy > 0)
    {
        p->SetDirection(SE);
    }

    else if (dx < 0 && dy < 0)
    {
        p->SetDirection(NW);
    }
    p->Move(dx, dy);
}
