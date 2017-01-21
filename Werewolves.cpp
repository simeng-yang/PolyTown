#include "Werewolves.h"

//Werewolf constructor
Werewolf::Werewolf(std::string name, std::string furColour, std::string classChar)
    :Human(name, "WEREWOLF", "TRANSMUTABLE"), Wolf(name, furColour, "WEREWOLF"){
}

//Makes the werewolf howl
void Werewolf::Howl(){
    Say("AWHOOOOAWHOOOOOO!");
}

//Makes the werewolf growl
void Werewolf::Growl(){
    Say("FEEAAAARRRR MEEEEE!");
}

//Makes werewolf speak "normally"
std::string Werewolf::DefaultSpeech(){
        return Human::DefaultSpeech();
}

//Werewolf destructor
Werewolf::~Werewolf(){

}
