#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "../core/StateManager.h"
#include "raylib.h"

class DebugLevel {
public:
    DebugLevel(StateManager& sm);

    void InitButtons(Renderer& renderRef);
    void Run(Renderer& renderRef);

private:
    void DrawGrid(int filledCount, int startX, int startY); // now draws circular pips

    StateManager& stateManager;
    UIButton testButton01;
    Color testButton01Color;

    int filledSquares = 8;

    static constexpr int GRID_ROWS = 2;
    static constexpr int GRID_COLS = 4;
    static constexpr int MAX_FILLED = 8;
    static constexpr int MIN_FILLED = 0;
};
