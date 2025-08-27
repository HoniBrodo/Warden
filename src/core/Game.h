#pragma once
#include "Renderer.h"

enum class GameState
{
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
};