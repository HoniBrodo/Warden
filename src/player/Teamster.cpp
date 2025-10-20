#include "Teamster.h"

Teamster::Teamster() : BaseClass("Teamster") {

    // stats
    strength = 41;
    speed = 41;
    intellect = 41;
    combat = 41;

    // saves
    sanity = 31;
    fear = 31;
    body = 31;

    classMechanics = { "+5 to all stats", "+10 to all saves"};

    classBio = "The backbone of any mission, the Teamster is a hardened labourer whos seen it all; long hauls through deep space, busted equipment in zero G, and bosses who never cared if they lived or died. Used to pulling double shifts and keeping crews together, the Teamster has grit in spades.";

    loadout01Items = { "Vaccsuit (AP 3)", "Revolver (6 rounds)", "Crowbar", "Flashlight"};
    loadout02Items = { "Heavy Duty Work Clothes (AP 2)", "Explosives & Detonator", "Cigarettes" };
    loadout03Items = { "Standard Crew Attire (AP 1)", "Nail Gun (32 rounds)", "HeadLamp", "Toolbelt with Assorted Tools" };
    loadout04Items = { "Heavy Duty Work Clothes (AP 2)", "Drill (as Assorted Tools)", "Paracord (100m)", "Salvage Drone" };
}



