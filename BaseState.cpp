#include "BaseState.h"
// #include "Base.h"

BaseState::BaseState(std::string baseName) {
	stateTitle = "BASE SETTINGS";
	fileName = "basestate.txt";
	this->baseName = baseName;
}

BaseState::~BaseState() {

}

std::string setId(Base base) {
	int Id;
	std::string returnId;
  	std::vector<Item>::iterator it;

	it = base.baseTab.end();
	Id = std::stoi((*it).itemId);
	Id++;
	returnId = std::to_string(Id);

	return returnId;
}

std::string BaseState::getHeader() {
	return stateTitle;
}

std::string BaseState::getFileName() {
	return fileName;
}

void BaseState::runOption(int option) {
	std::string itemId;
	std::vector<Item>::iterator it;
	std::string answer;

	Base base(baseName);

	switch(option) {
		case 1: //Show base
			base.showBase();
			break;
		case 2: //Add new item
			base.newItem();
			break;
		case 3: //Delete item
			std::cout << '\n' << "Type ID of item to delete: ";
			std::cin >> itemId;
			it = base.findItem(itemId);

			std::cout << "Are you sure, you want to delete item? (y/n) ";
			do {
				std::cin >> answer;
			} while(answer != "y" && answer != "n");

			if(answer == "y") {
				base.deleteItem(it); //delete item
			}
			break;
		case 4: //Edit item
			std::cout << '\n' << "Type ID of item to edit: ";
			std::cin >> itemId;
			base.editItem(itemId);
			break;
		case 5: //Find item
			std::cout << '\n' << "Type ID of item to find: ";
			std::cin >> itemId;
			base.findItem(itemId);
			break;
		case 6: //Sort base
			base.baseSort();
			base.showBase();
			break;
	};
}