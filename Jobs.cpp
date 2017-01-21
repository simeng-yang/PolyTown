#include "Jobs.h"

//Currency exchanger between money types
float Jobs::ExchangeCurrencyRates(float amount, std::string currencyFrom, std::string currencyTo)
    {
        float f;
        float t;

    //Currency to convert from
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

        //Currency to convert to
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

//Creates job and outputs job attributes
Jobs::Jobs(std::string jobName, float salary, std::string position):jobName(jobName), salary(salary), position(position)
{
    std::cout << "New " << jobName << ", position: " << position << " urgently needed!" << std::endl;
    std::cout << "Salary: " << salary << " DOLLARS, " << std::endl;
    std::cout << "      : " << ExchangeCurrencyRates(salary, "DOLLAR", "GOLD") << " GOLD COINS, " << std::endl;
    std::cout << "      : " << ExchangeCurrencyRates(salary, "DOLLAR", "GEM") << " GEMS, " << std::endl;
}

Jobs::~Jobs()
{
    //dtor
}

//Gets salary
float Jobs::GetSalary()
{
    return salary;
}

//Gets job position
std::string Jobs::GetPosition()
{
    return position;
}

std::string Jobs::GetName()
{
    return jobName;
}

//Make new salary
void Jobs::SetSalary(float newSalary)
{
    salary = newSalary;
}

//Make new job position
void Jobs::SetPosition(std::string newPosition)
{
    position = newPosition;
}

