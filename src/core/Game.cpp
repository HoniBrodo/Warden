#include "Game.h"
#include "raylib.h"
#include "Renderer.h"

Game::Game() : state(GameState::MAIN_MENU){}

Game::~Game() {}

void Game::Init()
{
	InitWindow(screenWidth, screenHeight, "Warden");
    render.SetScreenSize(screenWidth, screenHeight);
    render.SetGrid(24, 16);
	SetTargetFPS(120);
}

void Game::Run()
{
    while (!WindowShouldClose()) {

        if (state == GameState::DEBUG_WINDOW)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            if (IsKeyDown(KEY_G)) 
            {
                render.DrawGrid(true);
            }
            //render.DrawTextCentred("Hello from Warden", render.GridY(8), render.fontSize, DARKGREEN);
            render.DrawTextBlock("This is a test of the text block function, it will adjust dynamically to the size of the string. let's see what happens when we make it super super super super super super super super super long! ", render.GridX(2), render.GridY(4), 1000, TextAlign::Left);
            render.DrawTextBlock("I can adjust the size of the padding and the text will automatically wrap. NEAT!", render.GridX(15), render.GridY(10), 400, TextAlign::Left);
            EndDrawing();
        }

        if (state == GameState::MAIN_MENU)
        {
            BeginDrawing();
            ClearBackground(BLACK);
            if (IsKeyDown(KEY_G))
            {
                render.DrawGrid(true);
            }

            render.DrawTextBlock("WARDEN", render.GridX(15), render.GridY(9), 1000, TextAlign::Center);
           
            EndDrawing();
        }
    }
    CloseWindow();
}

void Game::ChangeState(GameState NewState)
{
    state = NewState;
}
