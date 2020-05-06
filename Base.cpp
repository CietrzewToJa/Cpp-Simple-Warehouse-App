#include "Base.h"

Base::Base(std::string type) {
	this->type = type;
}

//Get number of lines divide of 3 => how many elements you got
int Base::getSize() {
	int numLines = 0;
	std::ifstream in("druzyna.txt");
	std::string unused;
	while ( std::getline(in, unused) )
   		++numLines;
   	return size = numLines/3;
}

//Save base from file to baseTab[]
void Base::baseUpload() {
	getSize();
	baseOpen(2);
	int i = 0;
	while(i < size) {
		getline(plik,baseTab[i].itemName);
		getline(plik,baseTab[i].itemDescription);
		getline(plik,baseTab[i].itemPlace);
		i++;
	}
	baseClose();
}

void Base::baseOpen(int mode) {
	//get to the base
	switch(mode) {
		case 1:
			//Save to file
			plik.open(type, std::ios::app);
			if(!plik.good())
				std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
			break;
		case 2:
			//Read from file
			plik.open(type, std::ios::in);
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
void Base::saveItem(Item item) {
	getSize();
	size++;
	baseOpen(1);
	plik.write(&item.itemName[0], item.itemName.length());
	plik << '\n';
	plik.write(&item.itemDescription[0], item.itemDescription.length());
	plik << '\n';
	plik.write(&item.itemPlace[0], item.itemPlace.length());
	plik << '\n';
	baseClose();
}