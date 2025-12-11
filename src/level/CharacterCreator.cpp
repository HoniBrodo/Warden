#include <string>
#include "CharacterCreator.h"
#include "../core/Renderer.h"
#include "../core/StateManager.h"
#include "../assets/TextureManager.h"
#include "../player/Player.h"
#include "../player/SkillManager.h"
#include <iostream>

/*
-----
plan:
-----

- 

*/

CharacterCreator::CharacterCreator(StateManager& sm, TextureManager& tm, Renderer& render) : stateManager(sm), textureManager(tm), render(render),

// Skill initialisers
linguisticsNode(SkillLevel::TRAINED),
zoologyNode(SkillLevel::TRAINED),
botanyNode(SkillLevel::TRAINED),
geologyNode(SkillLevel::TRAINED),
industrialEquipmentNode(SkillLevel::TRAINED),
juryRiggingNode(SkillLevel::TRAINED),
chemistryNode(SkillLevel::TRAINED),
computersNode(SkillLevel::TRAINED),
zeroGNode(SkillLevel::TRAINED),
mathematicsNode(SkillLevel::TRAINED),
artNode(SkillLevel::TRAINED),
archeologyNode(SkillLevel::TRAINED),
theologyNode(SkillLevel::TRAINED),
militaryTrainingNode(SkillLevel::TRAINED),
rimwiseNode(SkillLevel::TRAINED),
athleticsNode(SkillLevel::TRAINED),

psychologyNode(SkillLevel::EXPERT),
pathologyNode(SkillLevel::EXPERT),
fieldMedicineNode(SkillLevel::EXPERT),
ecologyNode(SkillLevel::EXPERT),
asteroidMiningNode(SkillLevel::EXPERT),
mechanicalRepairNode(SkillLevel::EXPERT),
explosivesNode(SkillLevel::EXPERT),
pharmacologyNode(SkillLevel::EXPERT),
hackingNode(SkillLevel::EXPERT),
pilotingNode(SkillLevel::EXPERT),
physicsNode(SkillLevel::EXPERT),
mysticismNode(SkillLevel::EXPERT),
wildernessSurvivalNode(SkillLevel::EXPERT),
fireArmsNode(SkillLevel::EXPERT),
handToHandCombatNode(SkillLevel::EXPERT),

sophontologyNode(SkillLevel::MASTER),
exobiologyNode(SkillLevel::MASTER),
surgeryNode(SkillLevel::MASTER),
planetologyNode(SkillLevel::MASTER),
roboticsNode(SkillLevel::MASTER),
engineeringNode(SkillLevel::MASTER),
cyberneticsNode(SkillLevel::MASTER),
artificialIntelligenceNode(SkillLevel::MASTER),
hyperspaceNode(SkillLevel::MASTER),
xenoesotericismNode(SkillLevel::MASTER),
commandNode(SkillLevel::MASTER)

