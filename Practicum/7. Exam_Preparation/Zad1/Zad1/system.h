#ifndef SYSTEM_H
#define SYSTEM_H

#include "users.h"

class System {
private:

	User* user;

	unsigned capacity;
	unsigned userNum;

	void resize();
	void free();
	void copy(const System& other);
	void move(System&& other);

public:

	System();
	System(const System& other);
	System& operator=(const System& other);
	~System();
	System(System&& other);
	System& operator=(System&& other);

	bool addUser(const User& user);


};
#endif // !SYSTEM_H

