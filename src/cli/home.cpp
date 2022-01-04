#include <iostream>
#include <tuple>

#include "./inputs.cpp"

void Home() {
	int option = 0;

	std::cout << std::endl;
	std::cout << "  =======================" << std::endl;
	std::cout << "    Welcome to the CLI!  " << std::endl;
	std::cout << "  =======================" << std::endl << std::endl;
	std::cout << "  [1] Register" << std::endl;
	std::cout << "  [2] Login" << std::endl;
	std::cout << "  [3] List all users" << std::endl;
	std::cout << "  [4] Exit" << std::endl;

	std::cout << std::endl;

	std::cout << "  > ";
	try {
		std::cin >> option;
	} catch (...) {
		std::cout << "\n  Invalid option." << std::endl;
		return;
	}

	HandleOption(option);

	std::cout << std::endl;
}

