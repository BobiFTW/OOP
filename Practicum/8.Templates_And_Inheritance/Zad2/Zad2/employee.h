#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
	char* name;
	unsigned stash;
	unsigned salary;

	void free();
	void copy(const Employee& other);
	void move(Employee&& other);
public:
	Employee();
	Employee(char* name, unsigned stash, double salary);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	Employee(Employee&& other);
	Employee& operator=(Employee&& other);
};
#endif // !EMPLOYEE_H
