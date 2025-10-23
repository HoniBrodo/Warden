#pragma once
#include <string>
#include <vector>
#include "BaseSkill.h"
#include "BaseEquipment.h"
#include "raylib.h"

class BaseClass {
public:
    BaseClass(const std::string& name);
    virtual ~BaseClass();

    // accessors
    std::string GetClassBio() const { return classBio; }
    std::string GetName() const { return name; }
    int GetStrength() const { return strength; }
    int GetSpeed() const { return speed; }
    int GetIntellect() const { return intellect; }
    int GetCombat() const { return combat; }
    int GetSanity() const { return sanity; }
    int GetFear() const { return fear; }
    int GetBody() const { return body; }
    int GetHealth() const { return health; }
    int GetWounds() const { return wounds; }
    int GetStress() const { return stress; }
    virtual std::vector<std::string> GetLoadout(int loadoutNumber);
    virtual std::vector<std::string> GetMechanics() const { return classMechanics; }

    // actions 
    virtual void IncreaseStrength(int amount);
    virtual void DecreaseStrength(int amount);
    virtual void IncreaseSpeed(int amount);
    virtual void DecreaseSpeed(int amount);
    virtual void IncreaseIntellect(int amount);
    virtual void DecreaseIntellect(int amount);
    virtual void IncreaseCombat(int amount);
    virtual void DecreaseCombat(int amount);
    virtual void IncreaseSanity(int amount);
    virtual void DecreaseSanity(int amount);
    virtual void IncreaseFear(int amount);
    virtual void DecreaseFear(int amount);
    virtual void IncreaseBody(int amount);
    virtual void DecreaseBody(int amount);



    virtual void TakeDamage(int amount);
    virtual void Heal(int amount);
    virtual void IncreaseStress(int amount);
    virtual void ReduceStress(int amount);

protected:

    std::string name;

    // bio
    std::string classBio{};
    std::vector<std::string> classMechanics;

    // stats
    int strength{ 36 };
    int speed{ 36 };
    int intellect{ 36 };
    int combat{ 36 };

    // saves
    int sanity{ 21 };
    int fear{ 21 };
    int body{ 21 };

    int maxHealth{ 16 };
    int health{ 16 };
    int maxWounds{ 2 };
    int wounds{ 0 };
    int stress{ 2 };

    // Inventory + skills
    std::vector<BaseSkill> skills; // skill objects derived from the base skill class
    std::vector<BaseEquipment> equipment; // equipment objects derived from the base equipment class
    int credits{};

    std::vector<std::string> loadout01Items;
    std::vector<std::string> loadout02Items;
    std::vector<std::string> loadout03Items;
    std::vector<std::string> loadout04Items;

};