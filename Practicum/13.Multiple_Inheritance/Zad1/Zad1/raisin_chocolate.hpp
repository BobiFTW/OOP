#ifndef RAISIN_CHOCOLATE_H
#define RAISIN_CHOCOLATE_H

#include "chocolate.hpp"

template <typename T>
class RaisinChocolate : virtual public Chocolate<T> {
protected:
	double quantityRaisins;
	void setQuantityRaisins(double quantityRaisins) {
		if (quantityRaisins < 0) {
			quantityRaisins *= -1;
		}
		this->quantityRaisins = quantityRaisins;
	};
public:
	RaisinChocolate<T>(double quantityRaisins = 0.2) : Chocolate<T>() {
		setQuantityRaisins(quantityRaisins);
	}
};
#endif // !RAISIN_CHOCOLATE_H

