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
    InitMenuButtons();
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
            render.DrawTextBlock("This is a test of the text block function, it will adjust dynamically to the size of the string. let's see what happens when we make it super super super super super super super super super long! ", render.GridX(2), render.GridY(4), 1500, TextAlign::Left, TextSize::Dialogue);
            render.DrawTextBlock("I can adjust the size of the padding and the text will automatically wrap. NEAT!", render.GridX(15), render.GridY(10), 400, TextAlign::Left, TextSize::Dialogue);
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
            render.DrawTextBlock("WARDEN", render.TextScreenCenterX(700), render.GridY(3), 700, TextAlign::Center, TextSize::MainTitle);
            render.DrawTextBlock("Based on the Sci-fi Horror TTRPG 'Mothership' Written by Sean McCoy and Published by Tuesday Night Games", render.TextScreenCenterX(1000), render.GridY(7), 1000, TextAlign::Center, TextSize::Dialogue);
            startButton.Draw(render);
            exitButton.Draw(render);

            if (startButton.IsHovered())
                ChangeState(GameState::DEBUG_WINDOW);

            EndDrawing();
        }
    }
    CloseWindow();
}

void Game::ChangeState(GameState NewState)
{
    state = NewState;
}

void Game::InitMenuButtons()
{
    startButton = UIButton(
        "Start",
        render.TextScreenCenterX(300) - 250,
        render.GridY(11),
        300, 60,                   // width & height
        TextAlign::Center,
        TextSize::Button01
    );

    exitButton = UIButton(
        "Exit",
        render.TextScreenCenterX(300) + 250,
        render.GridY(11),
        300, 60,                   // width & height
        TextAlign::Center,
        TextSize::Button01
    );
}
