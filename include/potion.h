#include <iostream>
#include <iomanip>
#include <string>

/*********************************************************************
Class Name: Potion
Purpose:
    The Potion class represents a single potion in a wizard's 
    inventory.
Notes:
    Each potion has a name, type, potency, and quantity.
*********************************************************************/
class Potion
{
	private:
        std::string szName;        // Name of the potion (Healing, Mana)
        std::string szType;        // Type of potion (Health, Mana, Buff)
		int iPotency;         // Strength or effect level of the potion
		double dQuantity;     // Quantity in liters or ounces

	public:
		Potion();
		Potion(std::string szName, std::string szType, int iPotency, double dQuantity);

		// Setters and Getters
		void setName(std::string szName);
        std::string getName();

		void setType(std::string szType);
        std::string getType();

		void setPotency(int iPotency);
		int getPotency();

		void setQuantity(double dQuantity);
		double getQuantity();

		// Display function
		void display();
};
