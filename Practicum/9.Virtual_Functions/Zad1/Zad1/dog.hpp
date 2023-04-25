#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "animal.hpp"
class Dog : public Animal {
public:
	Dog(const char* name = "") : Animal(name) {};

	Dog(Animal const& other) : Animal(other) {};
	Dog(Animal&& other) : Animal(std::move(other)) {};

	Dog& operator=(Dog const& other);
	Dog& operator=(Dog&& other);

	~Dog();

	void talk();

};
#endif // !DOG_H
