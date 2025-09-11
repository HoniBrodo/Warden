#pragma once
#include "../level/MainMenu.h"
#include "Renderer.h"
#include "raylib.h"
#include "../ui/UIButton.h"
#include "../level/DebugLevel.h"
#include "StateManager.h"


class Game {
public:
    Game();
    ~Game();

    void Init();
    void Run();

private: 

    Renderer render;
    StateManager stateManager;
    MainMenu mMenu{ stateManager };
    DebugLevel debugLevel{ stateManager }; 

    int screenWidth = 1920;
    int screenHeight = 1080;

    bool gameRunning = true;
};