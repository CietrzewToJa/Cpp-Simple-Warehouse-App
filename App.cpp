#include "App.h"
#include "Person.h"

void App::run() {
	OpenState open;
	Person user("Maciej", "Knapik", "ebe");


	open.stateHeader(open.getHeader());
	open.stateMenu(open.getFileName());
	open.optionChoose();
}