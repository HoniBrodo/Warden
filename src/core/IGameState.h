#pragma once

#include "Renderer.h"  

class IGameState {
public:
    virtual ~IGameState() = default;

    // Forces each game state to handle its own input
    virtual void HandleInput() = 0;

    // Called every frame to update game logic
    virtual void Update(float dt) = 0;

    // Called every frame to render
    virtual void Render(Renderer& render) = 0;
};
