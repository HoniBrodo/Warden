#include "Game.h"
#include "raylib.h"

Game::Game() : state(GameState::DEBUG_WINDOW){}

Game::~Game() {}

void Game::Init()
{
	InitWindow(800, 600, "Warden");
	SetTargetFPS(120);
}

void Game::Run()
{
    while (!WindowShouldClose()) {

        if (state == GameState::DEBUG_WINDOW)
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello from Warden!", 320, 280, 20, BLACK);
            EndDrawing();
        }
    }
    CloseWindow();
}

void Game::ChangeState(GameState NewState)
{
    state = NewState;
}
