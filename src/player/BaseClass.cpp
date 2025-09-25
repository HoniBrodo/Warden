#include "BaseClass.h"

BaseClass::BaseClass(const std::string& name) : name(name) {}

BaseClass::~BaseClass() {}

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
