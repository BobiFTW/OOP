#ifndef BLACK_CHOCOLATE_H
#define BLACK_CHOCOLATE_H

#include <iostream>
#include "chocolate.hpp"

class BlackChocolate : virtual public Chocolate <std::string> {
protected:
	double quantityCocoa;
	void setQuantityCocoa(double quantityCocoa);

public:
	BlackChocolate(std::string id, double quantityCocoa = 0.8) : Chocolate<std::string>() {
		this->id = id;
		setQuantityCocoa(quantityCocoa);
	}
};
#endif // !BLACK_CHOCOLATE
