#include <raylib.h>
#include <iostream>
#include <vector>
#include "Player.h"
#include "CircleObstacle.h"
#include "StaticRectangleObstacle.h"
#include "DynamicShapeObstacle.h"
#include "CollisionManager.h"


void rotate(Vector2& v, Vector2 c, float angle)
{
    float tc = cosf(angle);
    float ts = sinf(angle);
    float x_rotated =       ((v.x - c.x) * tc) - ((c.y - v.y) * ts) + c.x;
    float y_rotated = -c.y + ((c.y - v.y) * tc) + ((v.x - c.x) * ts);

    //float x_rotated = ((v.x - c.x) * cos(angle)) - ((c.y - v.y) * sin(angle));
    //float y_rotated = ((c.y - v.y) * cos(angle)) - ((v.x - c.x) * sin(angle));

    v.x = x_rotated;
    v.y = -y_rotated;
}


int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Raylib basic window");
    //ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    std::vector<Vector2> v5;

    v5.push_back({700,700});
    v5.push_back({ 700,900 });
    v5.push_back({ 900,900 });
    v5.push_back({ 1000,900 });
    v5.push_back({ 900,700 });
    v5.push_back({ 700,700 });
    

    Player p = Player(200, 200);

    CircleObstacle c = CircleObstacle(300, 300, 50);
    StaticRectangleObstacle s = StaticRectangleObstacle(600,600, 50, 30);
    DynamicShapeObstacle d = DynamicShapeObstacle(800, 800, {800, 800}, v5, 0.1f, 0.01f);

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
        DrawCircle(600, 600, 5, RED);
     
        
        
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
//make dynamic polygon obsatcle
//ADD MORE COMMENTS
//const mystery
// include organize consult
