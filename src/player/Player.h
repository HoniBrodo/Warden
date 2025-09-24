#pragma once
#include <memory>
#include <string>
#include "BaseClass.h"

class Player {
public:
    // construct with a concrete derived BaseClass (Marine, Scientist, etc)
    explicit Player(std::unique_ptr<BaseClass> characterClass);
    ~Player();

    // forward useful accessors to the owned class
    std::string GetClassBio() const { return characterClass_->GetClassBio(); }
    std::string GetName() const { return characterClass_->GetName(); }
    int GetStrength() const { return characterClass_->GetStrength(); }
    int GetSpeed() const { return characterClass_->GetSpeed(); }
    int GetIntellect() const { return characterClass_->GetIntellect(); }
    int GetCombat() const { return characterClass_->GetCombat(); }
    int GetSanity() const { return characterClass_->GetSanity(); }
    int Getfear() const { return characterClass_->Getfear(); }
    int GetBody() const { return characterClass_->GetBody(); }
    int GetHealth() const { return characterClass_->GetHealth(); }
    int GetWounds() const { return characterClass_->GetWounds(); }
    int GetStress() const { return characterClass_->GetStress(); }



    // gameplay actions - these will dispatch to the derived class implementation
    void TakeDamage(int amount) { characterClass_->TakeDamage(amount); }
    void Heal(int amount) { characterClass_->Heal(amount); }
    void IncreaseStress(int amount) { characterClass_->IncreaseStress(amount); }
    void ReduceStress(int amount) { characterClass_->ReduceStress(amount); }

    // Expose the underlying BaseClass if you need to call custom methods:
    BaseClass& GetClass() { return *characterClass_; }

private:
    std::unique_ptr<BaseClass> characterClass_;
};
