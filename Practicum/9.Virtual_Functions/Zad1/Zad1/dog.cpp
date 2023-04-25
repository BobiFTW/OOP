#include "animal.hpp"
#include "dog.hpp"

Dog& Dog::operator=(Dog const& other) {
	if (this != &other) {
		Animal::operator=(other);
	}

	return *this;
}

Dog& Dog::operator=(Dog&& other) {
	if (this != &other) {
		Animal::operator=(std::move(other));
	}

	return *this;
}

Dog::~Dog() {}

void Dog::talk() {
	std::cout << "Woof woof\n";
}
