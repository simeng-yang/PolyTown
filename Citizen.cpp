#include "Citizen.h"
#include <time.h>              //Random number seed
#include <stdlib.h>            //srand

#include <Jobs.h>

//Citizen constructor
Citizen::Citizen (std::string name, std::string className, std::string classChar,
    std::string moneyName, std::string classNamePlural, std::string moneyNamePlural)
    :name(name), className(className), classChar(classChar), moneyName(moneyName),
    classNamePlural(classNamePlural), moneyNamePlural(moneyNamePlural),
    prefix(classChar + " "), suffix(" the " + className),
    salary(0), position("None"), jobName("None"), balance(0){

    //Default prefix is the job
    //Default suffix is the classname

    std::cout<<prefix<<name<<suffix<<" is created."<<std::endl;
}

//Gets citizen prefix
std::string Citizen::GetPrefix(){
return prefix;
}

//Gets citizen suffix
std::string Citizen::GetSuffix(){
return suffix;
}

//Sets new citizen prefix
void Citizen::SetPrefix(std::string newPrefix) {
    prefix = newPrefix;
}

//Sets new citizen suffix
void Citizen::SetSuffix(std::string newSuffix) {
    suffix = newSuffix;
}

//Updates job attributes for citizen object from Jobs object
void Citizen::GetJob(Jobs &toWork){
jobName = toWork.GetName();
salary = toWork.GetSalary();
position = toWork.GetPosition();
std::cout << "JOB TAKEN: " << prefix<<name<<suffix << std::endl;
}

//Set new name for citizen
void Citizen::SetName(std::string newName) {
    name = newName;
}

//Makes citizen say any std::string
void Citizen::Say (std::string stringToSay){
    std::cout<<prefix<<name<<suffix<<": "<<stringToSay<<std::endl;
}

//Makes citizen say default speech
void Citizen::Say (){

    Say(DefaultSpeech());
}

//Currency converter between different types of money
float Citizen::ExchangeCurrencyRates(float amount, std::string currencyFrom, std::string currencyTo)
    {
        float f;
        float t;

    if (currencyFrom == "DOLLAR")
        {
            f = 1;
        }
    else if (currencyFrom == "GOLD")
        {
            f = 0.85;
        }
    else
        {
            f = 0.9;
        }

        if (currencyTo == "DOLLAR")
        {
            t = 1;
        }
        else if (currencyTo == "GOLD")
        {
            t = 1.175;
        }
        else
        {
            t = 1.11;
        }

    return f * t * amount;
}

//Gets citizen balance
float Citizen::GetBalance(){
    return balance;
}

//Gets citizen classname
std::string Citizen::GetClass(){
    return className;
}

//Gets citizen name
std::string Citizen::GetName(){
    return name;
}

//Gets citizen money type
std::string Citizen::GetMoneyType(){
    return moneyName;
}

//Gets plural form of citizen classname
std::string Citizen::GetClassPlural(){
    return classNamePlural;
}

//Gets plural form of citizen money type
std::string Citizen::GetMoneyTypePlural(){
    return moneyNamePlural;
}

//Gets citizen salary
float Citizen::GetSalary(){
//std::cout << salary << std::endl;
return salary;
}

//Calculates loss between two values and outputs text
void Citizen::CalculuateLoss(float original, float reduced)
{
    float difference = original - reduced;
    std::cout << prefix << name << suffix << " lost " << difference << " " << moneyNamePlural;
    std::cout << " - how sad!" << std::endl;
}

//Lower citizen balance
void Citizen::LoseMoney(float toLose){
    balance -= toLose;
}

//Update citizen balance with salary
void Citizen::GetPaid(float salary){
    float correctedSalary = ExchangeCurrencyRates(salary, "DOLLAR", moneyName);
    balance += correctedSalary;
    std::cout << prefix << name << suffix << " has been paid: " << correctedSalary << " " << moneyNamePlural << std::endl;
}

//Make citizen pay taxes
//Adjusts citizen balance
void Citizen::PayTax(float taxPercent){
    float correctedBalance = ExchangeCurrencyRates(balance, "DOLLAR", moneyName);
    CalculuateLoss(correctedBalance, correctedBalance * (1-taxPercent/100));
    correctedBalance *= 1-taxPercent/100;
}

//destructor
Citizen::~Citizen(){
    std::cout<<prefix<<name<<suffix<<" is destroyed."<<std::endl;
}
