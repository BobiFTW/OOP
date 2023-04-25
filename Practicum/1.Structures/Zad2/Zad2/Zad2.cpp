#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
struct Student {
	char name[128];
	char surname[128];
	char EGN[128];
	
	void read() {
		std::cin.getline(name, 128);
		std::cin.getline(surname, 128);
		std::cin.getline(EGN, 128);
	}

	void print() {
		std::cout << name << " " << surname << " " << EGN << "\n";
	}
};


struct University {

	char name[128];
	Student students[128];

	unsigned countStudents = 0;
	
	bool hasStudent(const Student& student) {
		for (unsigned i = 0; i < countStudents; i++) {
			if (strcmp(students[i].name, student.name) == 0) {
				return true;
			}
		}
		return false;
	}

	void addStudent(const  Student& student) {
		if (!hasStudent(student) && countStudents < 128) {
			strcpy(students[countStudents].name, student.name);
			strcpy(students[countStudents].surname, student.surname);
			strcpy(students[countStudents].EGN, student.EGN);
			countStudents++;
		}
	}

	void print() {
		std::cout << name << ":\n";

		for (unsigned i = 0; i < countStudents; i++) {
			students[i].print();
		}
		std::cout << countStudents << "\n";
	}
};

int main() {
	Student s1;
	s1.read();

	Student s2;
	s2.read();

	Student s3;
	s3.read();

	University u;

	std::cin.getline(u.name, 128);

	u.addStudent(s1);
	u.addStudent(s2);
	u.addStudent(s3);

	u.print();

	return 0;
}