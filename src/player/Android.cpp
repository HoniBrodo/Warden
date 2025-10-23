#include "Android.h"

Android::Android() : BaseClass("Android") {

    intellect = 56;
    fear = 81;
    maxWounds = 3;

    classBio = "Engineered rather than born, the Android is a marvel of synthetic design. Programmed with logic far beyond human capacity and equipped with reinforced servos, it excels in both precision tasks and high - risk environments. Free from fear and fatigue, the Android operates where others falter.";

    classMechanics = { "+20 to intellect", "-10 to any 1 stat", "+60 to Fear Save", "+1 Max Wounds" };

    loadout01Items = { "Vaccsuit (AP 3)", "Smart Rifle(2 mags)", "Infrared Goggles", "Mylar Blanket" };
    loadout02Items = { "Standard Crew Attire (AP 1)", "Scalpel", "Bioscanner" };
    loadout03Items = { "Hazard Suit (AP 5)", "Revolver(6 rounds)", "Defibrillator", "First Aid Kit", "Flashlight" };
    loadout04Items = { "Hazard Suit (AP 5)", "Foam Gun(2 charges)", "Sample Collection Kit", "Screwdriver" };

}





 