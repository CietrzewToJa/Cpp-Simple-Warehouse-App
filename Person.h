#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <fstream>

class Person {
public:
	Person(std::string name, std::string surname, std::string password);
	void logIn(Person person);

private:
	std::string name;
	std::string surname;
	std::string password;
};

#endif