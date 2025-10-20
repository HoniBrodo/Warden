#include "Scientist.h"

Scientist::Scientist() : BaseClass("Scientist") {

    intellect = 46;
    sanity = 51;

    classBio = "The Scientist is highly intelligent and resourceful, capable of analyzing complex problems and discovering solutions under pressure. While physically weaker and less skilled in combat, their expertise in research, medicine, and engineering makes them invaluable in uncovering mysteries and supporting the crew.";
   
    classMechanics = { "+10 to Intellect", "+5 to any 1 stat", "+30 to Sanity Save"};

    loadout01Items = { "Hazard Suit (AP 5)", "Tranq Pistol (3 shots)","Bioscanner", "Sample Collection Kit" };
    loadout02Items = { "Vaccsuit (AP 3)", "Foam Gun (2 charges)", "Foldable Stretcher", "First Aid Kit", "Radiation Pills (x5)" };
    loadout03Items = { "Hazard Suit(AP 5)", "Flamethrower(1 charge)", "Stimpak", "Electronic Tool Set" };
    loadout04Items = { "Lab Coat (AP 1)", "Cybernetic Diagnostic Scanner", "Portable Computer Terminal" };
}
