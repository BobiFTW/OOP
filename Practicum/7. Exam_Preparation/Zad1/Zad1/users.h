#ifndef USERS_H
#define USERS_H

#include "events.h"
#include <cstring>

class User {
private:
	char* username;
	char* password;
	Event* events;

	unsigned eventNum;
	unsigned capacity;

	void copy(const User& other);
	void resize();
	void free();
	void move(User&& other);

public:

	User(char* username = nullptr, char* password = nullptr, Event* events = nullptr);
	User(const User& other);
	User& operator=(const User& other);
	~User();
	User(User&& other);
	User& operator=(User&& other);

	bool operator==(const User& other) const;

};


#endif // !USERS_H
