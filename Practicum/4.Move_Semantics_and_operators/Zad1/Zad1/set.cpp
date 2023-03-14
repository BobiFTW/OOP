#include <iostream>
#include "set.h"

void Set::resize() {

	this->capacity *= 2;
	int* copyElements = new int[this->capacity];

	for (int i = 0; i < this->numElements; i++) {
		copyElements[i] = this->elements[i];
	}

	delete[] this->elements;
	this->elements = copyElements;
}

void Set::copy(int const* elements, int numElements, int capacity) {
	this->capacity = capacity;
	this->numElements = numElements;

	if (this->elements != nullptr) {
		delete[] this->elements;
	}
	this->elements = new int[this->capacity];
	for (int i = 0; i < this->numElements; i++) {
		this->elements[i] = elements[i];
	}
}

void Set::move(Set&& other) {

	this->elements = other.elements;

	this->capacity = capacity;
	this->numElements = numElements;


	other.elements = nullptr;
	other.capacity = 0;
	other.numElements = 0;

}
Set::Set() {

	this->elements = new int[6];

	this->numElements = 0;
	this->capacity = 6;

}

Set::Set(Set const& other) {
	this->copy(other.elements, other.numElements, other.capacity);
}

Set& Set::operator= (Set const& other) {
	if (this != &other) {
		this->copy(other.elements, other.numElements, other.capacity);
	}

	return *this;
}

Set::~Set() {
	delete this->elements;
}

Set::Set(Set&& other) {
	this->move(std::move(other));
}

Set& Set::operator=(Set&& other) {

	if (this != &other) {
		this->move(std::move(other));
	}

	return *this;
}

Set& operator+ (Set setL, const Set setR) {

	setL.numElements += setR.numElements;
	if (setL.capacity > setR.capacity) {
		setL.capacity = setR.capacity;
	}
	if (setL.numElements >= setL.capacity) {
		setL.resize();
	}

	for (int i = 0; i < setR.numElements; i++) {
		setL.addElement(setR.elements[i]);
	}

	return setL;

}

bool Set::addElement(const int element) {

	if (this->numElements + 1 > this->capacity) {
		this->resize();
	}

	for (int i = 0; i < numElements; i++) {
		if (this->elements[i] == element) {
			return false;
		}
	}

	this->elements[numElements++] = element;

	return true;

}

bool Set::deleteElement(const int element) {

	for (int i = 0; i < this->numElements; i++) {
		if (this->elements[i] != element) {
			for (int j = i + 1; j < this->numElements; j++) {
				this->elements[j - 1] = this->elements[j];
			}
			this->numElements--;
			return true;
		}
	}

	return false;

}

void Set::print() {

	std::cout << " Elements: " << this->numElements << "\n";
	for (int i = 0; i < this->numElements; i++) {
		std::cout << this->elements[i] << " ";
	}

	std::cout << "\n";
	std::cout << "Capacity: " << this->capacity << "\n";

}

void Set::setUnion(const Set other) {

	for (int i = 0; i < other.numElements; i++) {
		this->addElement(other.elements[i]);
	}

}

void Set::setIntersection(const Set other) {

	for (int i = 0; i < other.numElements; i++) {
		int j = 0;
		while (j < other.numElements && this->elements[i] != other.elements[j]) {
			j++;
		}
		if (j == other.numElements) {
			this->deleteElement(elements[i]);
			i--;
		}
	}
}