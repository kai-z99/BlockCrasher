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
    float angle = 0;
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

// to do, demonstrate collition of a rotatting rectangle. (diffoicult) chocie bweteen point triangle, point poly, circle rec
// then make obstable class
// chidlren of obsatcle like rotationg square, large tower roattor, bullet, etc
