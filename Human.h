#ifndef HUMAN_H
#define HUMAN_H

#include "Citizen.h"

class Human : public Citizen{
public:
    //Human constructor
    Human (std::string name, std::string className = "HUMAN", std::string classChar = "EVOLVED",
            std::string classNamePlural = "HUMANS");
    //Default speech, can be passed down to human child classes
    virtual std::string DefaultSpeech ();
    //Human and subclass destructor
    virtual ~Human();
};

#endif // HUMAN_H
