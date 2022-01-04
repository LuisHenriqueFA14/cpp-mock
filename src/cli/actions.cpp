#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "../repositories/user_repository.cpp"

UserRepository user_repository;

void getUserPassword(std::string *password) {
	termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	std::string s;
	std::getline(std::cin, s);

	std::cout << "  Enter your password: ";
	std::cin >> *password;

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void ListAllUsers() {
	for(int j = 0; j < DataBase.size(); j += 1) {
		printf("  [%d] %s: %s\n", DataBase[j].id, DataBase[j].name.c_str(), DataBase[j].email.c_str());
	}

	printf("\n");

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}

void Register() {
	std::cout << "    Register:" << std::endl;

	std::cout << std::endl;

	std::string name = "";
	std::string email = "";
	std::string password = "";

	std::cout << "  Enter your name: ";
	std::cin >> name;

	std::cout << "  Enter your email: ";
	std::cin >> email;

	getUserPassword(&password);

	User userAlreadyExists = user_repository.findOne(email);

	if(userAlreadyExists.id != -1) {
		std::cout << std::endl;
		std::cout << "\n  User already exists." << std::endl;
		std::cout << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		return;
	}

	User user = User(name, email, password);
	user_repository.save(user);

	std::cout << std::endl;
	std::cout << "\n  User registered." << std::endl;
	std::cout << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

void Login() {
	std::cout << "    Login:" << std::endl;

	std::cout << std::endl;

	std::string email = "";
	std::string password = "";

	std::cout << "  Enter your email: ";
	std::cin >> email;

	getUserPassword(&password);

	User user = user_repository.findOne(email);

	if(user.password == password) {
		printf("\n\n  Welcome, %s!\n", user.name.c_str());
	} else {
		printf("\n\n  Invalid email or password!\n");
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

}

void Exit() {
	std::cout << "  Bye!" << std::endl;
	std::cout << std::endl;
	exit(0);
}
