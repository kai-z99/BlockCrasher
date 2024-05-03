#include <raylib.h>
#include <iostream>
#include <vector>
#include "Player.h"
#include "CircleObstacle.h"
#include "RectangleObstacle.h"
#include "DynamicShapeObstacle.h"
#include "CollisionManager.h"


int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Raylib basic window");
    ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    std::vector<Vector2> v5;

    v5.push_back({700,700});
    v5.push_back({ 700,900 });
    v5.push_back({ 900,1000 });
    v5.push_back({ 1000,900 });
    v5.push_back({ 900,700 });
    v5.push_back({ 700,700 });
    

    Player p = Player(200, 200);

    CircleObstacle c = CircleObstacle(300, 300, 50, {0,1});
    RectangleObstacle s = RectangleObstacle(600, 600, 50, 30, {1,1});
    DynamicShapeObstacle d = DynamicShapeObstacle(800, 800, { 200, 700 }, v5, 0.01f, 0.01f, {1,-1});

    CollisionManager z = CollisionManager();

    std::vector<Obstacle*> v;
    v.push_back(&c);
    v.push_back(&s);
    v.push_back(&d);
       
    int frameCount = 0;
    while (!WindowShouldClose()) {
        frameCount++;
        p.HandleMovement();
        d.Update(frameCount);
        c.Update(frameCount);
        s.Update(frameCount);

        if (z.CheckCollisions(&p, v))
        {
            p.SetColor(RED);
        }

        else
        {
            p.SetColor(WHITE);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        c.Draw();
        s.Draw();
        d.Draw();
        p.Draw();
       
        EndDrawing();
    }
    CloseWindow();
    return 0;
}


// fix dynam,ic obstacle hitbox (4 pints on player)
// chidlren of obsatcle like rotationg square, large tower roattor, bullet, etc
// //make shapes move. (Make update a pure virtual in Obstacle.h, then add movement to the children.)
//game class
//dash ability
//ADD MORE COMMENTS
//const mystery
// include organize consult
