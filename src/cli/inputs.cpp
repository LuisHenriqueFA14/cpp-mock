#include <iostream>

#include "./actions.cpp"

void HandleOption(int option) {
	std::cout << std::endl;
	switch (option) {
		case 1:
			Register();
			break;
		case 2:
			Login();
			break;
		case 3:
			ListAllUsers();
			break;
		case 4:
			Exit();
			break;
		default:
			std::cout << "  Invalid option." << std::endl;
			return;
	}
}
