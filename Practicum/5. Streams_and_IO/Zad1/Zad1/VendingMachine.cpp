#include <iostream>
#include "VendingMachine.h"

const int CAPACITY = 64;
const int SIZE = 64;
int id = 0;

void Inventory::changeSalty(int quantity) {
	
	if (quantity < 0) {
		this->salty = 0;
	}

	this->salty = quantity;

};

void Inventory::changeSweets(int quantity) {

	if (quantity < 0) {
		this->sweet = 0;
	}

	this->sweet = quantity;

};

void Inventory::changeDrinks(int quantity) {

	if (quantity < 0) {
		this->drinks = 0;
	}

	this->drinks = quantity;

};

void Inventory::print() {
	std::cout << "Salty: " << salty << "\nSweet: " << sweet << "\nDrinks: " << drinks << std::endl;
}

VendingMachine::VendingMachine() {
	this->id = id++;
	this->address = nullptr;
	this->inventory.salty = 0;
	this->inventory.sweet = 0;
	this->inventory.drinks = 0;
	this->warningMessages = nullptr;
	this->numWarningMsgs = 0;
	this->capacity = CAPACITY;
}

VendingMachine::VendingMachine(char* address, Inventory inventory) {
	this->id = id++;
	this->address = address;
	this->inventory = inventory;
	this->warningMessages = nullptr;
	this->numWarningMsgs = 0;
	this->capacity = CAPACITY;
	while (capacity < inventory.salty + inventory.sweet + inventory.drinks) {
		capacity *= 2;
	}
}

VendingMachine::VendingMachine(VendingMachine const& other) {
	this->id = id++;
	this->address = other.address;
	this->inventory = other.inventory;
	this->warningMessages = other.warningMessages;
	this->numWarningMsgs = other.numWarningMsgs;
	this->capacity = other.capacity;
}

VendingMachine::VendingMachine(VendingMachine&& other) {
	
	this->id = id++;
	this->address = other.address;
	this->inventory = other.inventory;
	this->warningMessages = other.warningMessages;
	this->numWarningMsgs = other.numWarningMsgs;
	this->capacity = other.capacity;

	other.address = nullptr;
	other.inventory = { 0, 0, 0 };
	other.warningMessages = nullptr;
	other.numWarningMsgs = 0;
	other.capacity = 0;

}

VendingMachine& VendingMachine::operator=(VendingMachine const& other) {
	if (this != &other) {

		this->id = id++;
		this->address = other.address;
		this->inventory = other.inventory;
		this->warningMessages = other.warningMessages;
		this->numWarningMsgs = other.numWarningMsgs;
		this->capacity = other.capacity;

	}

	return *this;
}

VendingMachine::~VendingMachine() {
	delete[] this->address;
	delete[] this->warningMessages;
}

bool compMachinesByID(const VendingMachine v1, const VendingMachine v2) {
	return v1.id == v2.id;
}

void VendingController::addVendingMachine(VendingMachine machine) {
	
	if (numMachines + 1 >= this->capacity) {
		this->capacity *= 2;

		VendingMachine* VendingMachineList = new VendingMachine[capacity];
		for (int i = 0; i < numMachines; i++) {
			VendingMachineList[i] = this->vendingMachineList[i];
		}

		delete[] this->vendingMachineList;
		this->vendingMachineList = VendingMachineList;

	}

	bool containsMachine = false;

	for (int i = 0; i < numMachines; i++) {
		if (compMachinesByID(this->vendingMachineList[i], machine)) {
			containsMachine = true;
		}
	}

	if (!containsMachine) {
		vendingMachineList[numMachines++] = machine;
	}

}