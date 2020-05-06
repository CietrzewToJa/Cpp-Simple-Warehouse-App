#ifndef BASE_H
#define BASE_H

#include "Item.h"
#include <fstream>

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
	std::string type;
	std::fstream plik;
	int size;
	Item * baseTab = new Item[20];

	friend class Item;
};

#endif