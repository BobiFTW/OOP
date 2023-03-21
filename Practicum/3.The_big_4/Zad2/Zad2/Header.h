#ifndef VENDING_MACHINE
#define VENDING_MACHINE

struct Inventory {
	
	unsigned sweets;
	unsigned salts;
	unsigned drinks;

};

class VendingMachine {

	Inventory products;

	char** msg;
	char* id;
	char* adress;

public:

	VendingMachine(Inventory products, );
	VendingMachine();
	VendingMachine(const VendingMachine& other);



};
#endif // !VENDING_MACHINE
