#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib Hello World");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Hello, World!", 50, 50, 24, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
