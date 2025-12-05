#pragma once
#include <string>
#include <vector>
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
    Color linguisticsNodeColor = GRAY; 
    SkillTreeNode zoologyNode;
    Color zoologyNodeColor = GRAY;
    SkillTreeNode botanyNode;
    Color botanyNodeColor = GRAY;
    SkillTreeNode geologyNode;
    Color geologyNodeColor = GRAY;
    SkillTreeNode industrialEquipmentNode;
    Color industrialodeColor = GRAY;
    SkillTreeNode juryRiggingNode;
    Color juryRiggingNodeColor = GRAY;
    SkillTreeNode chemistryNode;
    Color chemistryNodeColor = GRAY;
    SkillTreeNode computersNode;
    Color computersNodeColor = GRAY;
    SkillTreeNode zeroGNode;
    Color zeroGNodeColor = GRAY;
    SkillTreeNode mathematicsNode;
    Color mathematicsNodeColor = GRAY;
    SkillTreeNode artNode;
    Color artNodeColor = GRAY;
    SkillTreeNode archeologyNode;
    Color archeologyNodeColor = GRAY;
    SkillTreeNode theologyNode;
    Color theologyNodeColor = GRAY;
    SkillTreeNode militaryTrainingNode;
    Color militaryTrainingNodeColor = GRAY;
    SkillTreeNode rimwiseNode;
    Color rimwiseNodeColor = GRAY;
    SkillTreeNode athleticsNode;
    Color athleticsNodeColor = GRAY;

    //expert skill nodes
    SkillTreeNode psychologyNode;
    Color psychologyNodeColor = GRAY;
    SkillTreeNode pathologyNode;
    Color pathologyNodeColor = GRAY;
    SkillTreeNode fieldMedicineNode;
    Color fieldMedicineNodeColor = GRAY;
    SkillTreeNode ecologyNode;
    Color ecologyNodeColor = GRAY;
    SkillTreeNode asteroidMiningNode;
    Color asteroidMiningNodeColor = GRAY;
    SkillTreeNode mechanicalRepairNode;
    Color mechanicalRepairNodeColor = GRAY;
    SkillTreeNode explosivesNode;
    Color explosivesNodeColor = GRAY;
    SkillTreeNode pharmacologyNode;
    Color pharmacologyNodeColor = GRAY;
    SkillTreeNode hackingNode;
    Color hackingNodeColor = GRAY;
    SkillTreeNode pilotingNode;
    Color pilotingNodeColor = GRAY;
    SkillTreeNode physicsNode;
    Color physicsNodeColor = GRAY;
    SkillTreeNode mysticismNode;
    Color mysticismNodeColor = GRAY;
    SkillTreeNode wildernessSurvivalNode;
    Color wildernessSurvivalNodeColor = GRAY;
    SkillTreeNode fireArmsNode;
    Color fireArmsNodeColor = GRAY;
    SkillTreeNode handToHandCombatNode;
    Color handToHandCombatNodeColor = GRAY;

    //master skill nodes
    SkillTreeNode sophontologyNode;
    Color sophontologyNodeColor = GRAY;
    SkillTreeNode exobiologyNode;
    Color exobiologyNodeColor = GRAY;
    SkillTreeNode surgeryNode;
    Color surgeryNodeColor = GRAY;
    SkillTreeNode planetologyNode;
    Color planetologyNodeColor = GRAY;
    SkillTreeNode roboticsNode;
    Color roboticsNodeColor = GRAY;
    SkillTreeNode engineeringNode;
    Color engineeringNodeColor = GRAY;
    SkillTreeNode cyberneticsNode;
    Color cyberneticsNodeColor = GRAY;
    SkillTreeNode artificialIntelligenceNode;
    Color artificialIntelligenceNodeColor = GRAY;
    SkillTreeNode hyperspaceNode;
    Color hyperspaceNodeColor = GRAY;
    SkillTreeNode xenoesotericismNode;
    Color xenoesotericismNodeColor = GRAY;
    SkillTreeNode commandNode;
    Color commandNodeColor = GRAY;

    std::vector<SkillTreeNode* > allNodes{};

    // skill tree icon colors
    Color skillTreeTrainedColor = SKYBLUE;
    Color skillTreeMasterColor = ORANGE;
    Color skillTreeExpertColor = MAGENTA;
    Color skillTreeIconOpacity = WHITE;



};  
