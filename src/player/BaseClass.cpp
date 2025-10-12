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
