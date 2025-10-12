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
    int Getfear() const { return fear; }
    int GetBody() const { return body; }
    int GetHealth() const { return health; }
    int GetWounds() const { return wounds; }
    int GetStress() const { return stress; }
    virtual std::vector<std::string> GetLoadout(int loadoutNumber);

    // actions 
    virtual void IncreaseStrength(int amount);
    virtual void DecreaseStrength(int amount);
    virtual void IncreaseSpeed(int amount);
    virtual void DecreaseSpeed(int amount);
    virtual void IncreaseIntellect(int amount);
    virtual void DecreaseIntellect(int amount);
    virtual void IncreaseCombat(int amount);
    virtual void DecreaseCombat(int amount);
    virtual void TakeDamage(int amount);
    virtual void Heal(int amount);
    virtual void IncreaseStress(int amount);
    virtual void ReduceStress(int amount);

protected:

    std::string name;

    // bio
    std::string classBio{};

    // stats
    int strength{};
    int speed{};
    int intellect{};
    int combat{};

    // saves
    int sanity{};
    int fear{};
    int body{};

    int health{};
    int wounds{};
    int stress{};

    // Inventory + skills
    std::vector<BaseSkill> skills; // skill objects derived from the base skill class
    std::vector<BaseEquipment> equipment; // equipment objects derived from the base equipment class
    int credits{};

    std::vector<std::string> loadout01Items;
    std::vector<std::string> loadout02Items;
    std::vector<std::string> loadout03Items;
    std::vector<std::string> loadout04Items;

};