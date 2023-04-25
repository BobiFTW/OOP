#define _CRT_SECURE_NO_WARNINGS
#include "employee.h"
#include "ITspecialist.h"
#include <iostream>
#include <cstring>

void ITSpecialist::copy(const ITSpecialist& other) {
	project = new char[strlen(other.project) + 1];
	strcpy(project, other.project);
}

void ITSpecialist::move(ITSpecialist&& other) {
	project = other.project;
	other.project = nullptr;
}

ITSpecialist& ITSpecialist::operator=(const ITSpecialist& other) {
	if (this != &other) {
		Employee::operator=(other);

		delete[] project;
		copy(other);
	}

	return *this;
}

ITSpecialist& ITSpecialist::operator=(ITSpecialist&& other) {
	if (this != &other) {
		Employee::operator=(std::move(other));

		delete[] project;
		move(std::move(other));
	}

	return *this;
}

ITSpecialist::~ITSpecialist() {
	delete[] project;
}
