#include <iostream>

class User {
	public:
		int id;
		std::string name;
		std::string email;
		std::string password;

		User(std::string name, std::string email, std::string password) {
			this->id = -1;
			this->name = name;
			this->email = email;
			this->password = password;
		}

		User() {
			this->id = -1;
		}
};
