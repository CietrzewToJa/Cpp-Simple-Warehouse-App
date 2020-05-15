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
	void baseUpload();
	void saveItem(Item item);
	int getSize();

private:
	int cuantity;
	std::string type; //name of file with base
	std::fstream plik;
	int size;
	std::vector<Item> baseTab;

	friend class Item;
};

#endif