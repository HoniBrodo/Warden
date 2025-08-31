#pragma once
#include "Renderer.h"
#include "raylib.h"

enum class GameState
{
    DEBUG_WINDOW,
    MAIN_MENU,
    PLAYING,
    PAUSED,
    DIALOGUE,
    GAME_OVER
};

class Game {
public:
    Game();
    ~Game();

    void Init();
    void Run();

private: 

    void ChangeState(GameState newState);

    GameState state;
    Renderer render;

    int screenWidth = 1920;
    int screenHeight = 1080;
};