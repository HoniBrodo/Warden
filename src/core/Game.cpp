#include "Game.h"
#include "raylib.h"

Game::Game() {}

Game::~Game() {}

void Game::Init()
{
	InitWindow(800, 600, "Warden");
	SetTargetFPS(120);
}

void Game::Run()
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello from Warden!", 320, 280, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
}
