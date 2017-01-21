#ifndef JOBS_H
#define JOBS_H

#include <iostream>
#include "Citizen.h"

class Jobs
{
    public:
        Jobs(std::string jobName, float salary, std::string position);
        virtual ~Jobs();
        float GetSalary();
        std::string GetPosition();
        std::string GetName();
        void SetSalary(float newSalary);
        void SetPosition(std::string newPosition);
        float ExchangeCurrencyRates(float amount, std::string currencyFrom, std::string currencyTo);
    protected:
        float salary;
        std::string position;
        std::string jobName;
};

#endif // JOBS_H
