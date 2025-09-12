#pragma once
#include <string>
#include <vector>
#include "raylib.h"

class BaseClass {
public:
    BaseClass(const std::string& name);
    virtual ~BaseClass();

protected:

    std::string name;

    // stats
    int strength;
    int speed;
    int intellect;
    int combat;

    // saves
    int sanity;
    int fear;
    int body;

    int health;
    int wounds;
    int stress;

    // Inventory + skills
    std::vector<std::string> skills; // replace string with skills class objects
    std::vector<std::string> equipment; // replace string with equipment class objects
    int credits;

};