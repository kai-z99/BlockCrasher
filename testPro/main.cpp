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
    v5.push_back({ 900,700 });
    v5.push_back({ 700,700 });
    




    Player p = Player(200, 200);
    CircleObstacle c = CircleObstacle(300, 300, 50);
    StaticRectangleObstacle s = StaticRectangleObstacle(600,600, 50, 30);
    DynamicShapeObstacle d = DynamicShapeObstacle(800, 800, {800, 800}, v5, 0.01f);

    CollisionManager z = CollisionManager();
    std::vector<Obstacle*> v;
    v.push_back(&c);
    v.push_back(&s);
    v.push_back(&d);
    
    std::vector<Vector2> v2 ;
    Vector2 voff;
    voff = {500,500};
    v2.push_back({ 0 + voff.x,0 + voff.y });
    v2.push_back({ 100 + voff.x,0 + voff.y });
    v2.push_back({ 200 + voff.x,200 + voff.y });
    v2.push_back({ 0 + voff.x,100 + voff.y } );
    v2.push_back({ 0 + voff.x,0 + voff.y });

    //rotate(v2[0], { 50,50 }, PI / 6.0f);
    //rotate(v2[1], { 50,50 }, PI / 6.0f);
    //rotate(v2[2], { 0,0 }, PI / 30.0f);
    //rotate(v2[3], { 50,50 }, PI / 6.0f);
       
    float rv = PI / 100.f;
    int frameCount = 0;
    while (!WindowShouldClose()) {
        frameCount++;
        BeginDrawing();
        ClearBackground(BLACK);
        c.Draw();
        s.Draw();
        p.HandleMovement();
        DrawCircle(600, 600, 5, RED);
        //rotate(v2[2], { 50,50 }, ((PI / 30.0f)));

        
        rv = (sin(frameCount*0.01)) / 10.0f;
        Vector2 vc = { 550,550 };

        rotate(v2[0], vc, rv);
        rotate(v2[1], vc, rv);
        rotate(v2[2], vc, rv);
        rotate(v2[3], vc, rv);
        rotate(v2[4], vc, rv);


        d.Draw();
        d.Update(frameCount);
        
        DrawLineStrip(&v2[0], 5, WHITE);
        DrawCircle(510, 510, 5, WHITE);
        if (CheckCollisionPointPoly({ 50,50 }, &v2[1], 4))
        {
            std::cout << "scc";
        }


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

// to do, demonstrate collition of a rotatting rectangle.
// do this with point poly
// 
// chidlren of obsatcle like rotationg square, large tower roattor, bullet, etc
//game class
//dash ability
//make dynamic polygon obsatcle
//ADD MORE COMMENTS
//const mystery
// include organize consult
