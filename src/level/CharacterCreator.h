#pragma once
#include <string>
#include "../ui/UIButton.h"
#include "../ui/SkillTreeNode.h" 
#include "../player/Marine.h"
#include "../player/Scientist.h"
#include "../player/Teamster.h"
#include "../player/Android.h"
#include "../player/BaseClass.h"
#include "../core/IGameState.h"
#include "raylib.h" 


class Renderer;
class StateManager;
class TextureManager;

enum class CharacterSelect {
    Marine = 0,
    Scientist,
    Teamster,
    Android,
    Count // not a real option, just to track how many
};

enum class Page {
    CLASS_SELECT,
    LOADOUT_SELECT,
    STATS_SELECT,
    SKILLS_SELECT
};

class CharacterCreator : public IGameState {
public:
    CharacterCreator(StateManager& sm, TextureManager& tm, Renderer& render);

    void InitButtons();
    void Update(float dt) override;
    void Draw(Renderer& render) override;
    void HandleInput() override;
    CharacterSelect GetCurrentCharacter() const { return currentCharacter; }
    Page GetCurrentPage() const { return currentPage; }
    Marine marine;
    Scientist scientist;
    Android android;
    Teamster teamster;


private:
    Renderer& render;
    StateManager& stateManager;
    TextureManager& textureManager;

    CharacterSelect currentCharacter = CharacterSelect::Marine;
    Page currentPage = Page::CLASS_SELECT;

    void NextCharacter();
    void PreviousCharacter();

    void Reset();

    bool pendingDebugGrid = false;
    bool pendingMainMenu = false;
    bool drawDebugGrid{ false };
    bool shouldDraw{ true }; 
    bool androidDecisionRequired{ false };
    bool scientistDecisionRequired{ false };
    bool isAllocated{ false };
    bool areStatsCopied{ false }; 

    bool isStrengthIncreased = false;
    bool isSpeedIncreased = false;
    bool isIntellectIncreased = false;
    bool isCombatIncreased = false;

    bool isStrengthDecreased = false;
    bool isSpeedDecreased = false;
    bool isIntellectDecreased = false;
    bool isCombatDecreased = false;



    int availableStatPoints = 8;
    int availableSavePoints = 4;

    // stat copies
    int strengthCopy{};
    int speedCopy{};
    int intellectCopy{};
    int combatCopy{};

    // save copies
    int sanityCopy{};
    int fearCopy{};
    int bodyCopy{};

    int addedToStrength = 0;
    int addedToSpeed = 0;
    int addedToIntellect = 0;
    int addedToCombat = 0;

    int addedToSanity = 0;
    int addedToFear = 0;
    int addedToBody = 0;

    int testInt = 10;

    std::string marineInfo = marine.GetClassBio();
    std::string scientistInfo = scientist.GetClassBio();
    std::string androidInfo = android.GetClassBio();
    std::string teamsterInfo = teamster.GetClassBio();
    std::string className;

    DebugRect SelectClassAlignmentRect01;
    DebugRect SelectClassAlignmentRect02;
    DebugRect SelectClassAlignmentRect03;
    DebugRect SelectClassAlignmentRect04;
    DebugRect SelectClassAlignmentRect05;
    DebugRect LoadoutSelectAlignmentRect01;
    DebugRect LoadoutSelectAlignmentRect02;
    DebugRect SkillTreeAlignmentRect01;

    // buttons
    UIButton decrementStrengthButton;
    Color decrementStrengthButtonColor = GRAY;
    UIButton decrementSpeedButton;
    Color decrementSpeedButtonColor = GRAY;
    UIButton decrementIntellectButton;
    Color decrementIntellectButtonColor = GRAY;
    UIButton decrementCombatButton;
    Color decrementCombatButtonColor = GRAY;
    UIButton incrementStrengthButton;
    Color incrementStrengthButtonColor = GRAY;
    UIButton incrementSpeedButton;
    Color incrementSpeedButtonColor = GRAY;
    UIButton incrementIntellectButton;
    Color incrementIntellectButtonColor = GRAY;
    UIButton incrementCombatButton;
    Color incrementCombatButtonColor = GRAY;

    UIButton decrementSanityButton;
    Color decrementSanityButtonColor = GRAY;
    UIButton decrementFearButton;
    Color decrementFearButtonColor = GRAY;
    UIButton decrementBodyButton;
    Color decrementBodyButtonColor = GRAY;
    UIButton incrementSanityButton;
    Color incrementSanityButtonColor = GRAY;
    UIButton incrementFearButton;
    Color incrementFearButtonColor = GRAY;
    UIButton incrementBodyButton;
    Color incrementBodyButtonColor = GRAY;

    UIButton nextButton;
    Color nextButtonColor = LIGHTGRAY;
    UIButton previousButton;
    Color previousButtonColor = LIGHTGRAY;
    UIButton mainMenuButton;
    Color mainMenuButtonColor = LIGHTGRAY;
    UIButton selectClassButton;
    Color selectClassButtonColor = LIGHTGRAY;
    UIButton loadout01Button;
    Color loadout01ButtonColor = LIGHTGRAY;
    UIButton loadout02Button;
    Color loadout02ButtonColor = LIGHTGRAY;
    UIButton loadout03Button;
    Color loadout03ButtonColor = LIGHTGRAY;
    UIButton loadout04Button;
    Color loadout04ButtonColor = LIGHTGRAY;

