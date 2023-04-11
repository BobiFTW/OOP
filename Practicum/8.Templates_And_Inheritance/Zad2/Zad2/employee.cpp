#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "employee.h"

void Employee::free() {
	if (this->name != nullptr) {
		delete[] this->name;
	}
}

void Employee::copy(const Employee& other) {
	this->free();
	if (other.name != nullptr) {
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	this->stash = other.stash;
	this->salary = other.salary;
}

void Employee::move(Employee&& other) {
	this->free();
	if (other.name != nullptr) {
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	this->stash = other.stash;
	this->salary = other.salary;

	delete[] other.name;
}

Employee::Employee() {
	this->free();
	this->stash = 0;
	this->salary = 3000;
}

Employee::Employee(char* name, unsigned stash, double salary) {
	this->free();
	if (name != nullptr) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	this->stash = stash;
	this->salary = salary;
}

Employee::Employee(const Employee& other) {
	this->copy(other);
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

Employee::Employee(Employee&& other) {
	this->move(std::move(other));
}

Employee& Employee::operator=(Employee&& other) {
	if (this != &other) {
		this->move(std::move(other));
	}

	return *this;
}
