#include <string>
#include "CharacterCreator.h"
#include "../core/Renderer.h"
#include "../Core/StateManager.h"
#include "../assets/TextureManager.h"


void CharacterCreator::Run(Renderer& renderRef)
{
    Renderer render = renderRef;

    std::string marineInfo = "This is some placeholder text for the Marine class. The Marine is good at bla bla bla. They suffer from bla bla bla. Their base stats are bla bla bla";

    if (IsKeyDown(KEY_G))
    {
        render.DrawGrid(true);
    }

    BeginDrawing();
    ClearBackground(BLACK);
    InitButtons(render);

    render.DrawTextBlock
    (
        "Choose Your Class",
        render.TextScreenCenterX(800),
        render.GridY(1),
        800,
        TextAlign::Center,
        TextSize::SmallerTitle
    );

    textureManager.LoadTextureFromFile("Marine", "images/player/SFCP_1_01.png");
    render.DrawLoadedTexture("Marine", { render.GridX(4), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

    render.DrawTextBlock
    (
        marineInfo,
        render.GridX(13),
        render.GridY(8),
        600,
        TextAlign::Center,
        TextSize::Dialogue
    );

    render.DrawTextBlock
    (
        "Marine",
        render.GridX(15),
        render.GridY(4),
        300,
        TextAlign::Center,
        TextSize::SmallerTitle
    );

    PreviousButton.Draw(render, PreviousButtonColor);
    NextButton.Draw(render, NextButtonColor);
    MainMenuButton.Draw(render, MainMenuButtonColor);

    // previous button logic
    if (PreviousButton.IsClicked(render)) {
        
    }

    if (PreviousButton.IsHovered(render)) {
        PreviousButtonColor = GRAY;
    }
    else PreviousButtonColor = LIGHTGRAY;

    // Next button logic
    if (NextButton.IsClicked(render)) {

    }

    if (NextButton.IsHovered(render)) {
        NextButtonColor = GRAY;
    }
    else NextButtonColor = LIGHTGRAY;

    // MainMenu button logic
    if (MainMenuButton.IsClicked(render)) {
        stateManager.SetState(StateManager::GameState::MAIN_MENU);
    }

    if (MainMenuButton.IsHovered(render)) {
        MainMenuButtonColor = GRAY;
    }
    else MainMenuButtonColor = LIGHTGRAY;

    EndDrawing();
}

void CharacterCreator::InitButtons(Renderer& renderRef)
{
    Renderer render = renderRef;

    PreviousButton = UIButton(
        "Previous",
        render.TextScreenCenterX(400) - 450,
        render.GridY(13),
        400, 120,                   
        TextAlign::Center,
        TextSize::Button01
    );

    NextButton = UIButton(
        "Next",
        render.TextScreenCenterX(250) + 450,
        render.GridY(13),
        250, 120,
        TextAlign::Center,
        TextSize::Button01
    );

    MainMenuButton = UIButton(
        "Main Menu",
        render.GridX(20),
        render.GridY(1),
        200, 120,
        TextAlign::Center,
        TextSize::Dialogue
    );
}
