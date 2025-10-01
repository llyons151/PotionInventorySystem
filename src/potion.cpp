#include "potion.h"

// Constructors
Potion::Potion() : szName(""), szType(""), iPotency(0), dQuantity(0.0){};
Potion::Potion(std::string name, std::string type, int potency, double quantity)
    : szName(name), szType(type), iPotency(potency), dQuantity(quantity){};

// Getter and Setter functions
void Potion::setName(std::string szName) { this->szName = szName; };
std::string Potion::getName() { return szName; };

void Potion::setType(std::string szType) { this->szType = szType; };
std::string Potion::getType() { return szType; };

void Potion::setPotency(int iPotency) { this->iPotency = iPotency; };
int Potion::getPotency() { return iPotency; };

void Potion::setQuantity(double dQuantity) { this->dQuantity = dQuantity; };
double Potion::getQuantity() { return dQuantity; };

// Display function
void Potion::display() {
    std::cout << szName
              << " [" << szType << "]"
              << " - Potency: " << iPotency << "%"
              << ", Quantity: " << std::fixed << std::setprecision(2) << dQuantity << "L"
              << std::endl;
}
