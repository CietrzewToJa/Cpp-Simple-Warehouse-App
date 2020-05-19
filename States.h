#ifndef STATES_H
#define STATES_H

#include <string>
#include <iostream>
#include <fstream>

class States {

public:
	void stateHeader(std::string stateHeader);
	void stateMenu(std::string fileName);
	void textOpen(std::string fileName);
	int optionChoose();

private:
	std::fstream plik;
	int optionsNumber;
};

#endif