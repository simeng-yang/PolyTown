#ifndef TAXMAN_H
#define TAXMAN_H

#include "Human.h"

#include <iostream>
#include "Human.h"

class TaxMan: public Human {
public:
    TaxMan(std::string name);
    void CollectTax(Citizen &c);
    virtual ~TaxMan();
};

#endif // TAXMAN_H
