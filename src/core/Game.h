#pragma once
#include "../level/MainMenu.h"
#include "Renderer.h"
#include "raylib.h"
#include "../ui/UIButton.h"
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

    int screenWidth = 1920;
    int screenHeight = 1080;
};