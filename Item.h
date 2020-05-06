#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {

public:
	Item(std::string itemName, std::string itemDescription, std::string itemPlace);
	Item() = default;

private:
	int itemId;
	std::string itemName;
	std::string itemDescription;
	std::string itemPlace;

	friend class Base;
};

#endif