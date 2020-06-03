#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

// #include "Base.h"

// class Base;

class Item {

public:
	Item(std::string itemId, std::string itemName, std::string itemDescription, std::string itemPlace);
	~Item();
	void getItem();
	bool operator<(const Item& r) const;
	std::string itemId;

private:
	std::string itemName;
	std::string itemDescription;
	std::string itemPlace;
	char separator = ' ';

	friend class Base;
};

#endif