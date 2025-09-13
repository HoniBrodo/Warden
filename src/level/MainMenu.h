#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "../Core/StateManager.h"
#include "raylib.h" 

class MainMenu {
public:
    MainMenu(StateManager& sm) : stateManager(sm) {}

    void InitButtons(Renderer& renderRef);
    void Run(Renderer& renderRef, bool& gameRunning);

private:

    StateManager& stateManager;
    UIButton startButton;
    UIButton exitButton;
    Color startButtonColor = LIGHTGRAY;
    Color exitButtonColor = LIGHTGRAY;

};