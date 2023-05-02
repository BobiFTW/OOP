#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "user.hpp"
class Employee : public User {
public:
	Employee() : User() {};
	Employee(const char* username) : User(username) {};

	Employee(const Employee& other) : User(other) {};
	Employee(User&& other) : User(std::move(other)) {};


	Employee& operator=(const Employee& other);
	Employee& operator=(User&& other);

	~Employee() {};
	void updateFile();

};
#endif // !EMPLOYEE_H
