#pragma once
#include "Renderer.h"

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
};