#include <iostream>
#include "milk_chocolate.hpp"
#include "chocolate.hpp"

unsigned MilkChocolate::idGenerator = 0;

void MilkChocolate::setQuantityMilk(double quantityMilk) {
	if (quantityMilk < 0) {
		quantityMilk *= -1;
	}
	this->quantityMilk = quantityMilk;
}
