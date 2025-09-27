#include "Marine.h"

Marine::Marine() : BaseClass("Marine") {

    classBio = "Trained for combat in the harshest conditions, the Marine is a soldier bred for survival. Years of drills, deployments, and firefights have hardened them into a relentless fighter who can push through fear and pain where others would break.";
    strength = 60;
    speed = 40;
    intellect = 30;
    combat = 70;
    sanity = 30;
    fear = 40;
    body = 50;
    health = 100;
    wounds = 0;
    stress = 0;
    credits = 100;

    loadout01Items = { "Pistol", "Medkit", "Rations", "Flashlight" };
    loadout02Items = { "Shotgun", "Ammo x20", "Grenade" };
    loadout03Items = { "Rifle", "Body Armor", "Combat Knife" };
    loadout04Items = { "SMG", "Smoke Grenade", "Rations" };
}
