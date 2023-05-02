#ifndef USER_H
#define USER_H

#include <fstream>


class User {
private:
	char* username;

	void free();
	void copy(const User& other);
	void move(User&& other);

	void setUsername(const char* username);

protected:

public:
	User();
	User(const char* username);
	
	User(const User& other);
	User(User&& other);

	User& operator=(const User& other);
	User& operator=(User&& other);

	~User();

	virtual void updateFile(const char fileName[128]);

};

#endif // !ACCOUNT_H
