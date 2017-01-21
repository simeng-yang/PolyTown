#ifndef OTHERS_H
#define OTHERS_H

#include "Citizen.h"

class Troll : public Citizen{
public:
    Troll(std::string name);
    std::string DefaultSpeech();
    ~Troll();
};

class Dwarf : public Citizen {
private:

public:
    Dwarf(std::string name);
    std::string DefaultSpeech();
    ~Dwarf();
};

#endif // OTHERS_H
