#include "Person.h"

Person::Person(std::string name, std::string surname, std::string password) {

	this->name = name;
	this->surname = surname;
	this->password = password;
}

void Person::logIn(Person person) {

	std::string answer;

	std::cout << "What's your name?: ";
	std::cin >> answer;
	
}