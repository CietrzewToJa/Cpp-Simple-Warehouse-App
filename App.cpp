#include "App.h"

void App::run() {

	openStateRun();
	baseStateRun();
}

void App::openStateRun() {
	OpenState state;
	system("clear");

	state.stateHeader(state.getHeader());

	state.stateMenu(state.getFileName());
	int option = state.optionChoose();
	state.runOption(option, ptr);
}

void App::baseStateRun() {
	BaseState state(baseName);
	system("clear");

	state.stateHeader(state.getHeader());	

	while(1) {
		state.stateMenu(state.getFileName());
		int option = state.optionChoose();
		if(option == 0)
			openStateRun();
		system("clear");
		state.stateHeader(state.getHeader());	
		state.runOption(option);
	}
}