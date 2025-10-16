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
all base stats start at 36
all base saves are 21

marine:

* combat gets 46
* body gets 31
* fear gets 41
* max wounds is 3

android:

* choose a stat for a -10 handicap (that stat receives 26)
* intellect gets 56
* fear gets 81
* max wounds is 3

scientist:

* intellect gets 46
* choose a stat to recieve +5 (that stat receives 41, unless it's intellct, which would get 51)
* sanity gets 51

teamster: 

* +5 to all stats (all stats recieve 41)
* +10 to all saves (all saves recieve 31)

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
                androidDecisionRequired = true;
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

    case Page::SKILLS_SELECT:
    {
        int strength = stateManager.GetPlayer()->GetClass().GetStrength();
        int speed = stateManager.GetPlayer()->GetClass().GetSpeed();
        int intellect = stateManager.GetPlayer()->GetClass().GetIntellect();
        int combat = stateManager.GetPlayer()->GetClass().GetCombat();

        int sanity = stateManager.GetPlayer()->GetClass().GetSanity();
        int fear = stateManager.GetPlayer()->GetClass().GetFear();
        int body = stateManager.GetPlayer()->GetClass().GetBody();

        // increment strength button logic

        if (androidDecisionRequired == false)
        {
            if (incrementStrengthButton.IsClicked(render, false)) {
                availableStatPoints--;
                stateManager.GetPlayer()->GetClass().IncreaseStrength(1);
            }

            if (incrementStrengthButton.IsHovered(render, false)) {
                incrementStrengthButtonColor = BLACK;
            }
            else incrementStrengthButtonColor = GRAY;

            // decrement strength button logic

            if (decrementStrengthButton.IsClicked(render, false)) {
                availableStatPoints++;
                stateManager.GetPlayer()->GetClass().DecreaseStrength(1);
            }

            if (decrementStrengthButton.IsHovered(render, false)) {
                decrementStrengthButtonColor = BLACK;
            }
            else decrementStrengthButtonColor = GRAY;

            // increment speed button logic

            if (incrementSpeedButton.IsClicked(render, false)) {
                availableStatPoints--;
                stateManager.GetPlayer()->GetClass().IncreaseSpeed(1);
            }

            if (incrementSpeedButton.IsHovered(render, false)) {
                incrementSpeedButtonColor = BLACK;
            }
            else incrementSpeedButtonColor = GRAY;

            // decrement speed button logic

            if (decrementSpeedButton.IsClicked(render, false)) {
                availableStatPoints++;
                stateManager.GetPlayer()->GetClass().DecreaseSpeed(1);
            }

            if (decrementSpeedButton.IsHovered(render, false)) {
                decrementSpeedButtonColor = BLACK;
            }
            else decrementSpeedButtonColor = GRAY;

            // increment intellect button logic

            if (incrementIntellectButton.IsClicked(render, false)) {
                availableStatPoints--;
                stateManager.GetPlayer()->GetClass().IncreaseIntellect(1);
            }

            if (incrementIntellectButton.IsHovered(render, false)) {
                incrementIntellectButtonColor = BLACK;
            }
            else incrementIntellectButtonColor = GRAY;

            // decrement intellect button logic

            if (decrementIntellectButton.IsClicked(render, false)) {
                availableStatPoints++;
                stateManager.GetPlayer()->GetClass().DecreaseIntellect(1);
            }

            if (decrementIntellectButton.IsHovered(render, false)) {
                decrementIntellectButtonColor = BLACK;
            }
            else decrementIntellectButtonColor = GRAY;

            // increment combat button logic

            if (incrementCombatButton.IsClicked(render, false)) {
                availableStatPoints--;
                stateManager.GetPlayer()->GetClass().IncreaseCombat(1);
            }

            if (incrementCombatButton.IsHovered(render, false)) {
                incrementCombatButtonColor = BLACK;
            }
            else incrementCombatButtonColor = GRAY;

            // decrement combat button logic

            if (decrementCombatButton.IsClicked(render, false)) {
                availableStatPoints++;
                stateManager.GetPlayer()->GetClass().DecreaseCombat(1);
            }

            if (decrementCombatButton.IsHovered(render, false)) {
                decrementCombatButtonColor = BLACK;
            }
            else decrementCombatButtonColor = GRAY;

            // increment sanity button logic

            if (incrementSanityButton.IsClicked(render, false)) {
                availableSavePoints--;
                stateManager.GetPlayer()->GetClass().IncreaseSanity(1);
            }

            if (incrementSanityButton.IsHovered(render, false)) {
                incrementSanityButtonColor = BLACK;
            }
            else incrementSanityButtonColor = GRAY;

            // decrement sanity button logic

            if (decrementSanityButton.IsClicked(render, false)) {
                availableSavePoints++;
                stateManager.GetPlayer()->GetClass().DecreaseSanity(1);
            }

            if (decrementSanityButton.IsHovered(render, false)) {
                decrementSanityButtonColor = BLACK;
            }
            else decrementSanityButtonColor = GRAY;

            // increment fear button logic

            if (incrementFearButton.IsClicked(render, false)) {
                availableSavePoints--;
                stateManager.GetPlayer()->GetClass().IncreaseFear(1);
            }

            if (incrementFearButton.IsHovered(render, false)) {
                incrementFearButtonColor = BLACK;
            }
            else incrementFearButtonColor = GRAY;

            // decrement fear button logic

            if (decrementFearButton.IsClicked(render, false)) {
                availableSavePoints++;
                stateManager.GetPlayer()->GetClass().DecreaseFear(1);
            }

            if (decrementFearButton.IsHovered(render, false)) {
                decrementFearButtonColor = BLACK;
            }
            else decrementFearButtonColor = GRAY;

            // increment body button logic

            if (incrementBodyButton.IsClicked(render, false)) {
                availableSavePoints--;
                stateManager.GetPlayer()->GetClass().IncreaseBody(1);
            }

            if (incrementBodyButton.IsHovered(render, false)) {
                incrementBodyButtonColor = BLACK;
            }
            else incrementBodyButtonColor = GRAY;

            // decrement body button logic

            if (decrementBodyButton.IsClicked(render, false)) {
                availableSavePoints++;
                stateManager.GetPlayer()->GetClass().DecreaseBody(1);
            }

            if (decrementBodyButton.IsHovered(render, false)) {
                decrementBodyButtonColor = BLACK;
            }
            else decrementBodyButtonColor = GRAY;

        }  

        if (androidDecisionRequired)
        {
            static bool isStrengthDecreased = false;
            static bool isSpeedDecreased = false;
            static bool isIntellectDecreased = false;
            static bool isCombatDecreased = false;

            // android handicap strength button logic

            if (androidHandicapStrengthButton.IsHovered(render, false)) {
                androidHandicapStrengthButtonColor = BLACK;
                if (!isStrengthDecreased)
                {
                    stateManager.GetPlayer()->GetClass().DecreaseStrength(10);
                    isStrengthDecreased = true;
                }
            }
            else
            {
                androidHandicapStrengthButtonColor = GRAY;
                if (isStrengthDecreased)
                {
                    stateManager.GetPlayer()->GetClass().IncreaseStrength(10);
                    isStrengthDecreased = false;
                }
            }

            if (androidHandicapStrengthButton.IsClicked(render, false)) {
                androidDecisionRequired = false;
            }

            // android handicap speed button logic

            if (androidHandicapSpeedButton.IsHovered(render, false)) {
                androidHandicapSpeedButtonColor = BLACK;
                if (!isSpeedDecreased)
                {
                    stateManager.GetPlayer()->GetClass().DecreaseSpeed(10);
                    isSpeedDecreased = true;
                }
            }
            else
            {
                androidHandicapSpeedButtonColor = GRAY;
                if (isSpeedDecreased)
                {
                    stateManager.GetPlayer()->GetClass().IncreaseSpeed(10);
                    isSpeedDecreased = false;
                }
            }

            // android handicap intellect button logic

            if (androidHandicapIntellectButton.IsHovered(render, false)) {
                androidHandicapIntellectButtonColor = BLACK;
                if (!isIntellectDecreased)
                {
                    stateManager.GetPlayer()->GetClass().DecreaseIntellect(10);
                    isIntellectDecreased = true;
                }
            }
            else
            {
                androidHandicapIntellectButtonColor = GRAY;
                if (isIntellectDecreased)
                {
                    stateManager.GetPlayer()->GetClass().IncreaseIntellect(10);
                    isIntellectDecreased = false;
                }
            }

            // android handicap combat button logic

            if (androidHandicapCombatButton.IsHovered(render, false)) {
                androidHandicapCombatButtonColor = BLACK;
                if (!isCombatDecreased)
                {
                    stateManager.GetPlayer()->GetClass().DecreaseCombat(10);
                    isCombatDecreased = true;
                }
            }
            else
            {
                androidHandicapCombatButtonColor = GRAY;
                if (isCombatDecreased)
                {
                    stateManager.GetPlayer()->GetClass().IncreaseCombat(10);
                    isCombatDecreased = false;
                }
            }
        }

        
    }

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
        className = stateManager.GetPlayer()->GetClass().GetName();

        render.DrawTextBlock
        (
            "Choose " + className + " Starting Equipment",
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

    {
        int strength = stateManager.GetPlayer()->GetClass().GetStrength();
        int speed = stateManager.GetPlayer()->GetClass().GetSpeed();
        int intellect = stateManager.GetPlayer()->GetClass().GetIntellect();
        int combat = stateManager.GetPlayer()->GetClass().GetCombat();
        
        int sanity = stateManager.GetPlayer()->GetClass().GetSanity();
        int fear = stateManager.GetPlayer()->GetClass().GetFear();
        int body = stateManager.GetPlayer()->GetClass().GetBody();

        std::string classType = stateManager.GetPlayer()->GetClass().GetName();

        render.DrawTextBlock
        (
            className + " Stats and Saves",
            render.TextScreenCenterX(1200),
            render.GridY(1),
            1200,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawTextBlock
        (
            "Available stat points: " + std::to_string(availableStatPoints),
            render.AlignCenterXInRect(LoadoutSelectAlignmentRect01, 800),
            render.GridY(4),
            800,
            TextAlign::Center,
            TextSize::MenuSmall
        );

        render.DrawTextBlock
        (
            "Available save points: " + std::to_string(availableSavePoints),
            render.AlignCenterXInRect(LoadoutSelectAlignmentRect02, 800),
            render.GridY(4),
            800,
            TextAlign::Center,
            TextSize::MenuSmall
        );

        render.DrawRectangle(
            render.AlignCenterXInRect(LoadoutSelectAlignmentRect01, render.GridX(10)),
            render.GridY(6),
            render.GridX(10),
            render.GridY(9),
            LIGHTGRAY
        );

        render.DrawRectangle(
            render.AlignCenterXInRect(LoadoutSelectAlignmentRect02, render.GridX(10)),
            render.GridY(6),
            render.GridX(10),
            render.GridY(9),
            LIGHTGRAY
        );

        // draw stat types

        render.DrawTextBlockNoPadding
        (
            "Strength: " + std::to_string(stateManager.GetPlayer()->GetClass().GetStrength()),
            render.GridX(2),
            render.GridY(7)-10,
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Speed: " + std::to_string(speed),
            render.GridX(2),
            render.GridY(9)-10,
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Intellect: " + std::to_string(intellect),
            render.GridX(2),
            render.GridY(11)-10,
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Combat: " + std::to_string(combat),
            render.GridX(2),
            render.GridY(13)-10,
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        // draw save types

        render.DrawTextBlockNoPadding
        (
            "Sanity: " + std::to_string(sanity),
            render.GridX(13)-10,
            render.GridY(8)-10,
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Fear: " + std::to_string(fear),
            render.GridX(13),
            render.GridY(10)-10,
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Body: " + std::to_string(body),
            render.GridX(13),
            render.GridY(12)-10,
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        incrementStrengthButton.Draw(render, incrementStrengthButtonColor);
        incrementSpeedButton.Draw(render, incrementSpeedButtonColor);
        incrementIntellectButton.Draw(render, incrementIntellectButtonColor);
        incrementCombatButton.Draw(render, incrementCombatButtonColor);
        decrementStrengthButton.Draw(render, decrementStrengthButtonColor);
        decrementSpeedButton.Draw(render, decrementSpeedButtonColor);
        decrementIntellectButton.Draw(render, decrementIntellectButtonColor);
        decrementCombatButton.Draw(render, decrementCombatButtonColor);

        decrementSanityButton.Draw(render, decrementSanityButtonColor);
        decrementFearButton.Draw(render, decrementFearButtonColor);
        decrementBodyButton.Draw(render, decrementBodyButtonColor);
        incrementSanityButton.Draw(render, incrementSanityButtonColor);
        incrementFearButton.Draw(render, incrementFearButtonColor);
        incrementBodyButton.Draw(render, incrementBodyButtonColor);


        if (classType == "Android" && androidDecisionRequired == true)
        {
            render.DrawRectangleWithBorder(
                GetScreenWidth() / 2 - render.GridX(7),
                render.GridY(5),
                render.GridX(14),
                render.GridY(9),
                LIGHTGRAY,
                BLACK,
                render.GridX(1) / 8);

            render.DrawTextBlockNoPadding(
                "As an android, you must choose a stat to recieve a -10 point handicap",
                render.TextScreenCenterX(0) / 2,
                render.GridY(6),
                render.GridX(12),
                TextAlign::Center,
                TextSize::MenuSmall
            );

            render.DrawTextBlockNoPadding(
                std::to_string(strength),
                render.GridX(6) + 35,
                render.GridY(10),
                render.GridX(12),
                TextAlign::Left,
                TextSize::MainTitle
            );

            render.DrawTextBlockNoPadding(
                std::to_string(speed),
                render.GridX(9) + 35,
                render.GridY(10),
                render.GridX(12),
                TextAlign::Left,
                TextSize::MainTitle
            );

            render.DrawTextBlockNoPadding(
                std::to_string(intellect),
                render.GridX(12) + 35,
                render.GridY(10),
                render.GridX(12),
                TextAlign::Left,
                TextSize::MainTitle
            );

            render.DrawTextBlockNoPadding(
                std::to_string(combat),
                render.GridX(15) + 35,
                render.GridY(10),
                render.GridX(12),
                TextAlign::Left,
                TextSize::MainTitle
            );

            androidHandicapStrengthButton.Draw(render, androidHandicapStrengthButtonColor);
            androidHandicapSpeedButton.Draw(render, androidHandicapSpeedButtonColor);
            androidHandicapIntellectButton.Draw(render, androidHandicapIntellectButtonColor);
            androidHandicapCombatButton.Draw(render, androidHandicapCombatButtonColor);
        }

        break;
    }

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

    androidHandicapStrengthButton = UIButton(
        "Strength",
        render.GridX(6),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

    androidHandicapSpeedButton = UIButton(
        "Speed",
        render.GridX(9),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

    androidHandicapIntellectButton = UIButton(
        "Intellect",
        render.GridX(12),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

    androidHandicapCombatButton = UIButton(
        "Combat",
        render.GridX(15),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementStrengthButton = UIButton(
        "-",
        render.GridX(7),
        render.GridY(7),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementSpeedButton = UIButton(
        "-",
        render.GridX(7),
        render.GridY(9),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementIntellectButton = UIButton(
        "-",
        render.GridX(7),
        render.GridY(11),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementCombatButton = UIButton(
        "-",
        render.GridX(7),
        render.GridY(13),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementStrengthButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(7),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementSpeedButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(9),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementIntellectButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(11),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementCombatButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(13),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementSanityButton = UIButton(
        "-",
        render.GridX(18),
        render.GridY(8),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementFearButton = UIButton(
        "-",
        render.GridX(18),
        render.GridY(10),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementBodyButton = UIButton(
        "-",
        render.GridX(18),
        render.GridY(12),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementSanityButton = UIButton(
        "+",
        render.GridX(20),
        render.GridY(8),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementFearButton = UIButton(
        "+",
        render.GridX(20),
        render.GridY(10),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementBodyButton = UIButton(
        "+",
        render.GridX(20),
        render.GridY(12),
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

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

    pendingMainMenu = false;
    pendingDebugGrid = false;

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

