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

    loadout01Items = { "Advanced Battle Dress (AP 10)", "Flamethrower (4 shots)", "Boarding Axe"};
    loadout02Items = { "Standard Battle Dress (AP 7)", "Pulse Rifle (3 mags)", "Infrared Goggles" };
    loadout03Items = { "Standard Battle Dress (AP 7)", "Smart Rifle (3 mags)", "Binoculars", "Personal Locator"};
    loadout04Items = { "Advanced Battle Dress (AP 10)", "General Purpose Machine Gun (1 can of ammo)", "HUD" };
}
