#ifndef BASESTATE_H
#define BASESTATE_H

#include "States.h"

class States;
class BaseState : public States {
public:
	BaseState();
	std::string getHeader();
	std::string getFileName();
	void runOption(int option);

private:
	std::string stateTitle;
	std::string fileName;
};

#endif