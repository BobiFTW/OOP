#define _CRT_SECURE_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "events.h"
#include "users.h"

void User::copy(const User& other) {

	this->free();
	this->username = new char[((other.username != nullptr) ? strlen(other.username) : 0) + 1];
	strcpy(this->username, other.username);

	this->password = new char[((other.password != nullptr) ? strlen(other.password) : 0) + 1];
	strcpy(this->password, other.password);

	this->eventNum = other.eventNum;
	this->capacity = other.capacity;
	this->events = new Event[capacity];

	for (unsigned i = 0; i < eventNum; i++) {
		this->events[i] = other.events[i];
	}
}

void User::resize() {

	if (this->eventNum + 1 >= this->capacity) {
		this->capacity *= 2;

		Event* copyEvents = new Event[capacity];
		for (int i = 0; i < eventNum; i++) {
			copyEvents[i] = this->events[i];
		}
		if(this->events != nullptr){
			delete[] this->events;
		}
		this->events = copyEvents;
		delete[] copyEvents;
	}
}

void User::free() {
	if (this->username != nullptr) {
		delete[] this->username;
	}
	if (this->password != nullptr) {
		delete[] this->password;
	}
	if (this->events != nullptr) {
		delete[] this->events;
	}
}

void User::move(User&& other) {

	this->free();

	this->username = other.username;
	this->password = other.password;
	this->events = other.events;

	other.free();

}

User::User(char* username, char* password, Event* events) {
	if (this->username != nullptr) {
		delete[] this->username;
	}
	this->username = new char[((username != nullptr) ? strlen(username) : 0) + 1];

	if (this->password != nullptr) {
		delete[] this->password;
	}
	this->username = new char[((password != nullptr) ? strlen(password) : 0) + 1];

}

User::User(const User& other) {
	this->copy(other);
}

User& User::operator=(const User& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;

}

User::~User() {
	delete[] username;
	delete[] password;
	delete[] events;
}

User::User(User&& other) {
	this->move(std::move(other));
}

User& User::operator=(User&& other) {

	if (this != &other) {
		this->move(std::move(other));
	}

	return *this;
}
