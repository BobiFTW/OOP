#include <iostream>
#include "black_chocolate.hpp"
#include "chocolate.hpp"

void BlackChocolate::setQuantityCocoa(double quantityCocoa) {
	if (quantityCocoa < 0) {
		quantityCocoa *= -1;
	}

	this->quantityCocoa = quantityCocoa;
}
