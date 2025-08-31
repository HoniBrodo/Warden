#include "Game.h"
#include "raylib.h"
#include "Renderer.h"

Game::Game() : state(GameState::DEBUG_WINDOW){}

Game::~Game() {}

void Game::Init()
{
	InitWindow(screenWidth, screenHeight, "Warden");
    render.SetScreenSize(screenWidth, screenHeight);
	SetTargetFPS(120);
}

void Game::Run()
{
    while (!WindowShouldClose()) {

        if (state == GameState::DEBUG_WINDOW)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            render.SetGrid(24, 16);
            if (IsKeyDown(KEY_G)) 
            {
                render.DrawGrid(true);
            }
            render.DrawTextCentred("Hello from Warden", render.GridY(8), render.fontSize, DARKGREEN);
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
