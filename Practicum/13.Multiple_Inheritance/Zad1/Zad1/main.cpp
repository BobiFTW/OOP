#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "chocolate.hpp"
#include "milk_chocolate.hpp"
#include "black_chocolate.hpp"
#include "raisin_chocolate.hpp"
#include "milk_raisin_chocolate.hpp"
#include "black_raisin_chocolate.hpp"

int main() {

	MilkChocolate* mc[20];
	for (unsigned i = 0; i < 20; i++) {
		mc[i] = (i % 5 == 0) ? new MilkRaisinChocolate() : new MilkChocolate();
	}

	BlackChocolate* bc[20];
	for (unsigned i = 0; i < 20; i++) {
		char strnmb[5];
		_itoa(i, strnmb, 5);
		bc[i] = (i % 5 == 0) ? new BlackRaisinChocolate("id" + (std::string) strnmb) : new BlackChocolate("id" + (std::string) strnmb);
	}

	for (unsigned i = 0; i < 20; i++) {
		delete[] mc[i];
		delete[] bc[i];
	}
	return 0;
}