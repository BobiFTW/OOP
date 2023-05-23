#ifndef MILK_RAISIN_CHOCOLATE_H
#define MILK_RAISIN_CHOCOLATE_H

#include <iostream>
#include "chocolate.hpp"
#include "milk_chocolate.hpp"
#include "raisin_chocolate.hpp"

class MilkRaisinChocolate : virtual public MilkChocolate, virtual public RaisinChocolate<unsigned> {
public:
	MilkRaisinChocolate(double quantityMilk = 0.35, double quantityRaisins = 0.2) : MilkChocolate(quantityMilk), RaisinChocolate(quantityRaisins) {
		this->id += 450000;
	}
};

#endif // !MILK_RAISIN_CHOCOLATE_H
