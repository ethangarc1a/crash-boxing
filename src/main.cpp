#include "raylib.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 450, "Crash-Boxing");
    SetTargetFPS(60);

    bool crashLab = false;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_F1)) crashLab = !crashLab;

        BeginDrawing();
        ClearBackground(crashLab ? Color{245,245,255,255} : RAYWHITE);

        DrawText(crashLab ? "Crash Lab ON (F1 to toggle)" : "Arcade Mode (F1 for Crash Lab)", 40, 20, 20, BLACK);
        DrawText("Use F1 to toggle; crash hooks come next.", 40, 70, 18, DARKGRAY);

        if (crashLab) {
            DrawRectangle(30, 110, 740, 220, Fade(LIGHTGRAY, 0.4f));
            DrawText("Crash Buttons (inactive until Crashpad):", 40, 120, 18, BLACK);
            DrawText("1 Null deref   2 Out-of-bounds   3 Divide-by-zero   4 Stack overflow", 40, 150, 18, BLACK);
            DrawText("These will be wired up after Crashpad is integrated.", 40, 180, 18, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
