#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "animal.hpp"
class Cat : public Animal {
public:
	Cat(const char* name = "") : Animal(name) {};

	Cat(Animal const& other) : Animal(other) {};
	Cat(Animal&& other) : Animal(std::move(other)) {};

	Cat& operator=(Cat const& other);
	Cat& operator=(Cat&& other);

	~Cat();

	void talk();

};
#endif // !Cat_H
