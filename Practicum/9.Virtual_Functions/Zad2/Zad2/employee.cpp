#define _CRT_SECURE_NO_WARNINGS
#include "employee.h"
#include <iostream>
#include <cstring>

void Employee::setSalary(double salary) {
	if (salary < 780.00) {
		salary = 3000.00;
	}
		this->salary = salary;
}

void Employee::copy(const Employee& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	stash = other.stash;
	salary = other.salary;
}

void Employee::move(Employee&& other) {
	name = other.name;
	other.name = nullptr;

	stash = other.stash;
	salary = other.salary;
}

Employee::Employee() {
	name = new char[1];
	strcpy(name, "\0");

	stash = 0;
	setSalary();
}

Employee::Employee(const char* name, unsigned stash, double salary) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	
	this->stash = stash;
	setSalary(salary);
}

Employee::Employee(const Employee& other) {
	copy(other);
}

Employee::Employee(Employee&& other) {
	move(std::move(other));
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		delete[] name;
		copy(other);
	}

	return *this;
}

Employee& Employee::operator=(Employee&& other){
	if (this != &other) {
		delete[] name;
		move(std::move(other));
	}

	return *this;
}

Employee::~Employee() {
	delete[] name;
}
