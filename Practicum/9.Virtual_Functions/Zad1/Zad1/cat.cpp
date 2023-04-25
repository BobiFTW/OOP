#include "animal.hpp"
#include "cat.hpp"

Cat& Cat::operator=(Cat const& other) {
	if (this != &other) {
		Animal::operator=(other);
	}

	return *this;
}

Cat& Cat::operator=(Cat&& other) {
	if (this != &other) {
		Animal::operator=(std::move(other));
	}

	return *this;
}

Cat::~Cat() {}

void Cat::talk() {
	std::cout << "Meow meow\n";
}
