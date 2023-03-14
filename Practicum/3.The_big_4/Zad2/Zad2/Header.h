#ifndef VENDING_MACHINE
#define VENDING_MACHINE

struct Products {
	
	unsigned sweetProducts;
	unsigned saltyProducts;
	unsigned drinks;

};

class VendingMachine {

	Products products;

	char** msg;
	char* id;
	char* adress;

public:

	VendingMachine(Products products, )
	VendingMachine();
	VendingMachine(const VendingMachine& other);



};
#endif // !VENDING_MACHINE
