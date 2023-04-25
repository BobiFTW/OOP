#include <iostream>
#include "cat.hpp"
#include "dog.hpp"
#include "animal.hpp"

int main() {
	Cat myCat("Meowy");
	Dog myDog("Doggo");

	Animal* animal[] = { &myCat, &myDog };

	for (unsigned i = 0; i < 2; i++) {
		animal[i]->talk();
	}
	return 0;
}