{
    // add nodes to allNodes vector
    allNodes.push_back(&linguisticsNode);
    allNodes.push_back(&zoologyNode);
    allNodes.push_back(&botanyNode);
    allNodes.push_back(&geologyNode);
    allNodes.push_back(&industrialEquipmentNode);
    allNodes.push_back(&juryRiggingNode);
    allNodes.push_back(&chemistryNode);
    allNodes.push_back(&computersNode);
    allNodes.push_back(&zeroGNode);
    allNodes.push_back(&mathematicsNode);
    allNodes.push_back(&artNode);
    allNodes.push_back(&archeologyNode);
    allNodes.push_back(&theologyNode);
    allNodes.push_back(&militaryTrainingNode);
    allNodes.push_back(&rimwiseNode);
    allNodes.push_back(&athleticsNode);

    allNodes.push_back(&psychologyNode);
    allNodes.push_back(&pathologyNode);
    allNodes.push_back(&fieldMedicineNode);
    allNodes.push_back(&ecologyNode);
    allNodes.push_back(&asteroidMiningNode);
    allNodes.push_back(&mechanicalRepairNode);
    allNodes.push_back(&explosivesNode);
    allNodes.push_back(&pharmacologyNode);
    allNodes.push_back(&hackingNode);
    allNodes.push_back(&pilotingNode);
    allNodes.push_back(&physicsNode);
    allNodes.push_back(&mysticismNode);
    allNodes.push_back(&wildernessSurvivalNode);
    allNodes.push_back(&fireArmsNode);
    allNodes.push_back(&handToHandCombatNode);

    allNodes.push_back(&sophontologyNode);
    allNodes.push_back(&exobiologyNode);
    allNodes.push_back(&surgeryNode);
    allNodes.push_back(&planetologyNode);
    allNodes.push_back(&roboticsNode);
    allNodes.push_back(&engineeringNode);
    allNodes.push_back(&cyberneticsNode);
    allNodes.push_back(&artificialIntelligenceNode);
    allNodes.push_back(&hyperspaceNode);
    allNodes.push_back(&xenoesotericismNode);
    allNodes.push_back(&commandNode);


    for (auto n : allNodes)
    {
        if (n->skillLevel == SkillLevel::EXPERT || n->skillLevel == SkillLevel::MASTER)
        {
            n->nodeAvailability = NodeAvailability::UNAVAILABLE;
        }
    }
   

    // load player images
    textureManager.LoadTextureFromFile("Marine", "images/player/SFCP_1_01.png");
    textureManager.LoadTextureFromFile("Scientist", "images/player/SFCP_1_38.png");
    textureManager.LoadTextureFromFile("Android", "images/player/SFCP_1_59.png");
    textureManager.LoadTextureFromFile("Teamster", "images/player/SFCP_1_27.png");

    // load skill tree icons 
    textureManager.LoadTextureFromFile("LinguisticsIcon", "images/placeholder_icons/0 - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ZoologyIcon", "images/placeholder_icons/AI - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("BotanyIcon", "images/placeholder_icons/Airlock - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("GeologyIcon", "images/placeholder_icons/Armory - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("IndustrialEquipmentIcon", "images/placeholder_icons/Automed - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("JuryRiggingIcon", "images/placeholder_icons/Cabin - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ChemistryIcon", "images/placeholder_icons/Cargo - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ComputersIcon", "images/placeholder_icons/Command - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ZeroGIcon", "images/placeholder_icons/Cryo - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("MathematicsIcon", "images/placeholder_icons/Docking bay - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ArtIcon", "images/placeholder_icons/Door - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ArcheologyIcon", "images/placeholder_icons/Duct access - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("TheologyIcon", "images/placeholder_icons/Elevator - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("MilitaryTrainingIcon", "images/placeholder_icons/Elevator to bottom - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("RimwiseIcon", "images/placeholder_icons/Elevator to top - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("AthleticsIcon", "images/placeholder_icons/Emergency capsule - Dark - 64x64.png");

    textureManager.LoadTextureFromFile("PsychologyIcon", "images/placeholder_icons/Exit - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("PathologyIcon", "images/placeholder_icons/Fuel - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("FieldMedicineIcon", "images/placeholder_icons/Galley - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("EcologyIcon", "images/placeholder_icons/Intercom - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("AsteroidMiningIcon", "images/placeholder_icons/Jumpdrive - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("MechanicalRepairIcon", "images/placeholder_icons/Lab - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ExplosivesIcon", "images/placeholder_icons/Ladder - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("PharmacologyIcon", "images/placeholder_icons/Ladder bottom - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("HackingIcon", "images/placeholder_icons/Ladder top - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("PilotingIcon", "images/placeholder_icons/Laser - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("PhysicsIcon", "images/placeholder_icons/Medbay - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("MysticismIcon", "images/placeholder_icons/Ramp - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("WildernessSurvivalIcon", "images/placeholder_icons/Reactor core - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("FireArmsIcon", "images/placeholder_icons/Sensors - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("HandToHandCombatIcon", "images/placeholder_icons/Shower - Dark - 64x64.png");

    textureManager.LoadTextureFromFile("SophontologyIcon", "images/placeholder_icons/Supplies - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ExobiologyIcon", "images/placeholder_icons/Terminal - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("SurgeryIcon", "images/placeholder_icons/Cryo - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("PlanetologyIcon", "images/placeholder_icons/Toilet - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("RoboticsIcon", "images/placeholder_icons/Toilets 2 - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("EngineeringIcon", "images/placeholder_icons/Vac suit - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("CyberneticsIcon", "images/placeholder_icons/Vault - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("ArtificialIntelligenceIcon", "images/placeholder_icons/Ventillation - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("HyperspaceIcon", "images/placeholder_icons/Weapon system - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("XenoesotericismIcon", "images/placeholder_icons/Workshop - Dark - 64x64.png");
    textureManager.LoadTextureFromFile("CommandIcon", "images/placeholder_icons/Empty - Dark - 64x64.png");



    SelectClassAlignmentRect01 = { { render.GridX(13), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    SelectClassAlignmentRect02 = { { render.GridX(1), render.GridY(4), render.GridX(10), render.GridY(11) }, false };
    SelectClassAlignmentRect03 = { { render.GridX(8), render.GridY(4), render.GridX(8), render.GridY(9) }, false };
    SelectClassAlignmentRect04 = { { render.GridX(16), render.GridY(4), render.GridX(7), render.GridY(9) }, false };
    SelectClassAlignmentRect05 = { { render.GridX(1), render.GridY(4), render.GridX(7), render.GridY(9) }, false };
    LoadoutSelectAlignmentRect01 = { { render.GridX(1), render.GridY(4), render.GridX(11), render.GridY(11) }, false };
    LoadoutSelectAlignmentRect02 = { { render.GridX(12), render.GridY(4), render.GridX(11), render.GridY(11) }, false };
    SkillTreeAlignmentRect01 = { { render.GridX(2), render.GridY(7), render.GridX(20), render.GridY(06) }, false };
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

        {
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
                    scientistDecisionRequired = true;
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

                className = stateManager.GetPlayer()->GetClass().GetName();

                if (className == "Marine")
                {
                    militaryTrainingNode.nodeAvailability = NodeAvailability::MANDATORY;
                    athleticsNode.nodeAvailability = NodeAvailability::MANDATORY;
                }

                if (className == "Android")
                {
                    linguisticsNode.nodeAvailability = NodeAvailability::MANDATORY;
                    computersNode.nodeAvailability = NodeAvailability::MANDATORY;
                    mathematicsNode.nodeAvailability = NodeAvailability::MANDATORY;
                }

                if (className == "Teamster")
                {
                    industrialEquipmentNode.nodeAvailability = NodeAvailability::MANDATORY;
                    zeroGNode.nodeAvailability = NodeAvailability::MANDATORY;
                }

                // change back to stats once finished working on the skills screen
                currentPage = Page::SKILLS_SELECT;

                break;
            }

            if (selectClassButton.IsHovered(render, false)) {
                selectClassButtonColor = GRAY;
            }
            else selectClassButtonColor = LIGHTGRAY;

            break;
        }

        case Page::LOADOUT_SELECT:

        {
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

        case Page::STATS_SELECT:
        {
            if (!areStatsCopied)
            {
                strengthCopy = stateManager.GetPlayer()->GetClass().GetStrength();
                speedCopy = stateManager.GetPlayer()->GetClass().GetSpeed();
                intellectCopy = stateManager.GetPlayer()->GetClass().GetIntellect();
                combatCopy = stateManager.GetPlayer()->GetClass().GetCombat();
                sanityCopy = stateManager.GetPlayer()->GetClass().GetSanity();
                fearCopy = stateManager.GetPlayer()->GetClass().GetFear();
                bodyCopy = stateManager.GetPlayer()->GetClass().GetBody();
                areStatsCopied = true;
            }

            if (!androidDecisionRequired && !scientistDecisionRequired)
            {
                // increment strength button logic
                if (incrementStrengthButton.IsClicked(render, false)) {
                    if (availableStatPoints != 0)
                    {
                        availableStatPoints--;
                        addedToStrength++;
                        stateManager.GetPlayer()->GetClass().IncreaseStrength(1);
                    }
                }

                if (incrementStrengthButton.IsHovered(render, false)) {
                    if (availableStatPoints != 0)
                        incrementStrengthButtonColor = BLACK;
                    else
                        incrementStrengthButtonColor = MAROON;
                }
                else incrementStrengthButtonColor = GRAY;

                // decrement strength button logic

                if (decrementStrengthButton.IsClicked(render, false)) {
                    if (strengthCopy != stateManager.GetPlayer()->GetClass().GetStrength())
                    {
                        availableStatPoints++;
                        addedToStrength--;
                        stateManager.GetPlayer()->GetClass().DecreaseStrength(1);
                    }
                }

                if (decrementStrengthButton.IsHovered(render, false)) {
                    if (strengthCopy != stateManager.GetPlayer()->GetClass().GetStrength())
                        decrementStrengthButtonColor = BLACK;
                    else
                        decrementStrengthButtonColor = MAROON;
                }
                else decrementStrengthButtonColor = GRAY;

                // increment speed button logic

                if (incrementSpeedButton.IsClicked(render, false)) {
                    if (availableStatPoints != 0)
                    {
                        availableStatPoints--;
                        addedToSpeed++;
                        stateManager.GetPlayer()->GetClass().IncreaseSpeed(1);
                    }
                }

                if (incrementSpeedButton.IsHovered(render, false)) {
                    if (availableStatPoints != 0)
                        incrementSpeedButtonColor = BLACK;
                    else
                        incrementSpeedButtonColor = MAROON;
                }
                else incrementSpeedButtonColor = GRAY;

                // decrement speed button logic

                if (decrementSpeedButton.IsClicked(render, false)) {
                    if (speedCopy != stateManager.GetPlayer()->GetClass().GetSpeed())
                    {
                        availableStatPoints++;
                        addedToSpeed--;
                        stateManager.GetPlayer()->GetClass().DecreaseSpeed(1);
                    }
                }

                if (decrementSpeedButton.IsHovered(render, false)) {
                    if (speedCopy != stateManager.GetPlayer()->GetClass().GetSpeed())
                        decrementSpeedButtonColor = BLACK;
                    else
                        decrementSpeedButtonColor = MAROON;
                }
                else decrementSpeedButtonColor = GRAY;

                // increment intellect button logic

                if (incrementIntellectButton.IsClicked(render, false)) {
                    if (availableStatPoints != 0)
                    {
                        availableStatPoints--;
                        addedToIntellect++;
                        stateManager.GetPlayer()->GetClass().IncreaseIntellect(1);
                    }
                }

                if (incrementIntellectButton.IsHovered(render, false)) {
                    if (availableStatPoints != 0)
                        incrementIntellectButtonColor = BLACK;
                    else
                        incrementIntellectButtonColor = MAROON;
                }
                else incrementIntellectButtonColor = GRAY;

                // decrement intellect button logic

                if (decrementIntellectButton.IsClicked(render, false)) {
                    if (intellectCopy != stateManager.GetPlayer()->GetClass().GetIntellect())
                    {
                        availableStatPoints++;
                        addedToIntellect--;
                        stateManager.GetPlayer()->GetClass().DecreaseIntellect(1);
                    }
                }

                if (decrementIntellectButton.IsHovered(render, false)) {
                    if (intellectCopy != stateManager.GetPlayer()->GetClass().GetIntellect())
                        decrementIntellectButtonColor = BLACK;
                    else
                        decrementIntellectButtonColor = MAROON;
                }
                else decrementIntellectButtonColor = GRAY;

                // increment combat button logic

                if (incrementCombatButton.IsClicked(render, false)) {
                    if (availableStatPoints != 0)
                    {
                        availableStatPoints--;
                        addedToCombat++;
                        stateManager.GetPlayer()->GetClass().IncreaseCombat(1);
                    }
                }

                if (incrementCombatButton.IsHovered(render, false)) {
                    if (availableStatPoints != 0)
                        incrementCombatButtonColor = BLACK;
                    else
                        incrementCombatButtonColor = MAROON;
                }
                else incrementCombatButtonColor = GRAY;

                // decrement combat button logic

                if (decrementCombatButton.IsClicked(render, false)) {
                    if (combatCopy != stateManager.GetPlayer()->GetClass().GetCombat())
                    {
                        availableStatPoints++;
                        addedToCombat--;
                        stateManager.GetPlayer()->GetClass().DecreaseCombat(1);
                    }
                }

                if (decrementCombatButton.IsHovered(render, false)) {
                    if (combatCopy != stateManager.GetPlayer()->GetClass().GetCombat())
                        decrementCombatButtonColor = BLACK;
                    else
                        decrementCombatButtonColor = MAROON;
                }
                else decrementCombatButtonColor = GRAY;

                // increment sanity button logic

                if (incrementSanityButton.IsClicked(render, false)) {
                    if (availableSavePoints != 0)
                    {
                        availableSavePoints--;
                        addedToSanity++;
                        stateManager.GetPlayer()->GetClass().IncreaseSanity(1);
                    }
                }

                if (incrementSanityButton.IsHovered(render, false)) {
                    if (availableSavePoints != 0)
                        incrementSanityButtonColor = BLACK;
                    else
                        incrementSanityButtonColor = MAROON;
                }
                else incrementSanityButtonColor = GRAY;

                // decrement sanity button logic

                if (decrementSanityButton.IsClicked(render, false)) {
                    if (sanityCopy != stateManager.GetPlayer()->GetClass().GetSanity())
                    {
                        availableSavePoints++;
                        addedToSanity--;
                        stateManager.GetPlayer()->GetClass().DecreaseSanity(1);
                    }
                }

                if (decrementSanityButton.IsHovered(render, false)) {
                    if (sanityCopy != stateManager.GetPlayer()->GetClass().GetSanity())
                        decrementSanityButtonColor = BLACK;
                    else
                        decrementSanityButtonColor = MAROON;
                }
                else decrementSanityButtonColor = GRAY;

                // increment fear button logic

                if (incrementFearButton.IsClicked(render, false)) {
                    if (availableSavePoints != 0)
                    {
                        availableSavePoints--;
                        addedToFear++;
                        stateManager.GetPlayer()->GetClass().IncreaseFear(1);
                    }
                }

                if (incrementFearButton.IsHovered(render, false)) {
                    if (availableSavePoints != 0)
                        incrementFearButtonColor = BLACK;
                    else
                        incrementFearButtonColor = MAROON;
                }
                else incrementFearButtonColor = GRAY;

                // decrement fear button logic

                if (decrementFearButton.IsClicked(render, false)) {
                    if (fearCopy != stateManager.GetPlayer()->GetClass().GetFear())
                    {
                        availableSavePoints++;
                        addedToFear--;
                        stateManager.GetPlayer()->GetClass().DecreaseFear(1);
                    }
                }

                if (decrementFearButton.IsHovered(render, false)) {
                    if (fearCopy != stateManager.GetPlayer()->GetClass().GetFear())
                        decrementFearButtonColor = BLACK;
                    else
                        decrementFearButtonColor = MAROON;
                }
                else decrementFearButtonColor = GRAY;

                // increment body button logic

                if (incrementBodyButton.IsClicked(render, false)) {
                    if (availableSavePoints != 0)
                    {
                        availableSavePoints--;
                        addedToBody++;
                        stateManager.GetPlayer()->GetClass().IncreaseBody(1);
                    }
                }

                if (incrementBodyButton.IsHovered(render, false)) {
                    if (availableSavePoints != 0)
                        incrementBodyButtonColor = BLACK;
                    else
                        incrementBodyButtonColor = MAROON;
                }
                else incrementBodyButtonColor = GRAY;

                // decrement body button logic

                if (decrementBodyButton.IsClicked(render, false)) {
                    if (bodyCopy != stateManager.GetPlayer()->GetClass().GetBody())
                    {
                        availableSavePoints++;
                        addedToBody--;
                        stateManager.GetPlayer()->GetClass().DecreaseBody(1);
                    }
                }

                if (decrementBodyButton.IsHovered(render, false)) {
                    if (bodyCopy != stateManager.GetPlayer()->GetClass().GetBody())
                        decrementBodyButtonColor = BLACK;
                    else
                        decrementBodyButtonColor = MAROON;
                }
                else decrementBodyButtonColor = GRAY;

                if (availableSavePoints == 0 && availableStatPoints == 0)
                {
                    isAllocated = true;
                }
                else
                    isAllocated = false;

                if (isAllocated)
                {
                    if (statsConfirmButton.IsClicked(render, false)) {
                        currentPage = Page::LOADOUT_SELECT;
                    }

                    if (statsConfirmButton.IsHovered(render, false)) {
                        statsConfirmButtonColor = GRAY;
                    }
                    else statsConfirmButtonColor = LIGHTGRAY;
                }

            }

            if (androidDecisionRequired)
            {
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
                    strengthCopy -= 10;
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

                if (androidHandicapSpeedButton.IsClicked(render, false)) {
                    speedCopy -= 10;
                    androidDecisionRequired = false;
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

                if (androidHandicapIntellectButton.IsClicked(render, false)) {
                    intellectCopy -= 10;
                    androidDecisionRequired = false;
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

                if (androidHandicapCombatButton.IsClicked(render, false)) {
                    combatCopy -= 10;
                    androidDecisionRequired = false;
                }
            }

            if (scientistDecisionRequired)
            {
                // scientist buff strength button logic

                if (scientistBuffStrengthButton.IsHovered(render, false)) {
                    scientistBuffStrengthButtonColor = BLACK;
                    if (!isStrengthIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().IncreaseStrength(5);
                        isStrengthIncreased = true;
                    }
                }
                else
                {
                    scientistBuffStrengthButtonColor = GRAY;
                    if (isStrengthIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().DecreaseStrength(5);
                        isStrengthIncreased = false;
                    }
                }

                if (scientistBuffStrengthButton.IsClicked(render, false)) {
                    strengthCopy += 5;
                    scientistDecisionRequired = false;
                }

                // scientist buff speed button logic

                if (scientistBuffSpeedButton.IsHovered(render, false)) {
                    scientistBuffSpeedButtonColor = BLACK;
                    if (!isSpeedIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().IncreaseSpeed(5);
                        isSpeedIncreased = true;
                    }
                }
                else
                {
                    scientistBuffSpeedButtonColor = GRAY;
                    if (isSpeedIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().DecreaseSpeed(5);
                        isSpeedIncreased = false;
                    }
                }

                if (scientistBuffSpeedButton.IsClicked(render, false)) {
                    speedCopy += 5;
                    scientistDecisionRequired = false;
                }

                // scientist buff intellect button logic

                if (scientistBuffIntellectButton.IsHovered(render, false)) {
                    scientistBuffIntellectButtonColor = BLACK;
                    if (!isIntellectIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().IncreaseIntellect(5);
                        isIntellectIncreased = true;
                    }
                }
                else
                {
                    scientistBuffIntellectButtonColor = GRAY;
                    if (isIntellectIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().DecreaseIntellect(5);
                        isIntellectIncreased = false;
                    }
                }

                if (scientistBuffIntellectButton.IsClicked(render, false)) {
                    intellectCopy += 5;
                    scientistDecisionRequired = false;
                }

                // scientist buff combat button logic

                if (scientistBuffCombatButton.IsHovered(render, false)) {
                    scientistBuffCombatButtonColor = BLACK;
                    if (!isCombatIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().IncreaseCombat(5);
                        isCombatIncreased = true;
                    }
                }
                else
                {
                    scientistBuffCombatButtonColor = GRAY;
                    if (isCombatIncreased)
                    {
                        stateManager.GetPlayer()->GetClass().DecreaseCombat(5);
                        isCombatIncreased = false;
                    }
                }

                if (scientistBuffCombatButton.IsClicked(render, false)) {
                    combatCopy += 5;
                    scientistDecisionRequired = false;
                }
            }
        }

        case Page::SKILLS_SELECT:
        {
            // trained
             
            if (linguisticsNode.IsHovered())
            {
                linguisticsNode.isTransparent = false;
                psychologyNode.isTransparent = false;
                sophontologyNode.isTransparent = false;

                if (linguisticsNode.IsClicked())
                {
                    if (linguisticsNode.GetNodeAvailability() == NodeAvailability::AVAILABLE)
                    {
                        // a function here that uses the json data to check for 'unlocks' and sets those skills to 'available'
                        linguisticsNode.nodeAvailability = NodeAvailability::SELECTED;
                        hasNodeBeenClicked = true;
                    }

                    if (linguisticsNode.GetNodeAvailability() == NodeAvailability::SELECTED && hasNodeBeenClicked == false)
                    {
                        linguisticsNode.nodeAvailability = NodeAvailability::AVAILABLE;
                    }
                }

            }

            // why does the else only need to be called once, and why here? (moving it to the end wil break it)
            else
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }
            }

            if (zoologyNode.IsHovered()) 
            {
                if (zoologyNode.IsClicked())
                {
                    if (zoologyNode.GetNodeAvailability() == NodeAvailability::AVAILABLE)
                    {
                        zoologyNode.nodeAvailability = NodeAvailability::SELECTED;
                        hasNodeBeenClicked = true;
                    }

                    if (zoologyNode.GetNodeAvailability() == NodeAvailability::SELECTED && hasNodeBeenClicked == false)
                    {
                        zoologyNode.nodeAvailability = NodeAvailability::AVAILABLE;
                    }
                }

                zoologyNode.isTransparent = false;
                psychologyNode.isTransparent = false;
                pathologyNode.isTransparent = false;
                fieldMedicineNode.isTransparent = false;
                sophontologyNode.isTransparent = false;
                exobiologyNode.isTransparent = false;
                surgeryNode.isTransparent = false;

            }



            if (botanyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                botanyNode.isTransparent = false;
                pathologyNode.isTransparent = false;
                exobiologyNode.isTransparent = false;
                surgeryNode.isTransparent = false;
                sophontologyNode.isTransparent = false;
                psychologyNode.isTransparent = false;
                fieldMedicineNode.isTransparent = false;
                ecologyNode.isTransparent = false;
                planetologyNode.isTransparent = false;
                wildernessSurvivalNode.isTransparent = false;
            }

            if (geologyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                geologyNode.isTransparent = false;
                asteroidMiningNode.isTransparent = false;
                ecologyNode.isTransparent = false;
                planetologyNode.isTransparent = false;
            }

            if (industrialEquipmentNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                industrialEquipmentNode.isTransparent = false;
                asteroidMiningNode.isTransparent = false;
                mechanicalRepairNode.isTransparent = false;
                roboticsNode.isTransparent = false;
                engineeringNode.isTransparent = false;
                cyberneticsNode.isTransparent = false;
                planetologyNode.isTransparent = false;
            }

            if (juryRiggingNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                juryRiggingNode.isTransparent = false;
                mechanicalRepairNode.isTransparent = false;
                roboticsNode.isTransparent = false;
                engineeringNode.isTransparent = false;
                cyberneticsNode.isTransparent = false;
                explosivesNode.isTransparent = false;
            }

            if (chemistryNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                chemistryNode.isTransparent = false;
                explosivesNode.isTransparent = false;
                pharmacologyNode.isTransparent = false;
            }

            if (computersNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                computersNode.isTransparent = false;
                hackingNode.isTransparent = false;
                artificialIntelligenceNode.isTransparent = false;
            }

            if (zeroGNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                zeroGNode.isTransparent = false;
                pilotingNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
                commandNode.isTransparent = false;
            }

            if (mathematicsNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                mathematicsNode.isTransparent = false;
                physicsNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
            }

            if (artNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                artNode.isTransparent = false;
                mysticismNode.isTransparent = false;
                xenoesotericismNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
            }

            if (archeologyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                archeologyNode.isTransparent = false;
                mysticismNode.isTransparent = false;
                xenoesotericismNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
            }

            if (theologyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                theologyNode.isTransparent = false;
                mysticismNode.isTransparent = false;
                xenoesotericismNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
            }

            if (militaryTrainingNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                militaryTrainingNode.isTransparent = false;
                explosivesNode.isTransparent = false;
                wildernessSurvivalNode.isTransparent = false;
                fireArmsNode.isTransparent = false;
                handToHandCombatNode.isTransparent = false;
                commandNode.isTransparent = false;
            }

            if (rimwiseNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                rimwiseNode.isTransparent = false;
                fireArmsNode.isTransparent = false;
                handToHandCombatNode.isTransparent = false;
                commandNode.isTransparent = false;
            }

            if (athleticsNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                athleticsNode.isTransparent = false;
                handToHandCombatNode.isTransparent = false;
            }

            // expert

            if (psychologyNode.IsHovered())
            {
                if (psychologyNode.IsClicked())
                {
                    if (psychologyNode.GetNodeAvailability() == NodeAvailability::AVAILABLE)
                    {
                        psychologyNode.nodeAvailability = NodeAvailability::SELECTED;
                        hasNodeBeenClicked = true;
                    }

                    if (psychologyNode.GetNodeAvailability() == NodeAvailability::SELECTED && hasNodeBeenClicked == false)
                    {
                        psychologyNode.nodeAvailability = NodeAvailability::AVAILABLE;
                    }
                }

                linguisticsNode.isTransparent = false;
                zoologyNode.isTransparent = false;
                psychologyNode.isTransparent = false;
                sophontologyNode.isTransparent = false;

            }

            if (pathologyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                zoologyNode.isTransparent = false;
                botanyNode.isTransparent = false;
                pathologyNode.isTransparent = false;
                exobiologyNode.isTransparent = false;
                surgeryNode.isTransparent = false;
            }

            if (fieldMedicineNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                fieldMedicineNode.isTransparent = false;
                zoologyNode.isTransparent = false;
                botanyNode.isTransparent = false;
                surgeryNode.isTransparent = false;
            }

            if (ecologyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                geologyNode.isTransparent = false;
                botanyNode.isTransparent = false;
                ecologyNode.isTransparent = false;
                planetologyNode.isTransparent = false;
            }

            if (asteroidMiningNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                industrialEquipmentNode.isTransparent = false;
                asteroidMiningNode.isTransparent = false;
                geologyNode.isTransparent = false;
                planetologyNode.isTransparent = false;
            }

            if (mechanicalRepairNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                juryRiggingNode.isTransparent = false;
                industrialEquipmentNode.isTransparent = false;
                mechanicalRepairNode.isTransparent = false;
                roboticsNode.isTransparent = false;
                engineeringNode.isTransparent = false;
                cyberneticsNode.isTransparent = false;
            }

            if (explosivesNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                chemistryNode.isTransparent = false;
                explosivesNode.isTransparent = false;
                militaryTrainingNode.isTransparent = false;
                juryRiggingNode.isTransparent = false;
            }

            if (pharmacologyNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                pharmacologyNode.isTransparent = false;
                chemistryNode.isTransparent = false;
            }

            if (hackingNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                hackingNode.isTransparent = false;
                computersNode.isTransparent = false;
                artificialIntelligenceNode.isTransparent = false;
            }

            if (pilotingNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                pilotingNode.isTransparent = false;
                zeroGNode.isTransparent = false;
                commandNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
            }

            if (physicsNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                physicsNode.isTransparent = false;
                mathematicsNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
            }

            if (mysticismNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                archeologyNode.isTransparent = false;
                mysticismNode.isTransparent = false;
                xenoesotericismNode.isTransparent = false;
                hyperspaceNode.isTransparent = false;
                artNode.isTransparent = false;
                theologyNode.isTransparent = false;
            }

            if (wildernessSurvivalNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                wildernessSurvivalNode.isTransparent = false;
                botanyNode.isTransparent = false;
                militaryTrainingNode.isTransparent = false;
            }

            if (fireArmsNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                militaryTrainingNode.isTransparent = false;
                rimwiseNode.isTransparent = false;
                fireArmsNode.isTransparent = false;
                commandNode.isTransparent = false;
            }

            if (handToHandCombatNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                rimwiseNode.isTransparent = false;
                militaryTrainingNode.isTransparent = false;
                handToHandCombatNode.isTransparent = false;
                athleticsNode.isTransparent = false;
            }

             // master

            if (sophontologyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                linguisticsNode.isTransparent = false;
                zoologyNode.isTransparent = false;
                psychologyNode.isTransparent = false;
                sophontologyNode.isTransparent = false;

            }

            if (exobiologyNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                zoologyNode.isTransparent = false;
                botanyNode.isTransparent = false;
                pathologyNode.isTransparent = false;
                exobiologyNode.isTransparent = false;
            }

            if (surgeryNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                pathologyNode.isTransparent = false;
                fieldMedicineNode.isTransparent = false;
                zoologyNode.isTransparent = false;
                botanyNode.isTransparent = false;
                surgeryNode.isTransparent = false;
            }

            if (planetologyNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                geologyNode.isTransparent = false;
                botanyNode.isTransparent = false;
                ecologyNode.isTransparent = false;
                planetologyNode.isTransparent = false;
                industrialEquipmentNode.isTransparent = false;
                asteroidMiningNode.isTransparent = false;
            }

            if (roboticsNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes) 
                {
                    node->isTransparent = true;
                }

                roboticsNode.isTransparent = false;
                mechanicalRepairNode.isTransparent = false;
                industrialEquipmentNode.isTransparent = false;
                juryRiggingNode.isTransparent = false;
            }

            if (engineeringNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                engineeringNode.isTransparent = false;
                mechanicalRepairNode.isTransparent = false;
                industrialEquipmentNode.isTransparent = false;
                juryRiggingNode.isTransparent = false;
            }

            if (cyberneticsNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                cyberneticsNode.isTransparent = false;
                mechanicalRepairNode.isTransparent = false;
                industrialEquipmentNode.isTransparent = false;
                juryRiggingNode.isTransparent = false;
            }

            if (artificialIntelligenceNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                artificialIntelligenceNode.isTransparent = false;
                hackingNode.isTransparent = false;
                computersNode.isTransparent = false;
            }

            if (hyperspaceNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                hyperspaceNode.isTransparent = false;
                physicsNode.isTransparent = false;
                pilotingNode.isTransparent = false;
                mysticismNode.isTransparent = false;
                zeroGNode.isTransparent = false;
                mathematicsNode.isTransparent = false;
                artificialIntelligenceNode.isTransparent = false;
                archeologyNode.isTransparent = false;
                theologyNode.isTransparent = false;
            }

            if (xenoesotericismNode.IsHovered()) 
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                xenoesotericismNode.isTransparent = false;
                mysticismNode.isTransparent = false;
                artificialIntelligenceNode.isTransparent = false;
                archeologyNode.isTransparent = false;
                theologyNode.isTransparent = false;
            }

            if (commandNode.IsHovered())
            {
                for (SkillTreeNode* node : allNodes)
                {
                    node->isTransparent = true;
                }

                commandNode.isTransparent = false;
                fireArmsNode.isTransparent = false;
                militaryTrainingNode.isTransparent = false;
                rimwiseNode.isTransparent = false;
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
        //stateManager.GetPlayer()->GetClass().ResetDefaults();
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
    render.DrawDebugRect(SelectClassAlignmentRect05);

    mainMenuButton.Draw(render, mainMenuButtonColor);

    if (drawDebugGrid)
    {
        render.DrawGrid(true);
    }

    Rectangle mechanicsRec = { render.AlignCenterXInRect(SelectClassAlignmentRect05, 600), render.GridY(4) + 30, 600, 500 };

    switch (GetCurrentPage())
    {

    case Page::CLASS_SELECT:

    {
        render.DrawTextBlock
        (
            "Choose Your Class",
            render.TextScreenCenterX(800),
            render.GridY(1),
            800,
            TextAlign::Center,
            TextSize::SmallerTitle
        );

        render.DrawRectangle(render.AlignCenterXInRect(SelectClassAlignmentRect05, 600), render.GridY(4) + 30, 600, 500, LIGHTGRAY);

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

            render.DrawTextListInRect(marine.GetMechanics(), SelectClassAlignmentRect05.rect, TextAlign::Center, TextSize::MenuSmall, 100);

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

            render.DrawTextListInRect(scientist.GetMechanics(), SelectClassAlignmentRect05.rect, TextAlign::Center, TextSize::MenuSmall, 140);

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

            render.DrawTextListInRect(teamster.GetMechanics(), SelectClassAlignmentRect05.rect, TextAlign::Center, TextSize::MenuSmall, 180);

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

            render.DrawTextListInRect(android.GetMechanics(), SelectClassAlignmentRect05.rect, TextAlign::Center, TextSize::MenuSmall, 100);

            break;
        }

        previousButton.Draw(render, previousButtonColor);
        nextButton.Draw(render, nextButtonColor);
        selectClassButton.Draw(render, selectClassButtonColor);

        break;
    }

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

    case Page::STATS_SELECT:

    {
        int strength = stateManager.GetPlayer()->GetClass().GetStrength();
        int speed = stateManager.GetPlayer()->GetClass().GetSpeed();
        int intellect = stateManager.GetPlayer()->GetClass().GetIntellect();
        int combat = stateManager.GetPlayer()->GetClass().GetCombat();
        
        int sanity = stateManager.GetPlayer()->GetClass().GetSanity();
        int fear = stateManager.GetPlayer()->GetClass().GetFear();
        int body = stateManager.GetPlayer()->GetClass().GetBody();

        className = stateManager.GetPlayer()->GetClass().GetName();

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
            render.GridY(7)+32,
            LIGHTGRAY
        );

        render.DrawRectangle(
            render.AlignCenterXInRect(LoadoutSelectAlignmentRect02, render.GridX(10)),
            render.GridY(6),
            render.GridX(10),
            render.GridY(7)+32,
            LIGHTGRAY
        );

        // draw stat types

        render.DrawTextBlockNoPadding
        (
            "Strength: " + std::to_string(strength),
            render.GridX(2),
            render.GridY(6),
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Speed: " + std::to_string(speed),
            render.GridX(2),
            render.GridY(8),
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Intellect: " + std::to_string(intellect),
            render.GridX(2),
            render.GridY(10),
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Combat: " + std::to_string(combat),
            render.GridX(2),
            render.GridY(12),
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        // draw save types

        render.DrawTextBlockNoPadding
        (
            "Sanity: " + std::to_string(sanity),
            render.GridX(13),
            render.GridY(7),
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Fear: " + std::to_string(fear),
            render.GridX(13),
            render.GridY(9),
            800,
            TextAlign::Left,
            TextSize::MenuSmall
        );

        render.DrawTextBlockNoPadding
        (
            "Body: " + std::to_string(body),
            render.GridX(13),
            render.GridY(11),
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

        incrementSanityButton.Draw(render, incrementSanityButtonColor);
        incrementFearButton.Draw(render, incrementFearButtonColor);
        incrementBodyButton.Draw(render, incrementBodyButtonColor);

        decrementSanityButton.Draw(render, decrementSanityButtonColor);
        decrementFearButton.Draw(render, decrementFearButtonColor);
        decrementBodyButton.Draw(render, decrementBodyButtonColor);

        render.DrawPipsGrid(addedToStrength, render.GridX(10) + 30, render.GridY(6) + 30);
        render.DrawPipsGrid(addedToSpeed, render.GridX(10) + 30, render.GridY(8) + 30);
        render.DrawPipsGrid(addedToIntellect, render.GridX(10) + 30, render.GridY(10) + 30);
        render.DrawPipsGrid(addedToCombat, render.GridX(10) + 30, render.GridY(12) + 30);

        render.DrawPipsGrid(addedToSanity, render.GridX(21) + 30, render.GridY(7) + 30);
        render.DrawPipsGrid(addedToFear, render.GridX(21) + 30, render.GridY(9) + 30);
        render.DrawPipsGrid(addedToBody, render.GridX(21) + 30, render.GridY(11) + 30);

        if (!isAllocated)
        {
            render.DrawTextBlock
            (
                "Please Allocate all Stats to Proceed",
                render.TextScreenCenterX(1000),
                render.GridY(14),
                1000,
                TextAlign::Center,
                TextSize::MenuSmall
            );
        }
        else
        {
            statsConfirmButton.Draw(render, statsConfirmButtonColor);
        }



        if (className == "Scientist" && scientistDecisionRequired == true)
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
                "As a scientist, you must choose a stat to recieve a +5 point buff",
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

            scientistBuffStrengthButton.Draw(render, scientistBuffStrengthButtonColor);
            scientistBuffSpeedButton.Draw(render, scientistBuffSpeedButtonColor);
            scientistBuffIntellectButton.Draw(render, scientistBuffIntellectButtonColor);
            scientistBuffCombatButton.Draw(render, scientistBuffCombatButtonColor);
        }



        if (className == "Android" && androidDecisionRequired == true)
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
                std::to_string(stateManager.GetPlayer()->GetClass().GetStrength()),
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

    case Page::SKILLS_SELECT:
    {
        className = stateManager.GetPlayer()->GetClass().GetName();

        render.DrawRectangle(
            render.GridX(1) / 5,
            render.GridY(1) + render.GridX(1) / 7,
            ((render.GridX(24) - (render.GridX(1) / 2.5)) / 2) - 10,
            render.GridY(5 ) - render.GridX(1) / 2.5,
            LIGHTGRAY
        );

        render.DrawRectangle(
            render.GridX(12) + 10,
            render.GridY(1) + render.GridX(1) / 7,
            ((render.GridX(24) - (render.GridX(1) / 2.5)) / 2) - 10,
            render.GridY(5) - render.GridX(1) / 2.5,
            LIGHTGRAY
        );

        render.DrawRectangle(
            render.GridX(1) / 5,
            render.GridY(6),
            render.GridX(24) - render.GridX(1) / 2.5,
            render.GridY(10) - 40,
            LIGHTGRAY
        );

        render.DrawTextBlockNoPadding(
            "Select skills for " + className,
            render.GridX(1) / 5,
            render.GridY(1) + render.GridX(1) / 7,
            ((render.GridX(24) - (render.GridX(1) / 2.5)) / 2) - 10,
            TextAlign::Center,
            TextSize::MenuMedium
        );

        render.DrawTextBlockNoPadding(
            stateManager.GetPlayer()->GetClass().GetClassStatsInstructions(),
            render.GridX(1) / 5,
            render.GridY(3),
            ((render.GridX(24) - (render.GridX(1) / 2.5)) / 2) - 10,
            TextAlign::Center,
            TextSize::Dialogue
        );

        render.DrawTextBlockNoPadding(
            "Rules for skill selection:",
            render.GridX(12) + 10,
            render.GridY(1) + render.GridX(1) / 7,
            ((render.GridX(24) - (render.GridX(1) / 2.5)) / 2) - 10,
            TextAlign::Center,
            TextSize::MenuMedium
        );

        render.DrawTextBlockNoPadding(
            "To take a Master or Expert skill you must first take at least one of its prerequisite skills. Hover over a node to see the skill paths. Hover over an skill icon for a description.",
            render.GridX(12) + 10,
            render.GridY(3),
            ((render.GridX(24) - (render.GridX(1) / 2.5)) / 2) - 10,
            TextAlign::Center,
            TextSize::Dialogue
        );


        render.DrawDebugRect(SkillTreeAlignmentRect01);

        float spacing = SkillTreeAlignmentRect01.rect.width / 13.5;


        //nodes row 01


        linguisticsNode.Draw(render, render.GridX(1) - 9, render.GridY(7), linguisticsNode.innerRadius, linguisticsNode.outerRadius, "Linguistics");
        zoologyNode.Draw(render, render.GridX(1) - 9 + spacing, render.GridY(7), 18, 22, "Zoology");
        botanyNode.Draw(render, render.GridX(1) - 9 + spacing * 2, render.GridY(7), 18, 22, "Botany");
        geologyNode.Draw(render, render.GridX(1) - 9 + spacing * 3, render.GridY(7), 18, 22, "Geology");
        industrialEquipmentNode.Draw(render, render.GridX(1) + spacing * 4, render.GridY(7), 18, 22, "Industrial Equipment");
        juryRiggingNode.Draw(render, render.GridX(1) - 9 + spacing * 5, render.GridY(7), 18, 22, "Jury Rigging");
        chemistryNode.Draw(render, render.GridX(1) - 9 + spacing * 6, render.GridY(7), 18, 22, "Chemistry");
        computersNode.Draw(render, render.GridX(1) - 9 + spacing * 7, render.GridY(7), 18, 22, " Computers");
        zeroGNode.Draw(render, render.GridX(1) - 9 + spacing * 8, render.GridY(7), 18, 22, "ZeroG");
        mathematicsNode.Draw(render, render.GridX(1) - 9 + spacing * 9, render.GridY(7), 18, 22, "Mathematics");
        artNode.Draw(render, render.GridX(1) - 9 + spacing * 10, render.GridY(7), 18, 22, "Art");
        archeologyNode.Draw(render, render.GridX(1) - 9 + spacing * 11, render.GridY(7), 18, 22, "Archeology");
        theologyNode.Draw(render, render.GridX(1) - 9 + spacing * 12, render.GridY(7), 18, 22, "Theology");
        militaryTrainingNode.Draw(render, render.GridX(1) - 9 + spacing * 13, render.GridY(7), 18, 22, "Military Training");
        rimwiseNode.Draw(render, render.GridX(1) - 9 + spacing * 14, render.GridY(7), 18, 22, "Rimwise");
        athleticsNode.Draw(render, render.GridX(1) - 9 + spacing * 15, render.GridY(7), 18, 22, "Athletics");

        //nodes row 02

        psychologyNode.Draw(render, render.GridX(1) - 9 - spacing/2 + spacing, render.GridY(10), 18, 22, "Psychology");
        pathologyNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 2, render.GridY(10), 18, 22, "Pathology");
        fieldMedicineNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 3, render.GridY(10), 18, 22, "Field Medicine");
        ecologyNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 4, render.GridY(10), 18, 22, "Ecology");
        asteroidMiningNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 5, render.GridY(10), 18, 22, "Asteroid Mining");
        mechanicalRepairNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 6, render.GridY(10), 18, 22, "Mechanical Repair");
        explosivesNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 7, render.GridY(10), 18, 22, "Explosives");
        pharmacologyNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 8, render.GridY(10), 18, 22, "Pharma- cology");
        hackingNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 9, render.GridY(10), 18, 22, "Hacking");
        pilotingNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 10, render.GridY(10), 18, 22, "Piloting");
        physicsNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 11, render.GridY(10), 18, 22, "Physics");
        mysticismNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 12, render.GridY(10), 18, 22, "Mysticism");
        wildernessSurvivalNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 13, render.GridY(10), 18, 22, "Wilderness Survival");
        fireArmsNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 14, render.GridY(10), 18, 22, "Fire Arms");
        handToHandCombatNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 15, render.GridY(10), 18, 22, "Hand To Hand");

        //nodes row 03

        sophontologyNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 3, render.GridY(13), 18, 22, "Sophon- tology");
        exobiologyNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 4, render.GridY(13), 18, 22, "Exobiology");
        surgeryNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 5, render.GridY(13), 18, 22, "Surgery");
        planetologyNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 6, render.GridY(13), 18, 22, "Planetology");
        roboticsNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 7, render.GridY(13), 18, 22, "Robotics");
        engineeringNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 8, render.GridY(13), 18, 22, "Engineering");
        cyberneticsNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 9, render.GridY(13), 18, 22, "Cyber- netics");
        artificialIntelligenceNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 10, render.GridY(13), 18, 22, "Artificial Intelligence");
        hyperspaceNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 11, render.GridY(13), 18, 22, "Hyperspace");
        xenoesotericismNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 12, render.GridY(13), 18, 22, "Xenoeso- tericism");
        commandNode.Draw(render, render.GridX(1) - 9 - spacing / 2 + spacing * 13, render.GridY(13), 18, 22, "Command");

        //icons row 01

        //render.DrawSkillTreeIcon("LinguisticsIcon", { (float)linguisticsNode.cenX - 32, (float)linguisticsNode.cenY + 20 }, 0.f, 1.0f, Fade(WHITE, 0.5f), { 102, 191, 255, 80 });

        linguisticsNode.DrawIcon(render, "LinguisticsIcon", { (float)linguisticsNode.cenX - 32, (float)linguisticsNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        zoologyNode.DrawIcon(render, "ZoologyIcon", { (float)zoologyNode.cenX - 32, (float)zoologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        botanyNode.DrawIcon(render, "BotanyIcon", { (float)botanyNode.cenX - 32, (float)botanyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        geologyNode.DrawIcon(render, "GeologyIcon", { (float)geologyNode.cenX - 32, (float)geologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        industrialEquipmentNode.DrawIcon(render, "IndustrialEquipmentIcon", { (float)industrialEquipmentNode.cenX - 32, (float)industrialEquipmentNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        juryRiggingNode.DrawIcon(render, "JuryRiggingIcon", { (float)juryRiggingNode.cenX - 32, (float)juryRiggingNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        chemistryNode.DrawIcon(render, "ChemistryIcon", { (float)chemistryNode.cenX - 32, (float)chemistryNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        computersNode.DrawIcon(render, "ComputersIcon", { (float)computersNode.cenX - 32, (float)computersNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        zeroGNode.DrawIcon(render, "ZeroGIcon", { (float)zeroGNode.cenX - 32, (float)zeroGNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        mathematicsNode.DrawIcon(render, "MathematicsIcon", { (float)mathematicsNode.cenX - 32, (float)mathematicsNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        artNode.DrawIcon(render, "ArtIcon", { (float)artNode.cenX - 32, (float)artNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        archeologyNode.DrawIcon(render, "ArcheologyIcon", { (float)archeologyNode.cenX - 32, (float)archeologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        theologyNode.DrawIcon(render, "TheologyIcon", { (float)theologyNode.cenX - 32, (float)theologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        militaryTrainingNode.DrawIcon(render, "MilitaryTrainingIcon", { (float)militaryTrainingNode.cenX - 32, (float)militaryTrainingNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        rimwiseNode.DrawIcon(render, "RimwiseIcon", { (float)rimwiseNode.cenX - 32, (float)rimwiseNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);
        athleticsNode.DrawIcon(render, "AthleticsIcon", { (float)athleticsNode.cenX - 32, (float)athleticsNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeTrainedColor);

        psychologyNode.DrawIcon(render, "PsychologyIcon", { (float)psychologyNode.cenX - 32, (float)psychologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        pathologyNode.DrawIcon(render, "PathologyIcon", { (float)pathologyNode.cenX - 32, (float)pathologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        fieldMedicineNode.DrawIcon(render, "FieldMedicineIcon", { (float)fieldMedicineNode.cenX - 32, (float)fieldMedicineNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        ecologyNode.DrawIcon(render, "EcologyIcon", { (float)ecologyNode.cenX - 32, (float)ecologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        asteroidMiningNode.DrawIcon(render, "AsteroidMiningIcon", { (float)asteroidMiningNode.cenX - 32, (float)asteroidMiningNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        mechanicalRepairNode.DrawIcon(render, "MechanicalRepairIcon", { (float)mechanicalRepairNode.cenX - 32, (float)mechanicalRepairNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        explosivesNode.DrawIcon(render, "ExplosivesIcon", { (float)explosivesNode.cenX - 32, (float)explosivesNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        pharmacologyNode.DrawIcon(render, "PharmacologyIcon", { (float)pharmacologyNode.cenX - 32, (float)pharmacologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        hackingNode.DrawIcon(render, "HackingIcon", { (float)hackingNode.cenX - 32, (float)hackingNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        pilotingNode.DrawIcon(render, "PilotingIcon", { (float)pilotingNode.cenX - 32, (float)pilotingNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        physicsNode.DrawIcon(render, "PhysicsIcon", { (float)physicsNode.cenX - 32, (float)physicsNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        mysticismNode.DrawIcon(render, "MysticismIcon", { (float)mysticismNode.cenX - 32, (float)mysticismNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        wildernessSurvivalNode.DrawIcon(render, "WildernessSurvivalIcon", { (float)wildernessSurvivalNode.cenX - 32, (float)wildernessSurvivalNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        fireArmsNode.DrawIcon(render, "FireArmsIcon", { (float)fireArmsNode.cenX - 32, (float)fireArmsNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);
        handToHandCombatNode.DrawIcon(render, "HandToHandCombatIcon", { (float)handToHandCombatNode.cenX - 32, (float)handToHandCombatNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeMasterColor);

        sophontologyNode.DrawIcon(render, "SophontologyIcon", { (float)sophontologyNode.cenX - 32, (float)sophontologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        exobiologyNode.DrawIcon(render, "ExobiologyIcon", { (float)exobiologyNode.cenX - 32, (float)exobiologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        surgeryNode.DrawIcon(render, "SurgeryIcon", { (float)surgeryNode.cenX - 32, (float)surgeryNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        planetologyNode.DrawIcon(render, "PlanetologyIcon", { (float)planetologyNode.cenX - 32, (float)planetologyNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        roboticsNode.DrawIcon(render, "RoboticsIcon", { (float)roboticsNode.cenX - 32, (float)roboticsNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        engineeringNode.DrawIcon(render, "EngineeringIcon", { (float)engineeringNode.cenX - 32, (float)engineeringNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        cyberneticsNode.DrawIcon(render, "CyberneticsIcon", { (float)cyberneticsNode.cenX - 32, (float)cyberneticsNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        artificialIntelligenceNode.DrawIcon(render, "ArtificialIntelligenceIcon", { (float)artificialIntelligenceNode.cenX - 32, (float)artificialIntelligenceNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        hyperspaceNode.DrawIcon(render, "HyperspaceIcon", { (float)hyperspaceNode.cenX - 32, (float)hyperspaceNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        xenoesotericismNode.DrawIcon(render, "XenoesotericismIcon", { (float)xenoesotericismNode.cenX - 32, (float)xenoesotericismNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);
        commandNode.DrawIcon(render, "CommandIcon", { (float)commandNode.cenX - 32, (float)commandNode.cenY + 20 }, 0.f, 1.0f, skillTreeIconOpacity, skillTreeExpertColor);

        hasNodeBeenClicked = false;
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

    statsConfirmButton = UIButton(
        "Confirm Allocation",
        render.TextScreenCenterX(render.GridX(6) + 20),
        render.GridY(14),
        render.GridX(6)+20,
        120,
        TextAlign::Center,
        TextSize::MenuSmall
    );

    scientistBuffStrengthButton = UIButton(
        "Strength",
        render.GridX(6),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

    scientistBuffSpeedButton = UIButton(
        "Speed",
        render.GridX(9),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

    scientistBuffIntellectButton = UIButton(
        "Intellect",
        render.GridX(12),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

    scientistBuffCombatButton = UIButton(
        "Combat",
        render.GridX(15),
        render.GridY(9),
        render.GridX(3) - 10,
        120,
        TextAlign::Center,
        TextSize::Button02
    );

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
        render.GridY(6)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementSpeedButton = UIButton(
        "-",
        render.GridX(7),
        render.GridY(8)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementIntellectButton = UIButton(
        "-",
        render.GridX(7),
        render.GridY(10)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementCombatButton = UIButton(
        "-",
        render.GridX(7),
        render.GridY(12)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementStrengthButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(6)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementSpeedButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(8)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementIntellectButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(10)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementCombatButton = UIButton(
        "+",
        render.GridX(9),
        render.GridY(12)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementSanityButton = UIButton(
        "-",
        render.GridX(18),
        render.GridY(7)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementFearButton = UIButton(
        "-",
        render.GridX(18),
        render.GridY(9)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    decrementBodyButton = UIButton(
        "-",
        render.GridX(18),
        render.GridY(11)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementSanityButton = UIButton(
        "+",
        render.GridX(20),
        render.GridY(7)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementFearButton = UIButton(
        "+",
        render.GridX(20),
        render.GridY(9)+10,
        100, 120,
        TextAlign::Center,
        TextSize::Button02
    );

    incrementBodyButton = UIButton(
        "+",
        render.GridX(20),
        render.GridY(11)+10,
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

    areStatsCopied = false;

    drawDebugGrid = false;

    scientistDecisionRequired = false;
    androidDecisionRequired = false;

    isStrengthIncreased = false;
    isSpeedIncreased = false;
    isIntellectIncreased = false;
    isCombatIncreased = false;

    isStrengthDecreased = false;
    isSpeedDecreased = false;
    isIntellectDecreased = false;
    isCombatDecreased = false;

    addedToStrength = 0;
    addedToSpeed = 0;
    addedToIntellect = 0;
    addedToCombat = 0;

    addedToSanity = 0;
    addedToFear = 0;
    addedToBody = 0;

    availableStatPoints = 8;
    availableSavePoints = 4;

    // Reset button colours too
    nextButtonColor = LIGHTGRAY;
    previousButtonColor = LIGHTGRAY;
    mainMenuButtonColor = LIGHTGRAY;
    selectClassButtonColor = LIGHTGRAY;
    loadout01ButtonColor = LIGHTGRAY;
    loadout02ButtonColor = LIGHTGRAY;
    loadout03ButtonColor = LIGHTGRAY;
    loadout04ButtonColor = LIGHTGRAY;

    for (auto n : allNodes)
    {
        n->nodeAvailability = NodeAvailability::AVAILABLE;
    }
}

