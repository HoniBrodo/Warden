#include "Scientist.h"

Scientist::Scientist() : BaseClass("Scientist") {

    classBio = "The Scientist is highly intelligent and resourceful, capable of analyzing complex problems and discovering solutions under pressure. While physically weaker and less skilled in combat, their expertise in research, medicine, and engineering makes them invaluable in uncovering mysteries and supporting the crew.";
   
    loadout01Items = { "Hazard Suit(AP 5)", "Tranq Pistol(3 shots)","Bioscanner", "Sample Collection Kit" };
    loadout02Items = {  };
    loadout03Items = {  };
    loadout04Items = {  };
}
