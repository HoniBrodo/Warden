#include <string>
#include "CharacterCreator.h"
#include "../core/Renderer.h"
#include "../Core/StateManager.h"
#include "../assets/TextureManager.h"

void CharacterCreator::Run()
{

    DebugRect alignmentRect01 = { { render.GridX(13), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    DebugRect alignmentRect02 = { { render.GridX(1), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    DebugRect alignmentRect03 = { { render.GridX(4), render.GridY(4), render.GridX(8), render.GridY(9) }, false };
    DebugRect alignmentRect04 = { { render.GridX(12), render.GridY(4), render.GridX(8), render.GridY(9) }, false };

    std::string marineInfo = marine.GetClassBio();
    std::string scientistInfo = scientist.GetClassBio();
    std::string androidInfo = android.GetClassBio();
    std::string teamsterInfo = teamster.GetClassBio();

    if (IsKeyDown(KEY_G))
    {
        render.DrawGrid(true);
    }

    BeginDrawing();
    ClearBackground(BLACK);
    InitButtons();

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
    textureManager.LoadTextureFromFile("Android", "images/player/SFCP_1_59.png"); 
    textureManager.LoadTextureFromFile("Teamster", "images/player/SFCP_1_27.png");

    // optional: draw the debug rectangle
    render.DrawDebugRect(alignmentRect01);
    render.DrawDebugRect(alignmentRect02);
    render.DrawDebugRect(alignmentRect03);
    render.DrawDebugRect(alignmentRect04);

    switch (GetCurrentCharacter())
    {
    case CharacterSelect::Marine:

        render.DrawLoadedTexture("Marine", { static_cast<float>(render.AlignCenterXInRect(alignmentRect03, textureManager.GetTexture("Marine").width * 0.5)), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

        render.DrawTextBlock
        (
            "Marine",
            render.AlignCenterXInRect(alignmentRect04, 300),
            render.GridY(4),
            300,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawTextBlock
        (
            marineInfo,
            render.AlignCenterXInRect(alignmentRect04, 600),
            render.GridY(7),
            600,
            TextAlign::Center,
            TextSize::Dialogue
        );
        break;

    case CharacterSelect::Scientist:

        render.DrawLoadedTexture("Scientist", { static_cast<float>(render.AlignCenterXInRect(alignmentRect03, textureManager.GetTexture("Scientist").width * 0.5)), render.GridX(3) + 5}, 0.0f, 0.5f, WHITE);

        render.DrawTextBlock
        (
            "Scientist",
            render.AlignCenterXInRect(alignmentRect04, 400),
            render.GridY(4),
            400,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawTextBlock
        (
            scientistInfo,
            render.AlignCenterXInRect(alignmentRect04, 600),
            render.GridY(7),
            600,
            TextAlign::Center,
            TextSize::Dialogue
        );
        break;

    case CharacterSelect::Teamster:

        render.DrawLoadedTexture("Teamster", { static_cast<float>(render.AlignCenterXInRect(alignmentRect03, textureManager.GetTexture("Teamster").width * 0.5)), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

        render.DrawTextBlock
        (
            "Teamster",
            render.AlignCenterXInRect(alignmentRect04, 400),
            render.GridY(4),
            400,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawTextBlock
        (
            teamsterInfo,
            render.AlignCenterXInRect(alignmentRect04, 600),
            render.GridY(7),
            600,
            TextAlign::Center,
            TextSize::Dialogue
        );
        break;

    case CharacterSelect::Android:

        render.DrawLoadedTexture("Android", { static_cast<float>(render.AlignCenterXInRect(alignmentRect03, textureManager.GetTexture("Android").width * 0.5)), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

        render.DrawTextBlock
        (
            "Android",
            render.AlignCenterXInRect(alignmentRect04, 400),
            render.GridY(4),
            400,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawTextBlock
        (
            androidInfo,
            render.AlignCenterXInRect(alignmentRect04, 600),
            render.GridY(7),
            600,
            TextAlign::Center,
            TextSize::Dialogue
        );
        break;
    }



    previousButton.Draw(render, previousButtonColor);
    nextButton.Draw(render, nextButtonColor);
    mainMenuButton.Draw(render, mainMenuButtonColor);
    selectClassButton.Draw(render, selectClassButtonColor);

    // Previous button logic
    if (previousButton.IsClicked(render)) {
        PreviousCharacter();
    }

    if (previousButton.IsHovered(render)) {
        previousButtonColor = GRAY;
    }
    else previousButtonColor = LIGHTGRAY;

    // Next button logic
    if (nextButton.IsClicked(render)) {
        NextCharacter();
    }

    if (nextButton.IsHovered(render)) {
        nextButtonColor = GRAY;
    }
    else nextButtonColor = LIGHTGRAY;

    // MainMenu button logic
    if (mainMenuButton.IsClicked(render)) {
        stateManager.SetState(StateManager::GameState::MAIN_MENU);
    }

    if (mainMenuButton.IsHovered(render)) {
        mainMenuButtonColor = GRAY;
    }
    else mainMenuButtonColor = LIGHTGRAY;

    // SelectClass button logic
    if (selectClassButton.IsClicked(render)) {
        stateManager.SetState(StateManager::GameState::MAIN_MENU);
    }

    if (selectClassButton.IsHovered(render)) {
        selectClassButtonColor = GRAY;
    }
    else selectClassButtonColor = LIGHTGRAY;

    EndDrawing();
}

void CharacterCreator::InitButtons()
{

    DebugRect alignmentRect01 = { { render.GridX(13), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    DebugRect alignmentRect02 = { { render.GridX(1), render.GridY(4), render.GridX(10), render.GridY(11) }, true };

    previousButton = UIButton(
        "Previous",
        render.AlignCenterXInRect(alignmentRect02, 400),
        render.GridY(13),
        400, 120,                   
        TextAlign::Center,
        TextSize::Button01
    );

    nextButton = UIButton(
        "Next",
        render.AlignCenterXInRect(alignmentRect01, 400),
        render.GridY(13),
        400, 120,
        TextAlign::Center,
        TextSize::Button01
    );

    mainMenuButton = UIButton(
        "Main Menu",
        render.GridX(21) + 30,
        render.GridY(0) + 10,
        200, 120,
        TextAlign::Center,
        TextSize::Dialogue
    );

    selectClassButton = UIButton(
        "Select Class",
        render.TextScreenCenterX(500),
        render.GridY(13),
        500, 120,
        TextAlign::Center,
        TextSize::Button01
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

