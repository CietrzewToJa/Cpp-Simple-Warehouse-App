#include "Base.h"

Base::Base(std::string baseName) {
	this->baseName = baseName;
	baseUpload();
}

Base::~Base() {
	
}

//Get number of lines divide of 3 => how many elements you got
int Base::getSize() {
	int numLines = 0;
	std::ifstream in(baseName);
	std::string unused;
	while ( std::getline(in, unused) )
   		++numLines;
   	return size = numLines/4;
}

//Save base from file to baseTab[] vector
void Base::baseUpload() {
	std::string var1, var2, var3;
	std::string var0;
	getSize();
	baseOpen(2);
	int i = 0;
	while(i < size) {
		getline(plik,var0);
		getline(plik,var1);
		getline(plik,var2);
		getline(plik,var3);
		this->baseTab.push_back(Item(var0,var1,var2,var3));
		i++;
	}
	baseClose();
}

void Base::showBase() {
	std::cout << "\n";
	std::cout << " | " << std::left << std::setw(5) << std::setfill(' ') << " ID";
	std::cout << " | " << std::left << std::setw(15) << std::setfill(' ') << "  NAME";
	std::cout << " | " << std::left << std::setw(30) << std::setfill(' ') << "  DESCRIPTION";
	std::cout << " | " << std::left << std::setw(15) << std::setfill(' ') << "  PLACE";
	std::cout << std::left << std::setw(80) << std::setfill('=') << "\n";
	std::cout << "\n";
	for(auto & val: baseTab) {
		val.getItem();
	}
}

void Base::baseOpen(int mode) {
	//get to the base
	switch(mode) {
		case 1:
			//Save to file
			plik.open(baseName, std::ios::out);
			if(!plik.good())
				std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
			break;
		case 2:
			//Read from file
			plik.open(baseName, std::ios::in | std::ios::app);
			if(!plik.good())
				std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
			break;
	}
}

//Close file
void Base::baseClose() {
	plik.close();
}

//Save new item to base
void Base::newItem() {
	std::string var0, var1, var2, var3, a, b;

	std::cout << "Type name: (1-15 chars): ";
	std::cin.ignore(99999, '\n');
	std::getline(std::cin, var1);
	while(!sizeCheck(var1, 15)) {
		std::cout << "Type name: ";
		std::getline(std::cin, var1);
	}
	std::cout << "Type description (1-30 chars): ";
	std::getline(std::cin, var2);	
	while(!sizeCheck(var2, 30)) {
		std::cout << "Type name: ";
		std::getline(std::cin, var1);
	}
	std::cout << "Type place: ";
	std::getline(std::cin, var3);
	while(!sizeCheck(var3, 30)) {
		std::cout << "Type name: ";
		std::getline(std::cin, var1);
	}

	var0 = setId();

	baseTab.push_back(Item(var0,var1,var2,var3));
	baseSave();
}

bool Base::sizeCheck(std::string str, int limit) {
	if(str.length() > limit) {
		std::cout << "Text too long! ";
		return 0;
	}
	return 1;
}

void Base::editItem(std::string itemId) {
	std::vector<Item>::iterator it;

	it = findItem(itemId);

	std::cout << std::endl << "Type new name: ";
	std::cin.ignore(99999, '\n');
	std::getline(std::cin, (*it).itemName);
	while(!sizeCheck((*it).itemName, 15)) {
		std::cout << "Type new name again: ";
		std::getline(std::cin, (*it).itemName);
	}
	std::cout << "Type new description: ";
	std::getline(std::cin, (*it).itemDescription);
	while(!sizeCheck((*it).itemDescription, 30)) {
		std::cout << "Type new description again: ";
		std::getline(std::cin, (*it).itemName);
	}
	std::cout << "Type new place: ";
	std::getline(std::cin, (*it).itemPlace);
	while(!sizeCheck((*it).itemPlace, 15)) {
		std::cout << "Type new place again: ";
		std::getline(std::cin, (*it).itemName);
	}

	baseSave();
}

std::vector<Item>::iterator Base::findItem(std::string itemId) { 
  	std::vector<Item>::iterator it;

	for(it = baseTab.begin(); it != baseTab.end(); ++it) {
		if((*it).itemId == itemId) {
			std::cout << std::endl;
			(*it).getItem();
			break;
		}
  	}
  	if(it == baseTab.end())
  		std::cout << "There is no such item." << '\n';

  	return it;
}

void Base::deleteItem(std::vector<Item>::iterator it) {

	baseTab.erase(it);
	baseSave();
}

void Base::baseSort() {

	sort(baseTab.begin(), baseTab.end());
}

void Base::baseSave() {
	baseOpen(1);
	getSize();
	size++;

	for(auto & val: baseTab) {
		plik.write(&val.itemId[0], val.itemId.length());
		plik << '\n';
		plik.write(&val.itemName[0], val.itemName.length());
		plik << '\n';
		plik.write(&val.itemDescription[0], val.itemDescription.length());
		plik << '\n';
		plik.write(&val.itemPlace[0], val.itemPlace.length());
		plik << '\n';
	}
	baseClose();
}

std::string Base::setId() {
	std::vector<Item>::iterator it;
	int Id = 2;
	std::string Id2 = "00";

	it = baseTab.end()-1;
	// std::cout << "tu";
	// std::cout << (*it).itemId;
	Id = std::stoi((*it).itemId);
	Id++;
	Id2 += std::to_string(Id);

	return Id2;
}