#include "../database/index.cpp"

class UserRepository {
	public:
		User save(User user) {
			if(user.id != -1) {
				for(int j = 0; j < DataBase.size(); j += 1) {
					if(DataBase[j].id == user.id) {
						DataBase[j] = user;
						return user;
					}
				}
			} else {
				user.id = DataBase.size()+1;
				DataBase.push_back(user);
			}

			return user;
		}

		User findOne(int id) {
			for(int j = 0; j < DataBase.size(); j += 1) {
				if(DataBase[j].id == id) {
					return DataBase[j];
				}
			}

			return User();
		}

		User findOne(std::string email) {
			for(int j = 0; j < DataBase.size(); j += 1) {
				if(DataBase[j].email == email) {
					return DataBase[j];
				}
			}

			return User();
		}

		std::vector<User> findAll(int id) {
			std::vector<User> users;

			for(int j = 0; j < DataBase.size(); j += 1) {
				if(DataBase[j].id == id) {
					users.push_back(DataBase[j]);
				}
			}

			return users;
		}

		std::vector<User> findAll(std::string email) {
			std::vector<User> users;

			for(int j = 0; j < DataBase.size(); j += 1) {
				if(DataBase[j].email == email) {
					users.push_back(DataBase[j]);
				}
			}

			return users;
		}

		std::vector<User> findAll() {
			return DataBase;
		}

		User remove(int id) {
			for(int j = 0; j < DataBase.size(); j += 1) {
				if(DataBase[j].id == id) {
					DataBase.erase(DataBase.begin() + j);
					return DataBase[j];
				}
			}

			return User();
		}
};
