#include "Citizen.h"
#include "Human.h"
#include "Humanoids.h"
#include "Others.h"
#include "Werewolves.h"
#include "Wolves.h"
#include "TaxMan.h"
#include "Jobs.h"
#include <iostream>
#include <time.h>              //Random number seed
#include <vector>              //vectors
#include <sstream>             //stringstream

//Generates human names
using namespace std;

string GenHumanName(){
    vector<string> name;
    name.push_back("Goethe");
    name.push_back("Euclid");
    name.push_back("Archimedes");
    name.push_back("Aristotle");
    name.push_back("Zeno");

    int i = rand()%(name.size());
    return name[i];
}

//Generates dwarf names
string GenDwarfName(){
    vector<string> name;
    name.push_back("Toto");
    name.push_back("Momo");
    name.push_back("Dodo");
    name.push_back("Meme");
    name.push_back("Xoxo");

    int i = rand()%(name.size());
    return name[i];
}

//Generates wolf names
string GenWolfName() {
    vector<string> name;
    name.push_back("Growler");
    name.push_back("Howler");
    name.push_back("Bowler");
    name.push_back("Pouncer");
    name.push_back("Hatcher");

    int i = rand()%(name.size());
    return name[i];
}

//Generates troll names
string GenTrollName() {
    vector<string> name;
    name.push_back("Urem");
    name.push_back("Decem");
    name.push_back("Neptem");
    name.push_back("Graftem");
    name.push_back("Daftem");

    int i = rand()%(name.size());
    return name[i];
}

//Generates colour of wolf fur
string GenWolfFur() {
    vector<string> colour;
    colour.push_back("brown");
    colour.push_back("white");
    colour.push_back("grey");
    colour.push_back("black");

    int i = rand()%(colour.size());
    return colour[i];
}

//Generates salary
//Salary tier and multiplier should be non-zero
float GenSalary() {
    float tier = 0;
    float multiplier = 0;
    do {
        tier = rand() % 100;
        multiplier = rand() % 10;
    } while (tier < 0.1 || multiplier < 0.1);

    return tier * multiplier;
}

//Generates job position
string GenPosition(){
    vector<string> position;
    position.push_back("Novice");
    position.push_back("Trained");
    position.push_back("Experienced");
    position.push_back("Veteran");
    position.push_back("Master");

    int i = rand()%(position.size());
    return position[i];
}

//Generates job name
string GenJobName(){
    vector<string> name;
    name.push_back("Data Secretary");
    name.push_back("Physical Manipulator");
    name.push_back("Space Contortionist");
    name.push_back("Febreeze Dispenser");
    name.push_back("Esteem Deflator");

    int i = rand()%(name.size());
    return name[i];
}

//Gets the balance of the citizen
void FetchBalance(Citizen &c){
    std::cout << c.GetPrefix() << c.GetName()<< c.GetSuffix() << " has: "
    << c.GetBalance() << " " << c.GetMoneyTypePlural() << std::endl;
}

//Randomly generates a citizen with randomly generated name and adds it to a pointer vector
//Wolf fur is initialized for wolf object
void GetCitizen(vector<Citizen*> &base)
{
switch(rand()%7)
{
    case 0:
        base.push_back(new Human(GenHumanName()));
        break;
    case 1:
        base.push_back(new Nobbs(GenHumanName()));
        break;
    case 2:
        base.push_back(new Vampire(GenHumanName()));
        break;
    case 3:
        base.push_back(new Werewolf(GenWolfName(), GenWolfFur(), "TRANSMUTABLE"));
        break;
    case 4:
        base.push_back(new Zombie(GenHumanName()));
        break;
    case 5:
        base.push_back(new Troll(GenTrollName()));
        break;
    case 6:
        base.push_back(new Dwarf(GenDwarfName()));
        break;
}
}

//Makes a job and adds it to a pointer vector for Jobs
void MakeJob(vector<Jobs*> &jobs)
{
    jobs.push_back(new Jobs(GenJobName(), GenSalary(), GenPosition()));
}

