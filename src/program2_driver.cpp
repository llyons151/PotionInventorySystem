#include "inventory.h"
#include <iostream>
#include <fstream>

void displayMenu()
{
    std::cout << "\nPotion Inventory Menu:" << std::endl;
    std::cout << "1. Display Inventory" << std::endl;
    std::cout << "2. Add a Potion" << std::endl;
    std::cout << "3. Calculate Weighted Average Potency" << std::endl;
    std::cout << "4. Clear Inventory" << std::endl;
    std::cout << "-1. Exit" << std::endl;
}

int main() 
{
    std::cout << "Welcome to the Potion Inventory System!" << std::endl;

    std::ifstream fileInput;
    std::string fileName;
    std::cout << "Enter filename: ";
    std::cin >> fileName;
    fileInput.open(fileName);
    if(!fileInput.is_open()) {
        std::cout << fileName << " does not exist" << std::endl;
        return 0;
    };

    std::string szInventoryName;
    std::getline(fileInput, szInventoryName);
    Inventory potionInventory(szInventoryName);
    std::cout << "Inventory " << szInventoryName << " has been loaded." << std::endl << std::endl;

    std::string szPotionName, szPotionType;
    int iPotionPotency;
    double dPotionQuantity;

    while(fileInput >> szPotionName
                    >> szPotionType
                    >> iPotionPotency
                    >> dPotionQuantity)
    {
        Potion potion(szPotionName, szPotionType, iPotionPotency, dPotionQuantity);
        potionInventory.addPotion(potion);
    };
    fileInput.close();


    int iChoice;

    while(true)
    {
        displayMenu();

        std::cout << "Enter your choice: ";
        std::cin >> iChoice;

        if(iChoice == -1) { return 0; };

        if(iChoice == 1)
        {
            potionInventory.displayInventory();
            continue;
        };

        if(iChoice == 2)
        {

        };

        if(iChoice == 3)
        {
            std::cout << "The weighted average potency of all potions is: " 
                << potionInventory.calculateWeightedAveragePotency() << "%" << std::endl;
        };

        if(iChoice == 4)
        {
            potionInventory.clearInventory();
            std::cout << "Inventory cleared successfully!" << std::endl;
        };
    };
    
    return 0;
}
