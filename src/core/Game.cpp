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
            //BeginDrawing();
            //ClearBackground(BLACK);
            //if (IsKeyDown(KEY_G)) 
            //{
            //    render.DrawGrid(true);
            //}
            //render.DrawTextBlock("This is a test of the text block function, it will adjust dynamically to the size of the string. let's see what happens when we make it super super super super super super super super super long! ", render.GridX(2), render.GridY(4), 1500, TextAlign::Left, TextSize::Dialogue);
            //render.DrawTextBlock("I can adjust the size of the padding and the text will automatically wrap. NEAT!", render.GridX(15), render.GridY(10), 400, TextAlign::Left, TextSize::Dialogue);
            //EndDrawing();
        }

        if (state == GameState::MAIN_MENU)
        {
            mMenu.Run();
        }
    }
    CloseWindow();
}

void Game::ChangeState(GameState NewState)
{
    state = NewState;
}

