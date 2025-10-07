#include <string>
#include "CharacterCreator.h"
#include "../core/Renderer.h"
#include "../core/StateManager.h"
#include "../assets/TextureManager.h"
#include "../player/Player.h"
#include <iostream>

/*
--------------------------------
plan for stats and saves screen: 
--------------------------------

- Add classs modifiers to class select screen, call a fucntion that will generate class-unique stat and save modifiers as we cycle through the classes.
- Once we get to the stats screen, we want to be able to allocate a set amount of points to each stat and save.

Stats
------
- We will start with 36 (+ class modifier) for each. The player can click a plus or minus button, with a 'points available' tally on the screen.
Saves
-----
- We will start with 21 (+ class modifier) for each. The player can click a plus or minus button, with a 'points available' tally on the screen.
*/

CharacterCreator::CharacterCreator(StateManager& sm, TextureManager& tm, Renderer& render) : stateManager(sm), textureManager(tm), render(render) 
{
    textureManager.LoadTextureFromFile("Marine", "images/player/SFCP_1_01.png");
    textureManager.LoadTextureFromFile("Scientist", "images/player/SFCP_1_38.png");
    textureManager.LoadTextureFromFile("Android", "images/player/SFCP_1_59.png");
    textureManager.LoadTextureFromFile("Teamster", "images/player/SFCP_1_27.png");

    SelectClassAlignmentRect01 = { { render.GridX(13), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    SelectClassAlignmentRect02 = { { render.GridX(1), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    SelectClassAlignmentRect03 = { { render.GridX(4), render.GridY(4), render.GridX(8), render.GridY(9) }, false };
    SelectClassAlignmentRect04 = { { render.GridX(12), render.GridY(4), render.GridX(8), render.GridY(9) }, false };
    LoadoutSelectAlignmentRect01 = { { render.GridX(1), render.GridY(4), render.GridX(11), render.GridY(11) }, false };
    LoadoutSelectAlignmentRect02 = { { render.GridX(12), render.GridY(4), render.GridX(11), render.GridY(11) }, false };
}

void CharacterCreator::HandleInput()
{
    if (IsKeyDown(KEY_G))
    {
        pendingDebugGrid = true;
    }
    else
        pendingDebugGrid = false;

    // MainMenu button logic
    if (mainMenuButton.IsClicked(render, false)) {
        pendingMainMenu = true;
        pendingCharacterSelect = false;
        pendingLoadoutSelect = false;
    }

    mainMenuButtonColor = mainMenuButton.IsHovered(render, false) ? GRAY : LIGHTGRAY; 

    switch (GetCurrentPage())
    {
    case Page::CLASS_SELECT:

        // Previous button logic
        if (previousButton.IsClicked(render, false)) {
            PreviousCharacter();
        }

        if (previousButton.IsHovered(render, false)) {
            previousButtonColor = GRAY;
        }
        else previousButtonColor = LIGHTGRAY;

        // Next button logic
        if (nextButton.IsClicked(render, false)) {
            NextCharacter();
        }

        if (nextButton.IsHovered(render, false)) {
            nextButtonColor = GRAY;
        }
        else nextButtonColor = LIGHTGRAY;

        // SelectClass button logic
        if (selectClassButton.IsClicked(render, false)) {

            std::unique_ptr<BaseClass> chosenClass;

            switch (GetCurrentCharacter())
            {
            case CharacterSelect::Marine:
                chosenClass = std::make_unique<Marine>();
                break;
            case CharacterSelect::Scientist:
                chosenClass = std::make_unique<Scientist>();
                break;
            case CharacterSelect::Android:
                chosenClass = std::make_unique<Android>();
                break;
            case CharacterSelect::Teamster:
                chosenClass = std::make_unique<Teamster>();
                break;
            default:
                chosenClass = std::make_unique<Scientist>(); // fallback
            }

            // wrap into Player and pass to StateManager
            auto player = std::make_unique<Player>(std::move(chosenClass));
            stateManager.SetPlayer(std::move(player));

            currentPage = Page::LOADOUT_SELECT;

            break;
        }

        if (selectClassButton.IsHovered(render, false)) {
            selectClassButtonColor = GRAY;
        }
        else selectClassButtonColor = LIGHTGRAY;

        break;

    case Page::LOADOUT_SELECT:

        // loadout 01 button logic
        if (loadout01Button.IsClicked(render, true)) {
            currentPage = Page::SKILLS_SELECT;
        }

        if (loadout01Button.IsHovered(render, true)) {
            loadout01ButtonColor = GRAY;
        }
        else loadout01ButtonColor = LIGHTGRAY;

        // loadout 02 button logic
        if (loadout02Button.IsClicked(render, true)) {
            currentPage = Page::SKILLS_SELECT;
        }

        if (loadout02Button.IsHovered(render, true)) {
            loadout02ButtonColor = GRAY;
        }
        else loadout02ButtonColor = LIGHTGRAY;

        // loadout 03 button logic
        if (loadout03Button.IsClicked(render, true)) {
            currentPage = Page::SKILLS_SELECT;
        }

        if (loadout03Button.IsHovered(render, true)) {
            loadout03ButtonColor = GRAY;
        }
        else loadout03ButtonColor = LIGHTGRAY;

        // loadout 04 button logic
        if (loadout04Button.IsClicked(render, true)) {
            currentPage = Page::SKILLS_SELECT;
        }

        if (loadout04Button.IsHovered(render, true)) {
            loadout04ButtonColor = GRAY;
        }
        else loadout04ButtonColor = LIGHTGRAY;

        break;
    }
}

void CharacterCreator::Update(float dt)
{

    // Handle state transitions based on input
    if (pendingDebugGrid) {
        drawDebugGrid = true;
        pendingDebugGrid = false;
    }
    else drawDebugGrid = false;

    if (pendingMainMenu) {
        stateManager.SetState(StateManager::GameState::MAIN_MENU);
        shouldDraw = false;
        Reset();
        return;
    }
}

void CharacterCreator::Draw(Renderer& render)
{
    if (!shouldDraw)
    {
        shouldDraw = true;
        return;
    }

    BeginDrawing();
    ClearBackground(BLACK);

    InitButtons();

    // optional: draw the debug rectangle
    render.DrawDebugRect(SelectClassAlignmentRect01);
    render.DrawDebugRect(SelectClassAlignmentRect02);
    render.DrawDebugRect(SelectClassAlignmentRect03);
    render.DrawDebugRect(SelectClassAlignmentRect04);

    mainMenuButton.Draw(render, mainMenuButtonColor);

    if (drawDebugGrid)
    {
        render.DrawGrid(true);
    }

    switch (GetCurrentPage())
    {

    case Page::CLASS_SELECT:

        render.DrawTextBlock
        (
            "Choose Your Class",
            render.TextScreenCenterX(800),
            render.GridY(1),
            800,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        switch (GetCurrentCharacter())
        {
        case CharacterSelect::Marine:

            render.DrawLoadedTexture("Marine", { static_cast<float>(render.AlignCenterXInRect(SelectClassAlignmentRect03, textureManager.GetTexture("Marine").width * 0.5)), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

            render.DrawTextBlock
            (
                "Marine",
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 300),
                render.GridY(4),
                300,
                TextAlign::Center,
                TextSize::SmallerTitle
            );

            render.DrawTextBlock
            (
                marineInfo,
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 600),
                render.GridY(7),
                600,
                TextAlign::Center,
                TextSize::Dialogue
            );
            break;

        case CharacterSelect::Scientist:

            render.DrawLoadedTexture("Scientist", { static_cast<float>(render.AlignCenterXInRect(SelectClassAlignmentRect03, textureManager.GetTexture("Scientist").width * 0.5)), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

            render.DrawTextBlock
            (
                "Scientist",
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 400),
                render.GridY(4),
                400,
                TextAlign::Center,
                TextSize::SmallerTitle
            );

            render.DrawTextBlock
            (
                scientistInfo,
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 600),
                render.GridY(7),
                600,
                TextAlign::Center,
                TextSize::Dialogue
            );
            break;

        case CharacterSelect::Teamster:

            render.DrawLoadedTexture("Teamster", { static_cast<float>(render.AlignCenterXInRect(SelectClassAlignmentRect03, textureManager.GetTexture("Teamster").width * 0.5)), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

            render.DrawTextBlock
            (
                "Teamster",
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 400),
                render.GridY(4),
                400,
                TextAlign::Center,
                TextSize::SmallerTitle
            );

            render.DrawTextBlock
            (
                teamsterInfo,
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 600),
                render.GridY(7),
                600,
                TextAlign::Center,
                TextSize::Dialogue
            );
            break;

        case CharacterSelect::Android:

            render.DrawLoadedTexture("Android", { static_cast<float>(render.AlignCenterXInRect(SelectClassAlignmentRect03, textureManager.GetTexture("Android").width * 0.5)), render.GridX(3) + 5 }, 0.0f, 0.5f, WHITE);

            render.DrawTextBlock
            (
                "Android",
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 400),
                render.GridY(4),
                400,
                TextAlign::Center,
                TextSize::SmallerTitle
            );

            render.DrawTextBlock
            (
                androidInfo,
                render.AlignCenterXInRect(SelectClassAlignmentRect04, 600),
                render.GridY(7),
                600,
                TextAlign::Center,
                TextSize::Dialogue
            );
            break;
        }

        previousButton.Draw(render, previousButtonColor);
        nextButton.Draw(render, nextButtonColor);
        selectClassButton.Draw(render, selectClassButtonColor);

        break; 

    case Page::LOADOUT_SELECT:

    {
        render.DrawDebugRect(LoadoutSelectAlignmentRect01);
        render.DrawDebugRect(LoadoutSelectAlignmentRect02);

        // Get the player's chosen class name
        std::string className = stateManager.GetPlayer()->GetClass().GetName();

        // Build the display string
        std::string equipmentScreenText = "Choose " + className + " Starting Equipment";

        // Draw it
        render.DrawTextBlock
        (
            equipmentScreenText,
            render.TextScreenCenterX(1500),
            render.GridY(1),
            1500,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        std::vector<std::string> loadout01Items = stateManager.GetPlayer()->GetClass().GetLoadout(1);
        std::vector<std::string> loadout02Items = stateManager.GetPlayer()->GetClass().GetLoadout(2);
        std::vector<std::string> loadout03Items = stateManager.GetPlayer()->GetClass().GetLoadout(3);
        std::vector<std::string> loadout04Items = stateManager.GetPlayer()->GetClass().GetLoadout(4);

        loadout01Button.DrawFreeRec(render, loadout01ButtonColor);
        loadout02Button.DrawFreeRec(render, loadout02ButtonColor);
        loadout03Button.DrawFreeRec(render, loadout03ButtonColor);
        loadout04Button.DrawFreeRec(render, loadout04ButtonColor);

        render.DrawTextListInRect(loadout01Items, loadout01Button.GetRect(), TextAlign::Center, TextSize::Dialogue, 120);
        render.DrawTextListInRect(loadout02Items, loadout02Button.GetRect(), TextAlign::Center, TextSize::Dialogue, 120);
        render.DrawTextListInRect(loadout03Items, loadout03Button.GetRect(), TextAlign::Center, TextSize::Dialogue, 120);
        render.DrawTextListInRect(loadout04Items, loadout04Button.GetRect(), TextAlign::Center, TextSize::Dialogue, 120);

        break;
    }

    case Page::SKILLS_SELECT:

    render.DrawTextBlock
    (
    "Skills and Stats",
    render.TextScreenCenterX(1500),
    render.GridY(1),
    1500,
    TextAlign::Center,
    TextSize::SmallerTitle
    );

       break;
    }

    EndDrawing();
}

void CharacterCreator::InitButtons()
{

    DebugRect alignmentRect01 = { { render.GridX(13), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    DebugRect alignmentRect02 = { { render.GridX(1), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    DebugRect alignmentRect03 = { { render.GridX(1), render.GridY(4), render.GridX(11), render.GridY(11) }, false };
    DebugRect alignmentRect04 = { { render.GridX(12), render.GridY(4), render.GridX(11), render.GridY(11) }, false };

    render.DrawDebugRect(alignmentRect01);
    render.DrawDebugRect(alignmentRect02);
    render.DrawDebugRect(alignmentRect03);
    render.DrawDebugRect(alignmentRect04);

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
        render.GridX(21) + 39,
        render.GridY(0) + 1,
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

    loadout01Button = UIButton(
        "Loadout 01",
        render.AlignCenterXInRect(alignmentRect03, render.GridX(9)),
        render.GridY(4),
        render.GridX(9), render.GridY(5),
        TextAlign::Center,
        TextSize::Button01
    );

    loadout02Button = UIButton(
        "Loadout 02",
        render.AlignCenterXInRect(alignmentRect04, render.GridX(9)),
        render.GridY(4),
        render.GridX(9), render.GridY(5),
        TextAlign::Center,
        TextSize::Button01
    );

    loadout03Button = UIButton(
        "Loadout 03",
        render.AlignCenterXInRect(alignmentRect03, render.GridX(9)),
        render.GridY(10),
        render.GridX(9), render.GridY(5),
        TextAlign::Center,
        TextSize::Button01
    );

    loadout04Button = UIButton(
        "Loadout 04",
        render.AlignCenterXInRect(alignmentRect04, render.GridX(9)),
        render.GridY(10),
        render.GridX(9), render.GridY(5),
        TextAlign::Center,
        TextSize::Button01
    );
 

}

// could these helpers be in the .h file?
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

void CharacterCreator::Reset()
{
    currentCharacter = CharacterSelect::Marine;
    currentPage = Page::CLASS_SELECT;

    pendingCharacterSelect = false;
    pendingLoadoutSelect = false;
    pendingMainMenu = false;
    pendingDebugGrid = false;

    characterSelected = false;
    loadoutSelected = false;
    drawDebugGrid = false;

    // Reset button colours too
    nextButtonColor = LIGHTGRAY;
    previousButtonColor = LIGHTGRAY;
    mainMenuButtonColor = LIGHTGRAY;
    selectClassButtonColor = LIGHTGRAY;
    loadout01ButtonColor = LIGHTGRAY;
    loadout02ButtonColor = LIGHTGRAY;
    loadout03ButtonColor = LIGHTGRAY;
    loadout04ButtonColor = LIGHTGRAY;

       
}

