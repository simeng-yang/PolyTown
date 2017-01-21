#ifndef HUMANOIDS_H
#define HUMANOIDS_H

#include "Human.h"

class Vampire : public Human{
public:
    Vampire (std::string name);
    std::string DefaultSpeech();
    ~Vampire();
};

class Nobbs : public Human{
public:
    Nobbs (std::string name);
    std::string DefaultSpeech();
    ~Nobbs();
};

class Zombie: public Human{
public:
    Zombie(std::string name);
    std::string DefaultSpeech();
    ~Zombie();
};

#endif // HUMANOIDS_H
