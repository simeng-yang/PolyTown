#ifndef WOLVES_H
#define WOLVES_H

#include <iostream>
#include "Citizen.h"
#include <vector>
#include <algorithm> //vector erase method

class Wolf{
protected:
    std::string name;
    std::string furColour;
    std::string className;
    std::string classChar;

public:
    Wolf(std::string name, std::string furColour, std::string className = "WOLF", std::string classChar = "HAIRY");
    virtual void Howl();
    virtual void Growl();
    std::string GetName(){
        return name;
    }
    std::string GetFurColour(){
        return furColour;
    }
    std::string GetClass(){
        return className;
    }

    bool CauseDamage(Citizen &c, std::vector<Citizen*> &base, std::vector<Citizen*> &casualties);

    virtual ~Wolf();
};

#endif // WOLVES_H
