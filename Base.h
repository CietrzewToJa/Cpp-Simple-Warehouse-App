#ifndef BASE_H
#define BASE_H

#include "Item.h"

class Base {

public:
	Base(std::string baseName);
	Base() = delete;
	~Base();

	void showBase();
	void newItem();
	std::vector<Item>::iterator findItem(std::string itemId);
	void editItem(std::string itemId);
	void deleteItem(std::vector<Item>::iterator it);
	void baseSort();
	std::vector<Item> baseTab;


private:
	int cuantity;
	std::string baseName; //name of file with base
	std::fstream plik;
	int size;

	void baseUpload();
	void baseSave();
	void baseOpen(int mode);
	void baseClose();
	int getSize();
	bool sizeCheck(std::string str, int limit);


	friend class Item;
};

#endif