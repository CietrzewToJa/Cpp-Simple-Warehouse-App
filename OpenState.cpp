#include "OpenState.h"
#include "Person.h"

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

void OpenState::runOption(Person person, int option) {

	switch(option) {
		case 0:
			exit(0);
			break;
		case 1:
			person.logIn(person);
			break;
		case 2: 
			printf("2\n");
			break;
	};
}