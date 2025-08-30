#include "Game.h"
#include "raylib.h"
#include "Renderer.h"

Game::Game() : state(GameState::DEBUG_WINDOW){}

Game::~Game() {}

void Game::Init()
{
	InitWindow(1920, 1080, "Warden");
	SetTargetFPS(120);
}

void Game::Run()
{
    while (!WindowShouldClose()) {

        if (state == GameState::DEBUG_WINDOW)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            render.DrawTextCentred("Hello from Warden", render.TextRow(0), render.fontSize, DARKGREEN);
            EndDrawing();
        }

        if (state == GameState::MAIN_MENU)
        {
            //implement logic 
        }
    }
    CloseWindow();
}

void Game::ChangeState(GameState NewState)
{
    state = NewState;
}
