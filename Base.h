#ifndef BASE_H
#define BASE_H

#include "Item.h"
#include <fstream>
#include <vector>
#include <algorithm>

class Base {

public:
	Base(std::string type);
	~Base() = default;

	void baseOpen(int mode);
	void baseClose();
	void baseUpload(std::string var1, std::string var2, std::string var3);
	void saveItem(Item item);
	int getSize();

private:
	int cuantity;
	std::string type;
	std::fstream plik;
	int size;
	std::vector<Item> baseTab;

	friend class Item;
};

#endif