    UIButton androidHandicapStrengthButton;
    Color androidHandicapStrengthButtonColor = GRAY;
    UIButton androidHandicapSpeedButton;
    Color androidHandicapSpeedButtonColor = GRAY;
    UIButton androidHandicapIntellectButton;
    Color androidHandicapIntellectButtonColor = GRAY;
    UIButton androidHandicapCombatButton;
    Color androidHandicapCombatButtonColor = GRAY;

    UIButton scientistBuffStrengthButton;
    Color scientistBuffStrengthButtonColor = GRAY;
    UIButton scientistBuffSpeedButton;
    Color scientistBuffSpeedButtonColor = GRAY;
    UIButton scientistBuffIntellectButton;
    Color scientistBuffIntellectButtonColor = GRAY;
    UIButton scientistBuffCombatButton;
    Color scientistBuffCombatButtonColor = GRAY;

    UIButton statsConfirmButton;
    Color statsConfirmButtonColor = LIGHTGRAY;

    //test node
    SkillTreeNode testNode;

    //trained skill nodes 
    SkillTreeNode linguisticsNode;
    Color linguisticsNodeColor = DARKBLUE; 
    SkillTreeNode zoologyNode;
    Color zoologyNodeColor = DARKBLUE;
    SkillTreeNode botanyNode;
    Color botanyNodeColor = DARKBLUE;
    SkillTreeNode geologyNode;
    Color geologyNodeColor = DARKBLUE;
    SkillTreeNode industrialEquipmentNode;
    Color industrialodeColor = DARKBLUE;
    SkillTreeNode juryRiggingNode;
    Color juryRiggingNodeColor = DARKBLUE;
    SkillTreeNode chemistryNode;
    Color chemistryNodeColor = DARKBLUE;
    SkillTreeNode computersNode;
    Color computersNodeColor = DARKBLUE;
    SkillTreeNode zeroGNode;
    Color zeroGNodeColor = DARKBLUE;
    SkillTreeNode mathematicsNode;
    Color mathematicsNodeColor = DARKBLUE;
    SkillTreeNode artNode;
    Color artNodeColor = DARKBLUE;
    SkillTreeNode archeologyNode;
    Color archeologyNodeColor = DARKBLUE;
    SkillTreeNode theologyNode;
    Color theologyNodeColor = DARKBLUE;
    SkillTreeNode militaryTrainingNode;
    Color militaryTrainingNodeColor = DARKBLUE;
    SkillTreeNode rimwiseNode;
    Color rimwiseNodeColor = DARKBLUE;
    SkillTreeNode athleticsNode;
    Color athleticsNodeColor = DARKBLUE;

    //expert skill nodes
    SkillTreeNode psychologyNode;
    Color psychologyNodeColor = DARKBLUE;
    SkillTreeNode pathologyNode;
    Color pathologyNodeColor = DARKBLUE;
    SkillTreeNode fieldMedicineNode;
    Color fieldMedicineNodeColor = DARKBLUE;
    SkillTreeNode ecologyNode;
    Color ecologyNodeColor = DARKBLUE;
    SkillTreeNode asteroidMiningNode;
    Color asteroidMiningNodeColor = DARKBLUE;
    SkillTreeNode mechanicalRepairNode;
    Color mechanicalRepairNodeColor = DARKBLUE;
    SkillTreeNode explosivesNode;
    Color explosivesNodeColor = DARKBLUE;
    SkillTreeNode pharmacologyNode;
    Color pharmacologyNodeColor = DARKBLUE;
    SkillTreeNode hackingNode;
    Color hackingNodeColor = DARKBLUE;
    SkillTreeNode pilotingNode;
    Color pilotingNodeColor = DARKBLUE;
    SkillTreeNode physicsNode;
    Color physicsNodeColor = DARKBLUE;
    SkillTreeNode mysticismNode;
    Color mysticismNodeColor = DARKBLUE;
    SkillTreeNode wildernessSurvivalNode;
    Color wildernessSurvivalNodeColor = DARKBLUE;
    SkillTreeNode fireArmsNode;
    Color fireArmsNodeColor = DARKBLUE;
    SkillTreeNode handToHandCombatNode;
    Color handToHandCombatNodeColor = DARKBLUE;

    //master skill nodes
    SkillTreeNode sophontologyNode;
    Color sophontologyNodeColor = DARKBLUE;
    SkillTreeNode exobiologyNode;
    Color exobiologyNodeColor = DARKBLUE;
    SkillTreeNode surgeryNode;
    Color surgeryNodeColor = DARKBLUE;
    SkillTreeNode planetologyNode;
    Color planetologyNodeColor = DARKBLUE;
    SkillTreeNode roboticsNode;
    Color roboticsNodeColor = DARKBLUE;
    SkillTreeNode engineeringNode;
    Color engineeringNodeColor = DARKBLUE;
    SkillTreeNode cyberneticsNode;
    Color cyberneticsNodeColor = DARKBLUE;
    SkillTreeNode artificialIntelligenceNode;
    Color artificialIntelligenceNodeColor = DARKBLUE;
    SkillTreeNode hyperspaceNode;
    Color hyperspaceNodeColor = DARKBLUE;
    SkillTreeNode xenoesotericismNode;
    Color xenoesotericismNodeColor = DARKBLUE;
    SkillTreeNode commandNode;
    Color commandNodeColor = DARKBLUE;




};  
