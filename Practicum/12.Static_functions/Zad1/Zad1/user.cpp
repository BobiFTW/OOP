#include <iostream>
#include "user.hpp"

void User::setPassword(const std::string& password) {
	this->password = password;
	unsigned l = password.length();
	for (unsigned i = 0; i < l; i++) {
		switch (password[i]) {
		case 'z': this->password[i] = 'a'; break;
		case 'Z': this->password[i] = 'A'; break;
		case '0': this->password[i] = '?'; break;
		default: {
			if (password[i] >= '1' && password[i] <= '9') {
				this->password[i] = password[i] - 1;
			}
			else if ((password[i] >= 'a' && password[i] <= 'y') || (password[i] >= 'A' && password[i] <= 'Y')) {
				this->password[i] = password[i] + 1;
			}
			else {
				throw std::exception("Invalid password");
			}
		}
		}
	}
}

std::string User::getPassword() {
	return password;
}


User::User(const std::string& username, const std::string& password) {
	id = id_generator++;
	this->username = username;
	setPassword(password);
}

unsigned User::id_generator = 0;

bool User::compare(const std::string& password1, const std::string& password2) {
	User u1("", password1);
	User u2("", password2);

	return u1.getPassword() == u2.getPassword();
}
