#include "Item.h"

Item::Item(std::string itemId, std::string itemName, std::string itemDescription, std::string itemPlace) {
	this->itemName = itemName;
	this->itemDescription = itemDescription;
	this->itemPlace = itemPlace;
	this->itemId = itemId;
}

Item::~Item() {
	
}

void Item::getItem() {
	std::cout << " | " << std::left << std::setw(5) << std::setfill(separator) << itemId;
	std::cout << " | " << std::left << std::setw(15) << std::setfill(separator) << itemName;
	std::cout << " | " << std::left << std::setw(30) << std::setfill(separator) << itemDescription;
	std::cout << " | " << std::left << std::setw(15) << std::setfill(separator) << itemPlace;
	std::cout << "\n";
}

bool Item::operator<(const Item& r) const {
	if (itemName != r.itemName)
		return itemName < r.itemName;

	return itemName < r.itemName;
}