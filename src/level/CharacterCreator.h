#pragma once
#include <string>
#include "../ui/UIButton.h"
#include "raylib.h" 

class Renderer;
class StateManager;
class TextureManager;

enum class CharacterSelect {
    Marine = 0,
    Scientist,
    Count // not a real option, just to track how many
};

class CharacterCreator {
public:
    CharacterCreator(StateManager& sm, TextureManager& tm) : stateManager(sm), textureManager(tm) {}

    void Run(Renderer& renderRef);
    void InitButtons(Renderer& renderRef);
    CharacterSelect GetCurrentCharacter() const { return currentCharacter; }

private:
    StateManager& stateManager;
    TextureManager& textureManager;

    CharacterSelect currentCharacter = CharacterSelect::Scientist;

    void NextCharacter();
    void PreviousCharacter();

    // buttons
    UIButton NextButton;
    Color NextButtonColor = LIGHTGRAY;
    UIButton PreviousButton;
    Color PreviousButtonColor = LIGHTGRAY;
    UIButton MainMenuButton;
    Color MainMenuButtonColor = LIGHTGRAY;
};    