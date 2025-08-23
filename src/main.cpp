#include "raylib.h"

int main() {
    InitWindow(800, 600, "Warden");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Warden!", 320, 280, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
