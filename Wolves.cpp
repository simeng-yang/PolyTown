#include <Wolves.h>

//Wolf constructor
Wolf::Wolf(std::string name, std::string furColour, std::string className, std::string classChar)
    :name(name), furColour(furColour), className(className), classChar(classChar){
    if (className == "WOLF")
        std::cout<<"A "<<furColour<<" coloured "<<className<<" named "<<name<<" has come to wreak havoc!"<<std::endl;
}

//Makes wolf howl
void Wolf::Howl(){
    std::cout<<name<<" the "<<className<<": "<<"ARROOOOOOOO!"<<std::endl;
}

//Makes wolf growl
void Wolf::Growl(){
    std::cout<<name<<" the "<<className<<": "<<"GGRRRRRRRRR!"<<std::endl;
}

//Causes damage to citizens depending on their equity and a random number
bool Wolf::CauseDamage(Citizen &c, std::vector<Citizen*> &base, std::vector<Citizen*> &casualties){
    if (c.GetBalance() <= 100){
        std::cout << "The poor have no shelter and are devoured" << std::endl;
        //Adds citizen to a casualties vector
        casualties.push_back(&c);
        //Erase citizen from citizens vector
        base.erase(std::remove(base.begin(), base.end(), &c), base.end());
    }
    else if (c.GetBalance() <= 200 && (rand()%100 < 50))
    {
        std::cout << "The unfortunate few with nowhere to hide are devoured" << std::endl;
        //Adds citizen to a casualties vector
        casualties.push_back(&c);
        //Erase citizen from citizens vector
        base.erase(std::remove(base.begin(), base.end(), &c), base.end());
    }
    else
    {
        std::cout << "The sheltered and lucky ones live, but incur property damage" << std::endl;
        //Take away the specified amount of money from citizen balance
        c.LoseMoney(rand()%100);
    }

    std::cout << "And so fared " << c.GetPrefix()<< c.GetName() << c.GetSuffix() << std::endl;
}

//Wolf destructor
Wolf::~Wolf(){

}
