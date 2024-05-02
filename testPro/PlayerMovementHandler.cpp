#include <cmath>
#include "Player.h"
#include "PlayerMovementHandler.h"



PlayerMovementHandler::PlayerMovementHandler()
{}

void PlayerMovementHandler::HandlePlayerMovement(Player* p)
{
    float moveSpeed = 6.0;
    float dx = 0;
    float dy = 0;

    if (IsKeyDown(KEY_A))
    {
        dx -= moveSpeed;
        p->SetDirection(W);
    }
    if (IsKeyDown(KEY_D))
    {
        dx += moveSpeed;
        p->SetDirection(E);
    }
    if (IsKeyDown(KEY_W))
    {
        dy -= moveSpeed;
        p->SetDirection(N);
    }
    if (IsKeyDown(KEY_S))
    {
        dy += moveSpeed;
        p->SetDirection(S);
    }

    // Normalize diagonal speed
    if (dx != 0 && dy != 0)
    {
        float norm = std::sqrt(dx * dx + dy * dy);
        dx = (dx / norm) * moveSpeed;
        dy = (dy / norm) * moveSpeed;

        if (dx > 0 && dy < 0)
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
    }

 

    p->Move(dx, dy);
}
