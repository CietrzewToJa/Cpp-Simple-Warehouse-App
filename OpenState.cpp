#include "OpenState.h"

OpenState::OpenState() {
	stateTitle = "WELCOME!";
	fileName = "openstate.txt";
}

std::string OpenState::getHeader() {
	return stateTitle;
}

std::string OpenState::getFileName() {
	return fileName;
}

void OpenState::runOption(int option, std::string *baseName) {

	switch(option) {
		case 0:
			exit(0);
			break;
		case 1:
			std::cout << "Type name of base: ";
			std::cin >> *baseName;
			break;
	};
}