#define _CRT_SECURE_NO_WARNINGS
#include "animal.hpp"
#include <iostream>
#include <cstring>

void Animal::copy(Animal const& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Animal::move(Animal&& other) {
	name = other.name;
	other.name = nullptr;
}

Animal::Animal() {
	name = new char[1];
	strcpy(name, "\0");
}

Animal::Animal(const char* name) {
	this->name = new char [strlen(name) + 1];
	strcpy(this->name, name);
}

Animal::Animal(Animal const& other) {
	copy(other);
}

Animal::Animal(Animal&& other) {
	move(std::move(other));
}

Animal& Animal::operator=(Animal const& other) {
	if (this != &other) {
		delete[] name;
		copy(other);
	}

	return *this;
}

Animal& Animal::operator=(Animal&& other) {
	if (this != &other) {
		delete[] name;
		move(std::move(other));
	}

	return *this;
}

Animal::~Animal() {
	delete[] name;
}

void Animal::talk() {
}
