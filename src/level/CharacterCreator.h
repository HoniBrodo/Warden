#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "../Core/StateManager.h"
#include "../assets/TextureManager.h"
#include "raylib.h" 

class CharacterCreator {
public:
    CharacterCreator(StateManager& sm, TextureManager& tm) : stateManager(sm), textureManager(tm) {}

    void Run(Renderer& renderRef);
    void InitButtons(Renderer& renderRef);

private:
    StateManager& stateManager;
    TextureManager& textureManager;

    // buttons
    UIButton NextButton;
    Color NextButtonColor = LIGHTGRAY;
    UIButton PreviousButton;
    Color PreviousButtonColor = LIGHTGRAY;
    UIButton MainMenuButton;
    Color MainMenuButtonColor = LIGHTGRAY;
};    