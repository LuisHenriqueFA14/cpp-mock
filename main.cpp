#include <iostream>

#include "src/repositories/user_repository.cpp"

UserRepository userRepository;

void print_user(User user) {
	std::cout << "{"  << std::endl;
	std::cout << "\t" << user.id << std::endl;
	std::cout << "\t" << user.name << std::endl;
	std::cout << "\t" << user.email << std::endl;
	std::cout << "\t" << user.password << std::endl;
	std::cout << "}"  << std::endl;
}

int main() {
	User user1 = User("John", "john@gmail.com", "123456");
	user1 = userRepository.save(user1);

	User user2 = User("Bruh", "bruh@gmail.com", "45676543");
	user2 = userRepository.save(user2);

	User user3 = User("Test", "test@gmail.com", "123456789");
	user3 = userRepository.save(user3);

	print_user(user1);
	print_user(user2);
	print_user(user3);
}
