#include "Others.h"

//Troll constructor
Troll::Troll(std::string name)
    :Citizen(name, "TROLL", "DEGENERATE", "GEM" ,"TROLLS", "GEMS"){
}

//Makes troll default speech
std::string Troll::DefaultSpeech(){
    switch (rand()%3){
        case 0:
            return "My father was an architect";
            break;
        case 1:
            return "My mother was an engineer";
            break;
        case 2:
            return "Woe is my fate in this dismal world";
            break;
    }
}

//Troll destructor
Troll::~Troll(){

}

//Dwarf constructor
Dwarf::Dwarf(std::string name)
    :Citizen(name, "DWARF", "GIANT", "GOLD", "DWARVES", "GOLD"){
}

//Makes dwarf default speech
std::string Dwarf::DefaultSpeech(){
    switch (rand()%3){
        case 0:
            return "I was always born short, don't judge me.";
            break;
        case 1:
            return "Anything over this height is not a dwarf (Points to self)";
            break;
        case 2:
            return "I've never seen over that hill in my life.";
            break;
    }
}

//Dwarf destructor
Dwarf::~Dwarf(){

}
