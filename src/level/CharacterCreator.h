#pragma once
#include <string>
#include "../ui/UIButton.h"
#include "../player/Marine.h"
#include "../player/Scientist.h"
#include "../player/Teamster.h"
#include "../player/Android.h"
#include "../core/IGameState.h"
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

class CharacterCreator : public IGameState {
public:
    CharacterCreator(StateManager& sm, TextureManager& tm, Renderer& render);

    void InitButtons();
    void Update(float dt) override;
    void Draw(Renderer& render) override;
    void HandleInput() override;
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

    void Reset();

    bool pendingDebugGrid = false;
    bool pendingCharacterSelect = false;
    bool pendingLoadoutSelect = false;
    bool pendingMainMenu = false;

    bool characterSelected{ false };
    bool loadoutSelected{ false }; 

    bool drawDebugGrid{ false };

    bool shouldDraw{ true }; 

    std::string marineInfo = marine.GetClassBio();
    std::string scientistInfo = scientist.GetClassBio();
    std::string androidInfo = android.GetClassBio();
    std::string teamsterInfo = teamster.GetClassBio();

    DebugRect SelectClassAlignmentRect01;
    DebugRect SelectClassAlignmentRect02;
    DebugRect SelectClassAlignmentRect03;
    DebugRect SelectClassAlignmentRect04;

    // buttons
    UIButton nextButton;
    Color nextButtonColor = LIGHTGRAY;
    UIButton previousButton;
    Color previousButtonColor = LIGHTGRAY;
    UIButton mainMenuButton;
    Color mainMenuButtonColor = LIGHTGRAY;
    UIButton selectClassButton;
    Color selectClassButtonColor = LIGHTGRAY;
    UIButton loadout01Button;
    Color loadout01ButtonColor = LIGHTGRAY;
    UIButton loadout02Button;
    Color loadout02ButtonColor = LIGHTGRAY;
    UIButton loadout03Button;
    Color loadout03ButtonColor = LIGHTGRAY;
    UIButton loadout04Button;
    Color loadout04ButtonColor = LIGHTGRAY;
};  