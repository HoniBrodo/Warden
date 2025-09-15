#pragma once
#include <string>
#include "../ui/UIButton.h"
#include "raylib.h" 

class Renderer;
class StateManager;
class TextureManager;

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