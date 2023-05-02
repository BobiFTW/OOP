#include "employee.hpp"
#include "user.hpp"
Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		User::operator=(other);
	}

	return *this;
}

Employee& Employee::operator=(User&& other) {
	if (this != &other) {
		User::operator=(std::move(other));
	}

	return *this;
}

void Employee::updateFile() {
	User::updateFile("Employees.txt");
}
