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

Set::Set() {

	this->elements = new int[6];

	this->numElements = 0;
	this->capacity = 6;

}

Set::Set(Set const& other) {

	this->elements = other.elements;

	this->numElements = other.numElements;
	this->capacity = other.capacity;

}

Set& Set::operator= (Set const* other) {

	if (this != other) {

		this->elements = other->elements;

		this->numElements = other->numElements;
		this->capacity = other->capacity;

	}

	return *this;

}
Set::~Set() {
	delete this->elements;
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

	int* copyElements = new int[capacity];
	int numCopyElements = 0;
	for (int i = 0; i < this->numElements; i++) {
		if (this->elements[i] != element) {
			copyElements[numCopyElements] = this->elements[i];
			numCopyElements++;
		}
	}

	if (numCopyElements < this->numElements) {
		this->numElements = numCopyElements;
		delete[] this->elements;
		this->elements = copyElements;
		return true;
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

	if (this->capacity < other.capacity) {
		this->capacity = other.capacity;
	}

	if (this->capacity < this->numElements + other.numElements) {
		this->resize();
	}

	int* unionElements = new int[this->capacity];

	for (int i = 0; i < this->numElements; i++) {
		if () {

		}
	}
	
	for (int i = 0; i < this->numElements + other.numElements; i++) {

		if (i < this->numElements) {
			unionElements->addElement(this->elements[i]);
		}
		else {
			unionElements[i] = this->elements[i - this->numElements];
		}

	}

	this->numElements += other.numElements;

}