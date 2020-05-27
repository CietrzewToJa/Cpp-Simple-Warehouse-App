#ifndef OPENSTATE_H
#define OPENSTATE_H

#include "States.h"


class States;

class OpenState : public States {
public:
	OpenState();
	std::string getHeader();
	std::string getFileName();
	void runOption(int option, std::string *baseName);

private:
	std::string stateTitle;
	std::string fileName;
};

#endif