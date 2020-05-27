#ifndef APP_H
#define APP_H

#include "OpenState.h"
#include "Base.h"
#include "BaseState.h"

class App {

public:
	void run();
	void openStateRun();
	void baseStateRun();
	std::string *ptr = &baseName;

private:
	std::string baseName;
};

#endif