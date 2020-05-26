#ifndef APP_H
#define APP_H

#include "OpenState.h"
#include "Base.h"
#include "Person.h"
#include "BaseState.h"
#include "Item.h"

#define WINDOW_WIDTH 100

class App {

public:
	void run();
	void openStateRun();
	void baseStateRun();

private:
};

#endif