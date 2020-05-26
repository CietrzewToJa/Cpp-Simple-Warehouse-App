#ifndef BASESTATE_H
#define BASESTATE_H

#include "States.h"
#include "Base.h"

class States;
class BaseState : public States {
public:
	BaseState(std::string baseName);
	std::string getHeader();
	std::string getFileName();
	void runOption(int option);

private:
	std::string stateTitle;
	std::string fileName;
	std::string baseName;
};

#endif