#ifndef BLACK_RAISIN_CHOCOLATE_H
#define BLACK_RAISIN_CHOCOLATE_H

#include <iostream>
#include "chocolate.hpp"
#include "black_chocolate.hpp"
#include "raisin_chocolate.hpp"

class BlackRaisinChocolate : virtual public BlackChocolate, virtual public RaisinChocolate<std::string> {
public:
	BlackRaisinChocolate(std::string id, double quantityCocoa = 0.8, double quantityRaisins = 0.2) : BlackChocolate(id, quantityCocoa), RaisinChocolate<std::string>(quantityRaisins) {
		this->id = 'S' + this->id;
	}
};
#endif // !BLACK_RAISIN_CHOCOLATE_H
