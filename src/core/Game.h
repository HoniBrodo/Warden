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

    Renderer render;
    
    TextureManager textureManager;
    StateManager stateManager;
    MainMenu mMenu{ stateManager };
    DebugLevel debugLevel{ stateManager }; 
    CharacterCreator cCreator{ stateManager, textureManager };


    int screenWidth = 1920;
    int screenHeight = 1080;

    bool gameRunning = true;
};