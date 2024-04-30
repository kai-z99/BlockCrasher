#include <raylib.h>
#include "Player.h"

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Raylib basic window");
    ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    Player p = Player(200, 200);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        p.Draw();
        p.HandleMovement();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

//tester
//another tester
