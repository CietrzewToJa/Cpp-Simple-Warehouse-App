#include "BaseState.h"

BaseState::BaseState() {
	stateTitle = "BASE SETTINGS";
	fileName = "basestate.txt";
}

std::string BaseState::getHeader() {
	return stateTitle;
}

std::string BaseState::getFileName() {
	return fileName;
}

void BaseState::runOption(int option) {

	switch(option) {
		case 0:
			exit(0);
			break;
		case 1:
			printf("2\n");
			break;
		case 2: 
			printf("2\n");
			break;
	};
}