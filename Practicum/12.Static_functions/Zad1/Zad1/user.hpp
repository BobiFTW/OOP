#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

class User {
private:
	static unsigned id_generator;
	unsigned id;
	std::string username;
	std::string password;

	void setPassword(const std::string& password);
public:

	std::string getPassword();
	
	User(const std::string& username = "", const std::string& password = "");

	static bool compare(const std::string& password1, const std::string& password2);
};


#endif // !USERS_H
