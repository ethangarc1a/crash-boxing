#include "raylib.h"
int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 450, "Crash-Boxing (Arcade)");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Crash-Boxing: Arcade (F1 toggles Crash Lab later)", 70, 200, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
