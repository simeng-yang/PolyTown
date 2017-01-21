#ifndef CITIZEN_H
#define CITIZEN_H

//Forward declarations
class Jobs;

class Wolf;

#include <iostream>
#include <stdlib.h>

class Citizen{
private:
    std::string prefix;
    std::string suffix;
protected:
    std::string name;
    std::string classChar;
    std::string className;
    std::string moneyName;
    std::string classNamePlural;
    std::string moneyNamePlural;
    float salary;
    std::string position;
    std::string jobName;
    float balance;

public:
    Citizen (std::string name, std::string className, std::string classChar, std::string moneyName,
             std::string classNamePlural, std::string moneyNamePlural);

    std::string GetPrefix();
    std::string GetSuffix();

    void SetSuffix (std::string newSuffix);
    void SetPrefix (std::string newPrefix);
    void SetName(std::string newName);

    virtual std::string DefaultSpeech() = 0;

    //For werewolves
    virtual void Howl(){}
    virtual void Growl(){}

    void Say (std::string stringToSay);
    void Say ();

    void GetPaid(float salary);

    float ExchangeCurrencyRates(float amount, std::string currencyFrom, std::string currencyTo);

    void PayTax(float taxPercent);

    void LoseMoney(float toLose);

    float GetBalance();

    float GetSalary();

    void GetJob(Jobs &toWork);

    void CalculuateLoss(float original, float reduced);

    std::string GetClass();

    std::string GetName();

    std::string GetMoneyType();

    std::string GetClassPlural();

    std::string GetMoneyTypePlural();

    virtual ~Citizen();
};


#endif // CITIZEN_H
