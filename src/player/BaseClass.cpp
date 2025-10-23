#include "BaseClass.h"

BaseClass::BaseClass(const std::string& name) : name(name) {}

BaseClass::~BaseClass() {}

std::vector<std::string> BaseClass::GetLoadout(int loadoutNumber)
{
    switch (loadoutNumber)
    {
    case 1:
        return loadout01Items;
        break;
    case 2:
        return loadout02Items;
        break;
    case 3:
        return loadout03Items;
        break;
    case 4:
        return loadout04Items;
        break;
    }
}

void BaseClass::IncreaseStrength(int amount)
{
    strength += amount;
}

void BaseClass::DecreaseStrength(int amount)
{
    strength -= amount;
}

void BaseClass::IncreaseSpeed(int amount)
{
    speed += amount;
}

void BaseClass::DecreaseSpeed(int amount)
{
    speed -= amount;
}

void BaseClass::IncreaseIntellect(int amount)
{
    intellect += amount;
}

void BaseClass::DecreaseIntellect(int amount)
{
    intellect -= amount;
}

void BaseClass::IncreaseCombat(int amount)
{
    combat += amount;
}

void BaseClass::DecreaseCombat(int amount)
{
    combat -= amount;
}

void BaseClass::IncreaseSanity(int amount)
{
    sanity += amount;
}

void BaseClass::DecreaseSanity(int amount)
{
    sanity -= amount;
}

void BaseClass::IncreaseFear(int amount)
{
    fear += amount;
}

void BaseClass::DecreaseFear(int amount)
{
    fear -= amount;
}

void BaseClass::IncreaseBody(int amount)
{
    body += amount;
}

void BaseClass::DecreaseBody(int amount)
{
    body -= amount;
}

void BaseClass::SetDefaults()
{
    defaultStrength = strength;
    defaultSpeed = speed;
    defaultIntellect = intellect;
    defaultCombat = combat;
    defsultSanity = sanity;
    defaultFear = fear;
    defaultBody = body;
}

void BaseClass::ResetDefaults()
{
    strength = defaultStrength;
    speed = defaultSpeed;
    intellect = defaultIntellect;
    combat = defaultCombat;
    sanity = defsultSanity;
    fear = defaultFear;
    body = defaultBody;
}

void BaseClass::TakeDamage(int amount)
{
}

void BaseClass::Heal(int amount)
{
}

void BaseClass::IncreaseStress(int amount)
{
}

void BaseClass::ReduceStress(int amount)
{
}
