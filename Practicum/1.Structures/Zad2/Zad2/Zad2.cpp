#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

const int SIZE = 256;
struct Student {

	char name[SIZE];
	char surname[SIZE];
	char EGN[SIZE];

	void setStudent() {

		std::cin.getline(name, SIZE);
		std::cin.getline(surname, SIZE);
		std::cin.getline(EGN, SIZE);

	}
};

struct University {
	
	char name[SIZE];
	Student students[SIZE];

	bool hasStudent(const Student student, const unsigned countStudents) const {

		for (unsigned i = 0; i < countStudents; i++) {
			if (strcmp(student.name, students[i].name)) {
				return true;
			}
		}

		return false;

	}

	void addStudent(const Student student, unsigned& countStudents) {

		if (!hasStudent(student, countStudents)) {
			students[countStudents++].setStudent();
		}

	}

};

int main() {



	return 0;

}