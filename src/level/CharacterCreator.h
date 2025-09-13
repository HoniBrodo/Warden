#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "../Core/StateManager.h"
#include "raylib.h" 

class CharacterCreator {
public:
    CharacterCreator(StateManager& sm) : stateManager(sm) {}

private:
    StateManager& stateManager;

    void InitMenuButtons(Renderer& renderRef);
};    