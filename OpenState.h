#ifndef OPENSTATE_H
#define OPENSTATE_H

#include "States.h"
#include "Person.h"


class States;

class OpenState : public States {
public:
	OpenState();
	std::string getHeader();
	std::string getFileName();

private:
	std::string stateTitle;
	std::string fileName;
};

#endif