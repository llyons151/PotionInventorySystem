#include "inventory.h"

// Constructors
Inventory::Inventory() : szName(""), iCurrentPotions(0) {};
Inventory::Inventory(std::string name) : szName(name), iCurrentPotions(0) {};

// Setters and Getters
void Inventory::setName(std::string szName) { this->szName = szName; };
std::string Inventory::getName() { return szName; };
int Inventory::getInventorySize() { return MAX_INVENTORY_SIZE; };

// Inventory operations
void Inventory::addPotion(const Potion& newPotion) 
{
    if(iCurrentPotions == 30)
    {
        std::cout << "Inventory has reached max capacity" << std::endl;
        return;
    };

    potionArr[iCurrentPotions] = newPotion;
    iCurrentPotions++;
};

void Inventory::displayInventory() 
{
    for(int i = 0; i < iCurrentPotions; i++)
    {
        potionArr[i].display();
    };
};

double Inventory::calculateWeightedAveragePotency() 
{
    if(iCurrentPotions == 0) return 0;

    double dWeightedAverage = 0;
    
    for(Potion p : potionArr)
    {
        dWeightedAverage += p.getPotency();
    };

    dWeightedAverage = dWeightedAverage / iCurrentPotions;

    return dWeightedAverage;
};

void Inventory::clearInventory() { iCurrentPotions = 0; };
