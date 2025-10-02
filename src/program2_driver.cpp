#include "inventory.h"
#include <iostream>
#include <fstream>

/*********************************************************************
File name: program2_driver.cpp
Author: Luke Lyons (ujw18)
Date: 10/03/2025

Purpose:
    Runs the Potion Inventory System by loading data from a file
    and providing a menu-driven interface for the user.

Command Parameters:
    None.

Input:
    Reads inventory data (name, type, potency, quantity) from a file
    and user input from the console.

Results:
    Displays inventory contents, allows adding potions, clears
    inventory, and calculates weighted average potency.

Notes:
    Inventory must be initialized with a valid file.
*********************************************************************/

void displayMenu()
{
    std::cout << "\nPotion Inventory Menu:" << std::endl;
    std::cout << "1. Display Inventory" << std::endl;
    std::cout << "2. Add a Potion" << std::endl;
    std::cout << "3. Calculate Weighted Average Potency" << std::endl;
    std::cout << "4. Clear Inventory" << std::endl;
    std::cout << "-1. Exit" << std::endl << std::endl;
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
    std::cout << "Inventory \"" << szInventoryName << "\" has been loaded." << std::endl << std::endl;

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

        if(iChoice == -1) 
        {
            std::cout << "Exiting the Potion Inventory System. " << std::endl;
            return 0; 
        };

        if(iChoice == 1)
        {
            std::cout << "Displaying  Inventory Information: " << std::endl;
            potionInventory.displayInventory();
            continue;
        };

        if(iChoice == 2)
        {
            std::cout << "Enter the name of the potion: ";
            std::cin >> szPotionName;
            std::cout << "Enter the type of the potion: ";
            std::cin >> szPotionType;
            std::cout << "Enter the potency of the potion: ";
            std::cin >> iPotionPotency;
            std::cout << "Enter the quantity of the potion: ";
            std::cin >> dPotionQuantity;

            Potion potion(szPotionName, szPotionType, iPotionPotency, dPotionQuantity);
            potionInventory.addPotion(potion);
            std::cout << "Potion added successfully!" << std::endl;
        };

        if(iChoice == 3)
        {
            std::cout << "The weighted average potency of all potions is: " 
                << std::fixed << std::setprecision(2) << potionInventory.calculateWeightedAveragePotency() << "%" << std::endl;
        };

        if(iChoice == 4)
        {
            potionInventory.clearInventory();
            std::cout << "Inventory cleared successfully!" << std::endl;
        };
    };
    
    return 0;
}
