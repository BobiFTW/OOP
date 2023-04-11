#include <iostream>
#include "sorted.h"

int main() {

	Sorted<int> arr;

	for (int i = 0; i < 20; i += 2) {
		arr.add(i);
	}
	std::cout << "Even only:\n";
	arr.print();
	for (int i = 1; i < 20; i += 2) {
		arr.add(i);
	}
	std::cout << "All:\n";
	arr.print();
	for (int i = 0; i < 20; i += 3) {
		arr.remove(i);
	}
	std::cout << "Without multiples of 3:\n";
	arr.print();

	return 0;
}