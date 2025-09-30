#include "potion.h"
inline const int MAX_INVENTORY_SIZE = 30;

/*********************************************************************
Class Name: Inventory
Purpose:
    The Inventory class represents a collection of potions managed
    by a wizard or alchemist.
Notes:
    Stores multiple Potion objects.
    Supports adding, displaying, clearing, and calculating total 
    quantity.
*********************************************************************/
class Inventory
{
	private:
        std::string szName;                          // Name of the inventory or owner
		int iCurrentPotions;                    // Number of potions currently in inventory
		Potion potionArr[MAX_INVENTORY_SIZE];   // Array of Potion objects

	public:
		Inventory();
		Inventory(std::string szName);

		// Setters and Getters
		void setName(std::string szName);
        std::string getName();
		int getInventorySize();

		// Inventory operations
		void addPotion(const Potion& newPotion);
		void displayInventory();
		double calculateWeightedAveragePotency();
		void clearInventory();
};