int main()
{
//Declare variables
int townSize = 15;

vector<Citizen*> base;
vector<Citizen*> casualties;
vector<Jobs*> jobs;
vector<Wolf*> beasts;
vector<string> names;
vector<string> types;
string name = " ";
string type = " ";
stringstream ss;
int typeCounter;

//Grandma Atta is telling a story. It all begins here...
cout << "Children, come along! I have a story to share, " << endl <<
"one of the rise and fall of a great town to rival our own." << endl << endl;

//Generate and add citizens to citizen pointer vector
for (int i = 0; i < townSize; i++)
{
    GetCitizen(base);

    name = base[i] -> GetName();
    type = base[i] -> GetClass();

    typeCounter = 1;

    //If a combination of name and classname is duplicated,
    //changes the name to be unique by appending the instance number
    for (int j = 0; j < base.size()-1; j++)
    {
        string compareClass = base[j] -> GetClass();
        string compareName = base[j] -> GetName();

        if (compareClass == type && compareName == name){
            cout << "Inconsistency avoidance: " << name << " will be appended";
            typeCounter++;

            ss << name << " No. " << typeCounter;
            name = ss.str();
            cout << ": No. " << typeCounter << endl;

            base[i] -> SetName(name);
            ss.str(string());
        }
    }

   names.push_back(name);
   types.push_back(type);
}

cout << endl;
cout << "The economic boom has opened up a large number of jobs for the town!" << endl << endl;

//Make jobs up to how many citizens there are
for (int j = 0; j < base.size(); j++)
{
    MakeJob(jobs);
    //Adds the job to a citizen of same index (j)
    base[j] -> GetJob(*jobs[j]);
}

cout << endl;
cout << "One week later, the citizens rejoice with monetary compensation!" << endl << endl;

//Pay each citizen their salaries
//Will update citizen balance
for (int k = 0; k < base.size(); k++)
{
    base[k] -> GetPaid(base[k] -> GetSalary());
}

cout << endl;
cout << "Overjoyed, they talk about their lives and those of others!" << endl << endl;

//Make citizens talk
for (int l = 0; l < base.size(); l++)
{
    base[l] -> Say();

    //If the citizen is also a werewolf, makes them howl or growl
    if (base[l] -> GetClass() == "WEREWOLF")
    {
        if (rand() % 2 == 0)
        {
             base[l] -> Howl();
        }
        else
        {
            base[l] -> Growl();
        }
    }
}

cout << endl;
cout << "Townsfolk eagerly await the celebration of their new balances:" << endl << endl;

//Print balances of each citizen
for (int m = 0; m < base.size(); m++)
{
    FetchBalance(*base[m]);
}

cout << endl;
cout << "However, in this otherwise peaceful town, something is astir..." << endl
    << "Gasp, the tax man has come!" << endl;
//Instantiates TaxMan object
TaxMan *theTaxer = new TaxMan("Gloria");

cout << endl << "Anxiously, the townsfolk gather 'round and ... pay their taxes!" << endl << endl;

//Tax all citizens
//Citizens will be taxed by class and have their balances adjusted
for (int n = 0; n < base.size(); n++)
{
    theTaxer -> CollectTax(*base[n]);
}

cout << endl << "With their wallets a little lighter and their spirits a little heavier," << endl
    << "the citizens protect all they have left: " << endl << endl;

//Print new balances of all citizens
for (int o = 0; o < base.size(); o++)
{
    FetchBalance(*base[o]);
}

cout << endl << "But, in the morning, disaster strikes: the town is ambushed by wolves!" << endl << endl;

//Generate wolf objects and add them to a wolves pointer array
for (int p = 0; p < 10; p++)
{
    beasts.push_back(new Wolf(GenWolfName(), GenWolfFur()));

    //Make wolves growl or howl
    if (p % 2 == 0)
    {
        beasts[p] -> Growl();
    }
    else if (p % 3 == 0)
    {
        beasts[p] -> Howl();
    }
}

cout << endl << "With nowhere left to run, the townsfolk are forced to hide!" << endl
    << "But who will make it out alive?" << endl << endl;

//Make wolves attack the town citizens
for (int q = 0; q < base.size(); q++)
{
    beasts[0] -> CauseDamage(*base[q], base, casualties);
}

cout << endl << "Oh, the massacre, the bloodshed! Now, who has survived?";
cout << endl << "A tally is made; the survivors are named and casualties declared. " << endl << endl;

//Compiles and outputs a list of citizens who have survived
for (int r = 0; r < base.size(); r++)
{
    cout << base[r] -> GetPrefix() << base[r] -> GetName() << base[r] -> GetSuffix() <<
    " lives to see another day: ALIVE" << endl;
}

//Lists citizens who have died
for (int y = 0; y < casualties.size(); y++)
{
    cout << casualties[y] -> GetPrefix() << casualties[y] -> GetName() << casualties[y] -> GetSuffix() <<
    " has perished: DEAD" << endl;
}

//Tally the number of survivors and the dead
    cout << "In total, there were " << base.size() << " survivors and "
    << casualties.size() << " casualties.";

//Grandma Atta's story is concluded
cout << endl << endl << "Thus ends the tragic story and to all a good night!" << endl << endl;

//Delete citizens who have survived
for (int s = 0; s < base.size(); s++) {
    delete base[s]; // Calls ~object which deallocates base[s]
}

 //Clear vector
base.clear();

//Delete citizens who were killed
for (int t = 0; t < casualties.size(); t++)
{
    delete casualties[t];
}

//Clear vector
casualties.clear();

return 0;
}
