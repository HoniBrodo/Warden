#include "Game.h"
#include "raylib.h"
#include "Renderer.h"

Game::Game() {}

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
        switch (stateManager.GetState()) 
        {
        case StateManager::GameState::DEBUG_WINDOW:
            debugLevel.Run(render);
            break;

        case StateManager::GameState::MAIN_MENU:
            mMenu.Run(render);
            break;
        }
    }
    CloseWindow();
}

