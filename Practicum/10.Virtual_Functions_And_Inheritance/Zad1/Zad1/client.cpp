#include "client.hpp"
#include "user.hpp"
Client& Client::operator=(const Client& other) {
	if (this != &other) {
		User::operator=(other);
	}

	return *this;
}

Client& Client::operator=(User&& other) {
	if (this != &other) {
		User::operator=(std::move(other));
	}

	return *this;
}

void Client::updateFile() {
	User::updateFile("Clients.txt");
}

void Client::addLandmark(const Landmark& landmark) {
}
