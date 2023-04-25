#ifndef ITSPECIALIST_H
#define ITSPECIALIST_H

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "employee.h"

class ITSpecialist : public Employee {
private:
	char* project;

	void copy(const ITSpecialist& other);
	void move(ITSpecialist&& other);
public:
	ITSpecialist() : Employee() {
		project = new char[1];
		strcpy(project, "\0");
	};

	ITSpecialist(const char* name, unsigned stash, double salary, char* project) : Employee(name, stash, salary) {
		this->project = new char[strlen(project) + 1];
		strcpy(this->project, project);
	};

	ITSpecialist(const ITSpecialist& other) : Employee(other) {
		copy(other);
	};
	ITSpecialist(ITSpecialist&& other) : Employee(std::move(other)) {
		move(std::move(other));
	};

	ITSpecialist& operator=(const ITSpecialist& other);
	ITSpecialist& operator=(ITSpecialist&& other);

	~ITSpecialist();
};
#endif // !ITSPECIALIST_H
