#include "potion.h"

//Constructors
Potion::Potion() : szName(""), szType(""), iPotency(0), dQuantity(0.0){};
Potion::Potion(std::string name, std::string type, int potency, double quantity)
    : szName(name), szType(type), iPotency(potency), dQuantity(quantity){};


