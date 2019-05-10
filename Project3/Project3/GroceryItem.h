#pragma once

#include <string> 

using namespace std;

class GroceryItem {
private:
	string _name;
	int _quantity;
	float _unitPrice;
	bool _taxable;
public:
	GroceryItem()
	{
		_name = "";
		_quantity = 0;
		_unitPrice = 0.0f;
		_taxable = false;
	}


	template<typename T>
	GroceryItem(const string& itemName, const int& quantity,
		const T& unitPrice, const bool& taxable)
	{
		_name = itemName;
		_quantity = quantity;
		_unitPrice = static_cast<float>(unitPrice);
		_taxable = taxable;
	}

	string getName() const
	{
		return _name;
	}

	void setName(const string& itemName)
	{
		_name = itemName;
	}

	int getQuantity() const
	{
		return _quantity;
	}

	void setQuantity(const int& quantity)
	{
		_quantity = quantity;
	}

	float getUnitPrice() const
	{
		return _unitPrice;
	}

	void setUnitPrice(const float& unitPrice)
	{
		_unitPrice = unitPrice;
	}

	bool isTaxable() const
	{
		return _taxable;
	}

	void setTaxable(const bool& taxable)
	{
		_taxable = taxable;
	}

};