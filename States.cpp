#include "States.h"
#include "Base.h"

States::States() {

}

States::~States() {
	
}

//open file
void States::textOpen(std::string fileName) {

	plik.open(fileName, std::ios::in);
	if(!plik.good())
		std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

void States::stateHeader(std::string stateHeader) {
	for(int i = 0; i < 80; i++)
		std::cout << "=";
	std::cout << std::endl;

	int place = (80/2)-(stateHeader.length()/2);
	for(int i = 0; i < place; i++)
		std::cout << " ";

	std::cout << stateHeader << std::endl;

	for(int i = 0; i < 80; i++)
		std::cout << "=";
	std::cout << "\n";
}

void States::stateMenu(std::string fileName) {
	textOpen(fileName);

	optionsNumber = 0;
	std::string line;
	while(getline(plik, line)) {
		std::cout << line << std::endl;
		optionsNumber++;
	}
	plik.close();
}

int States::optionChoose() {
	int answer;

	do {
		std::cout << "Choose an option: ";
		std::cin >> answer;
		if(answer < 0 || answer > optionsNumber-1) {
			std::cout << "Wrong answer, try again! ";
		}
	} while(answer < 0 || answer > optionsNumber-1);

	return answer;
}