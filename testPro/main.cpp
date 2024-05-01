#include <raylib.h>
#include <iostream>
#include <vector>
#include "Player.h"
#include "CircleObstacle.h"
#include "StaticRectangleObstacle.h"
#include "CollisionManager.h"


int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Raylib basic window");
    ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    Player p = Player(200, 200);
    CircleObstacle c = CircleObstacle(300, 300, 50);
    StaticRectangleObstacle s = StaticRectangleObstacle(600,600, 50, 30);

    CollisionManager z = CollisionManager();
    std::vector<Obstacle*> v;
    v.push_back(&c);
    v.push_back(&s);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        c.Draw();
        s.Draw();
        p.HandleMovement();
        DrawCircle(600, 600, 5, RED);

        if (z.CheckCollisions(&p, v))
        {
            p.SetColor(RED);
        }

        else
        {
            p.SetColor(WHITE);
        }
        p.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

// to do, demonstrate collition of a rotatting rectangle. (diffoicult) chocie bweteen point triangle, point poly, circle rec
// do this with point poly
// 
// chidlren of obsatcle like rotationg square, large tower roattor, bullet, etc
//game class
//dash ability
//make hitbox accurate
//make dynamic polygon obsatcle
