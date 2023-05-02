#ifndef CLIENT_H
#define CLIENT_H

#include "user.hpp"
#include "landmark.hpp"
class Client : public User {
public:
	Client() : User() {};
	Client(const char* username) : User(username) {};

	Client(const Client& other) : User(other) {};
	Client(User&& other) : User(std::move(other)) {};


	Client& operator=(const Client& other);
	Client& operator=(User&& other);

	~Client() {};
	void updateFile();
	void addLandmark(const Landmark& landmark);
};
#endif // !CLIENT_H
