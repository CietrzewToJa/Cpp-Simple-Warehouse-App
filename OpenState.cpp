#include "OpenState.h"

OpenState::OpenState() {
	stateHeader = "WELCOME!";
}

std::string OpenState::getHeader() {
	return stateHeader;
}