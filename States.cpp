#include "States.h"
#include "Base.h"

void States::stateWrite(std::string stateHeader) {
	system("clear");
	for(int i = 0; i < 80; i++)
		std::cout << "=";
	std::cout << std::endl;

	int place = (80/2)-(stateHeader.length()/2);
	for(int i = 0; i < place; i++)
		std::cout << " ";

	std::cout << stateHeader << std::endl;

	for(int i = 0; i < 80; i++)
		std::cout << "=";
	std::cout << std::endl;
}