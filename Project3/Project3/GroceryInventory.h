#pragma once 

#include <vector> 
#include <iostream> 
#include <fstream> 
#include <stdexcept> 
#include "GroceryItem.h" 

using namespace std;
class GroceryInventory {
private:
	vector<GroceryItem> _inventory;
	float _taxRate;

public:
	GroceryInventory()
	{
		_taxRate = 0.0f;
	}

	GroceryItem& getEntry(const string& itemName)
	{
		size_t i = 0;
		while (i < _inventory.size())
		{
			if (_inventory[i].getName() == itemName)
			{
				return _inventory[i];
			}

			i++;
		}
		throw invalid_argument("Item not found");
	}

	template<typename T>
	void addEntry(const string& itemName, const int& quantity, const T& unitPrice, const bool& taxable)
	{
		GroceryItem newItem(itemName, quantity, (float)(unitPrice), taxable);
		_inventory.push_back(newItem);
	}

	float getTaxRate() const
	{
		return _taxRate;
	}

	void setTaxRate(const float& taxRate)
	{
		_taxRate = taxRate / 100;
		//_taxRate /= 100;
	}

	void createListFromFile(const string&);

	float calculateUnitRevenue() const
	{
		float total = 0.0f;
		for (size_t i = 0; i < _inventory.size(); i++)
		{
			total += _inventory[i].getUnitPrice() * _inventory[i].getQuantity();
		}
		return total;
	}

	float calculateTaxRevenue() const
	{
		float total = 0.0f;
		for (size_t i = 0; i < _inventory.size(); i++)
		{
			if (_inventory[i].isTaxable() == true)
				total += _inventory[i].getUnitPrice() * _inventory[i].getQuantity() * _taxRate;
		} 
		return total;
	}

	float calculateTotalRevenue() const
	{
		float total = 0.0f;
		for (size_t i = 0; i < _inventory.size(); i++)
		{
			total += _inventory[i].getQuantity() * _inventory[i].getUnitPrice();
		}
		return total;
	}

	GroceryItem& operator[](const int& index)
	{
		return _inventory[index];
	}

	//~GroceryInventory() {}
};

void GroceryInventory::createListFromFile(const string& filename) {

	ifstream input_file(filename);

	if (input_file.is_open()) {

		cout << "Successfully opened file " << filename << endl;

		string name;

		int quantity;

		float unit_price;

		bool taxable;

		while (input_file >> name >> quantity >> unit_price >> taxable) {

			addEntry(name, quantity, unit_price, taxable);
		}

		input_file.close();

	}
	else {

		throw invalid_argument("Could not open file " + filename);
	}

}