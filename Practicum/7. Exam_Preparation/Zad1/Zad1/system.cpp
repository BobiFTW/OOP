#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "system.h"
#include "users.h"

const int SIZE = 12;
void System::resize() {
	
	if (this->userNum + 1 >= this->capacity) {
		this->capacity *= 2;

		User* copyUsers = new User[capacity];
		for (int i = 0; i < userNum; i++) {
			copyUsers[i] = this->user[i];
		}
		if (this->user != nullptr) {
			delete[] this->user;
		}
		this->user = copyUsers;
		delete[] copyUsers;

	}
}

void System::free() {
	if (this->user != nullptr) {
		delete[] this->user;
	}
}

void System::copy(const System& other) {
	this->free();
	this->capacity = other.capacity;
	this->userNum = other.userNum;
	this->user = new User[capacity];
	for (int i = 0; i < this->capacity; i++) {
	this->user[i] = other.user[i];
	}
}

void System::move(System&& other) {
	this->free();

	this->user = other.user;

	other.free();
}

System::System() {
	this->free();
	this->user = nullptr;
	this->capacity = SIZE;
	this->userNum = 0;
}

System::System(const System& other) {
	this->copy(other);
}

System& System::operator=(const System& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

System::System(System&& other) {
	this->move(std::move(other));
}

System& System::operator=(System&& other) {
	if (this != &other) {
		this->move(std::move(other));
	}

	return *this;
}

bool System::addUser(const User& user) {

	for (int i = 0; i < this->userNum; i++) {
		if (this->user[i] == user) {
			return false;
		}
	}

	this->resize();
	this->user[userNum++] = user;

	return true;
}
