#include "TaxMan.h"

//Tax Man constructor
TaxMan::TaxMan(std::string name):Human(name, "TAX MAN", "HIGHLORD") {
 std::cout << "I, " << name << ", the tax man, have come to collect my due!";
}

//Taxes all citizens, depending on classname
void TaxMan::CollectTax(Citizen &c) {
    if (c.GetBalance() <= 0){
        Say(("You have no money, but I'll get you next time."));
    }

    std::string cn = c.GetClass();   //Gets the class name
    if (cn == "HUMAN"){
        Say("10\% tax rate for you, human.");
        c.PayTax(10);
    }
    else if (cn == "ZOMBIE"){
        Say("12\% tax rate for you, zombie.");
        c.PayTax(15);
    }
    else if (cn == "VAMPIRE"){
        Say("14\% rate for you, vampire.");
        c.PayTax(15);
    }
    else if (cn == "NOBBS"){
        Say("15\% tax rate for you, Nobbs.");
        c.PayTax(15);
    }
    else if (cn == "WEREWOLF"){
        Say("16\% tax rate for you, werewolf.");
        c.PayTax(15);
    }
    else if (cn == "DWARF"){
        Say("17\% tax rate for you, dwarf.");
        c.PayTax(20);
    }
    else if (cn == "TROLL"){
        Say("18\% tax rate for you, troll.");
        c.PayTax(17);
    }
    else
        Say("Ah, exempt. A lucky break.");

        std::cout << "And so complied " << c.GetPrefix()<< c.GetName() << c.GetSuffix() << std::endl;
}

//Tax Man destructor
TaxMan::~TaxMan()
{
    //dtor
}
