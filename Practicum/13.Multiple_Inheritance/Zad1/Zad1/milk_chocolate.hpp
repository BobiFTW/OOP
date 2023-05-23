#ifndef MILK_CHOCOLATE
#define MILK_CHOCOLATE

#include "chocolate.hpp"
class MilkChocolate : virtual public Chocolate<unsigned> {
protected:
	static unsigned idGenerator;
	double quantityMilk;

	void setQuantityMilk(double quantityMilk);
public:
	MilkChocolate(double quantityMilk = 0.35) : Chocolate() {
		this->id = idGenerator++;
		setQuantityMilk(quantityMilk);
	};
};

#endif // !MILK_CHOCOLATE
