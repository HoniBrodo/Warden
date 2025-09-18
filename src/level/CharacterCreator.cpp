#include <string>
#include "CharacterCreator.h"
#include "../core/Renderer.h"
#include "../Core/StateManager.h"
#include "../assets/TextureManager.h"


void CharacterCreator::Run(Renderer& renderRef)
{
    Renderer render = renderRef;

    DebugRect alignmentRect01 = { { render.GridX(13), render.GridY(4), render.GridX(10), render.GridY(11) }, true };

    // these need to be moved into their respective derived child sub-classes 
    std::string marineInfo = marine.GetClassBio();
    std::string ScientistInfo = scientist.GetClassBio();

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
    textureManager.LoadTextureFromFile("Scientist", "images/player/SFCP_1_38.png");

    // optional: draw the debug rectangle
    render.DrawDebugRect(alignmentRect01);

    switch (GetCurrentCharacter())
    {
    case CharacterSelect::Marine:

        render.DrawLoadedTexture("Marine", { render.GridX(4), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

        render.DrawTextBlock
        (
            "Marine",
            render.AlignCenterXInRect(alignmentRect01, 300),
            render.GridY(4),
            300,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawTextBlock
        (
            marineInfo,
            render.AlignCenterXInRect(alignmentRect01, 600),
            render.GridY(8),
            600,
            TextAlign::Center,
            TextSize::Dialogue
        );
        break;

    case CharacterSelect::Scientist:

        render.DrawLoadedTexture("Scientist", { render.GridX(4), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

        render.DrawTextBlock
        (
            "Scientist",
            render.GridX(15),
            render.GridY(4),
            400,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawTextBlock
        (
            ScientistInfo,
            render.GridX(13),
            render.GridY(7),
            600,
            TextAlign::Center,
            TextSize::Dialogue
        );
        break;
    }



    PreviousButton.Draw(render, PreviousButtonColor);
    NextButton.Draw(render, NextButtonColor);
    MainMenuButton.Draw(render, MainMenuButtonColor);

    // Previous button logic
    if (PreviousButton.IsClicked(render)) {
        PreviousCharacter();
    }

    if (PreviousButton.IsHovered(render)) {
        PreviousButtonColor = GRAY;
    }
    else PreviousButtonColor = LIGHTGRAY;

    // Next button logic
    if (NextButton.IsClicked(render)) {
        NextCharacter();
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


void CharacterCreator::NextCharacter() {
    int current = static_cast<int>(currentCharacter);
    current = (current + 1) % static_cast<int>(CharacterSelect::Count);
    currentCharacter = static_cast<CharacterSelect>(current);
}

void CharacterCreator::PreviousCharacter() {
    int current = static_cast<int>(currentCharacter);
    current = (current - 1 + static_cast<int>(CharacterSelect::Count)) % static_cast<int>(CharacterSelect::Count);
    currentCharacter = static_cast<CharacterSelect>(current);
}

