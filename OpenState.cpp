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