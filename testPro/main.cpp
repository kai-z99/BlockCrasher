#include <raylib.h>
#include <iostream>
#include <vector>
#include "Player.h"
#include "CircleObstacle.h"
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
    CollisionManager z = CollisionManager();
    std::vector<Obstacle*> v;
    v.push_back(&c);
    
    float angle = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        c.Draw();
        p.Draw();
        p.HandleMovement();
        if (z.CheckCollisions(&p, v))
        {
            std::cout << "Collision\n";
        }
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

// to do, demonstrate collition of a rotatting rectangle. (diffoicult) chocie bweteen point triangle, point poly, circle rec
// 
// then make obstable class
// chidlren of obsatcle like rotationg square, large tower roattor, bullet, etc
//game class
//dash ability
//make hitbox accurate
