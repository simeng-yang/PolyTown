#include "Humanoids.h"

//Vampire constructor
Vampire::Vampire(std::string name)
    :Human(name, "VAMPIRE", "BLOODSUCKING",  "VAMPIRES"){
}

//Makes default speech for vampire
std::string Vampire::DefaultSpeech(){
    switch (rand()%3){
        case 0:
            return "Vlad the Impaler was too gentle.";
            break;
        case 1:
            return "The sun is the destroyer of life, not the creator.";
            break;
        case 2:
            return "You mortals suffer the plight of fools.";
            break;
    }
}

//Vampire destructor
Vampire::~Vampire(){}

//Nobbs constructor
Nobbs::Nobbs(std::string name)
    :Human(name, "NOBBS", "UNKNOWN",  "NOBBS"){
}

//Makes default speech for Nobbs
std::string Nobbs::DefaultSpeech(){
    switch (rand()%3){
        case 0:
            return "What is a Nobb?";
            break;
        case 1:
            return "Excuse me while I disappear.";
            break;
        case 2:
            return "What is the question to my answer?";
            break;
    }
}

//Nobbs destructor
Nobbs::~Nobbs(){}

//Zombie constructor
Zombie::Zombie(std::string name)
    :Human(name, "ZOMBIE", "UNDEAD",  "ZOMBIES"){

}

//Makes zombie default speech
std::string Zombie::DefaultSpeech(){
    switch (rand()%3){
        case 0:
            return "*Tearing*";
            break;
        case 1:
            return "*Crumbling to dust*";
            break;
        case 2:
            return "*Awkward silence*";
            break;
    }
}

//Zombie destructor
Zombie::~Zombie(){}
