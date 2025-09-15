#include "CharacterCreator.h"


void CharacterCreator::Run(Renderer& renderRef)
{
    Renderer render = renderRef;



    if (IsKeyDown(KEY_G))
    {
        render.DrawGrid(true);
    }

	BeginDrawing();
	ClearBackground(BLACK);
	InitButtons(render);

    textureManager.LoadTextureFromFile("Marine", "images/player/SFCP_1_01.png");

    Texture2D& MarineTex = textureManager.GetTexture("Marine");
    DrawTexture(MarineTex, 100, 100, WHITE);

    render.DrawTextBlock
    (
        "Character Creator",
        render.TextScreenCenterX(800),
        render.GridY(1),
        800,
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
