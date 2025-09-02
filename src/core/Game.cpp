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
            //render.DrawTextCentred("Hello from Warden", render.GridY(8), render.fontSize, DARKGREEN);
            render.DrawTextBlock("This is a test of the text block function, it will adjust dynamically to the size of the string", render.GridX(2), render.GridY(7));
            render.DrawTextBlock("Smaller string = smaller box", render.GridX(15), render.GridY(10));
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
