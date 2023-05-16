#ifndef PREMIUM_H
#define PREMIUM_H

#include <iostream>
#include "user.hpp"

class Premium : User {
private:
	std::string planDesc;
	std::string dateList;
public:
	Premium(const std::string& username, const std::string& password,
		const std::string& planDesc, const std::string& dateList) : User(username, password) {
		this->planDesc = planDesc;
		this->dateList = dateList;
	}

};
#endif // !PREMIUM_H
