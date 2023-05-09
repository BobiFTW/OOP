#include <iostream>
#include "my_vector.hpp"

int addOne(int& a) {
	return ++a;
}

int main() {

	MyVector<int> mv;
	for (unsigned i = 0; i < 20; i++) {
		mv.addElement(i * 3);
	}
	
	try {
		std::cout << mv[5] << "\n";
		std::cout << mv[15] << "\n";

		mv.apply(addOne);

		std::cout << mv[5] << "\n";
		std::cout << mv[15] << "\n";
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}


	return 0;
}