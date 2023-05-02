#define _CRT_SECURE_NO_WARNINGS
#include "user.hpp"
#include <cstring>
#include <iostream>
#include <fstream>

void User::free() {
	delete[] username;
}

void User::copy(const User& other) {
	username = new char[strlen(other.username) + 1];
	strcpy(username, other.username);

}

void User::move(User&& other) {
	username = other.username;

	other.username = nullptr;

}

void User::setUsername(const char* username) {
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void User::updateFile(const char fileName[128]) {
	std::ofstream file;
	file.open(fileName, std::ios::ate);
	file << username << ":\n";

	file.close();
}

User::User() {
	setUsername("");
}

User::User(const char* username) {
	setUsername(username);
}

User::User(const User& other) {
	copy(other);
}

User::User(User&& other) {
	move(std::move(other));
}

User& User::operator=(const User& other) {
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}

User& User::operator=(User&& other) {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

User::~User() {
	free();
}

