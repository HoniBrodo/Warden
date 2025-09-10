#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "../Core/StateManager.h"
#include "raylib.h" 

class DebugLevel {
public:
    DebugLevel(StateManager& sm) : stateManager(sm) {}
    
    void Run(Renderer& renderRef);

private:
    StateManager& stateManager;
};