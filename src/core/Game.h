#pragma once
#include "../level/MainMenu.h"
#include "../level/CharacterCreator.h"
#include "../level/DebugLevel.h"
#include "../assets/TextureManager.h"
#include "../ui/UIButton.h"
#include "Renderer.h"
#include "raylib.h"
#include "StateManager.h"



class Game {
public:
    Game();
    ~Game();

    void Init();
    void Run();

private: 

    TextureManager textureManager;
    Renderer render{ textureManager, 24, 16, 1920, 1080 };
    StateManager stateManager;
    MainMenu mMenu{ stateManager };
    DebugLevel debugLevel{ stateManager }; 
    CharacterCreator cCreator{ stateManager, textureManager, render };


    int screenWidth = 1920;
    int screenHeight = 1080;

    bool gameRunning = true;
};