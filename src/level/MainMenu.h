#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "../Core/StateManager.h"
#include "raylib.h" 

class MainMenu {
public:
    MainMenu(StateManager& sm) : stateManager(sm) {}

    void InitMenuButtons(Renderer& renderRef);
    void Run(Renderer& renderRef);

private:

    StateManager& stateManager;
    UIButton startButton;
    UIButton exitButton;
    Color startButtonColor = BLUE;
    Color exitButtonColor = LIGHTGRAY;
};