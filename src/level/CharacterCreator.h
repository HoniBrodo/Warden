#pragma once
#include <string>
#include "../ui/UIButton.h"
#include "../player/Marine.h"
#include "../player/Scientist.h"
#include "../player/Teamster.h"
#include "../player/Android.h"
#include "raylib.h" 


class Renderer;
class StateManager;
class TextureManager;

enum class CharacterSelect {
    Marine = 0,
    Scientist,
    Teamster,
    Android,
    Count // not a real option, just to track how many
};

class CharacterCreator {
public:
    CharacterCreator(StateManager& sm, TextureManager& tm, Renderer& render) : stateManager(sm), textureManager(tm), render(render) {}

    void Run();
    void InitButtons();
    CharacterSelect GetCurrentCharacter() const { return currentCharacter; }
    Marine marine;
    Scientist scientist;
    Android android;
    Teamster teamster;

private:
    Renderer& render;
    StateManager& stateManager;
    TextureManager& textureManager;

    CharacterSelect currentCharacter = CharacterSelect::Marine;

    void NextCharacter();
    void PreviousCharacter();

    // buttons
    UIButton nextButton;
    Color nextButtonColor = LIGHTGRAY;
    UIButton previousButton;
    Color previousButtonColor = LIGHTGRAY;
    UIButton mainMenuButton;
    Color mainMenuButtonColor = LIGHTGRAY;
    UIButton selectClassButton;
    Color selectClassButtonColor = LIGHTGRAY;
};    