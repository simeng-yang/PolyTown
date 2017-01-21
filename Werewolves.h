#ifndef WEREWOLVES_H
#define WEREWOLVES_H

#include "Wolves.h"
#include "Human.h"

class Werewolf : public Human, public Wolf
{
public:
    Werewolf(std::string name, std::string furColour, std::string classChar);
    std::string DefaultSpeech();
    virtual void Howl();
    virtual void Growl();
    void ChangeForm();
    ~Werewolf();
};

#endif // WEREWOLVES_H
