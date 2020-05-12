#ifndef OPENSTATE_H
#define OPENSTATE_H

#include "States.h"

class States;

class OpenState : public States {
public:
	OpenState();
	std::string getHeader();
	bool logIn();

private:
	std::string stateHeader;
};

#endif