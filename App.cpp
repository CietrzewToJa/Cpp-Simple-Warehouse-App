#include "App.h"
#include "Person.h"
#include "BaseState.h"

void App::run() {

	baseStateRun();
	openStateRun();
	// open.runOption(option);
}

void App::openStateRun() {
	OpenState open;
	Person user("Maciej", "ebe", "bebe");

	open.stateHeader(open.getHeader());
	open.stateMenu(open.getFileName());
	int option = open.optionChoose();
	open.runOption(user, option);
}

void App::baseStateRun() {
	BaseState basestate;

	basestate.stateHeader(basestate.getHeader());
	basestate.stateMenu(basestate.getFileName());
	int option = basestate.optionChoose();
}