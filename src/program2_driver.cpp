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
    
    return 0;
}
