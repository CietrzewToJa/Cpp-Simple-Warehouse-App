#include "Item.h"
#include "Base.h"

Item::Item(std::string itemName, std::string itemDescription, std::string itemPlace) {
	this->itemName = itemName;
	this->itemDescription = itemDescription;
	this->itemPlace = itemPlace;
}