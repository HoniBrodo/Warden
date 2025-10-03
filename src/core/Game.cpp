#include "Game.h"
#include "raylib.h"
#include "Renderer.h"

Game::Game() {}

Game::~Game() {}

void Game::Init()
{
    render.SetScreenSize(screenWidth, screenHeight);
    render.SetGrid(24, 16);
	SetTargetFPS(120);
}


void Game::Run()
{
    float lastTime = GetTime();  // seconds since start
    while (!WindowShouldClose() && gameRunning) {

        float currentTime = GetTime();
        float dt = currentTime - lastTime;
        lastTime = currentTime;

        switch (stateManager.GetState()) 
        {
        case StateManager::GameState::DEBUG_WINDOW:
            debugLevel.Run(render);
            break;

        case StateManager::GameState::MAIN_MENU:
            mMenu.Run(render, gameRunning);
            break;

        case StateManager::GameState::CHARATER_CREATOR:
            cCreator.HandleInput();
            cCreator.Update(dt);
            // check prevents one-frame flash by skipping Draw() if the state switched this frame
            // this feels like a patch rather than a fix
            if (stateManager.GetState() == StateManager::GameState::CHARATER_CREATOR)
                cCreator.Draw(render);
            break;
        }
    }
    CloseWindow();
}

