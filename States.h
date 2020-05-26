#ifndef STATES_H
#define STATES_H

#include <string>
#include <iostream>
#include <fstream>

class States {

public:
	States();
	virtual ~States() = 0;
	virtual void stateHeader(std::string stateHeader);
	virtual void stateMenu(std::string fileName);
	virtual void textOpen(std::string fileName);
	int optionChoose();

private:
	std::fstream plik;
	int optionsNumber;
};

#endif