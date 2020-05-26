#include "App.h"

void App::run() {

	baseStateRun();
	// openStateRun();
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
	BaseState basestate("druzyna.txt");
	system("clear");

	basestate.stateHeader(basestate.getHeader());	

	while(1) {
		basestate.stateMenu(basestate.getFileName());
		int option = basestate.optionChoose();
		system("clear");
		basestate.stateHeader(basestate.getHeader());	
		basestate.runOption(option);
	}
}