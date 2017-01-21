#include "Human.h"

//Human constructor
Human::Human(std::string name, std::string className, std::string classChar, std::string classNamePlural)
    :Citizen(name, className, classChar, "DOLLAR", classNamePlural, "DOLLARS"){
}

//Human default speech
std::string Human::DefaultSpeech(){
    switch (rand()%3){
        case 0:
            return "There are just five regular polyhedra.";
        case 1:
            return "In dimensions > 4, there are only 3 regular n-polytopes.";
        case 2:
            return "Are there infinitely many pairs of twin primes?";
    }
}

//Human destructor
Human::~Human(){}
