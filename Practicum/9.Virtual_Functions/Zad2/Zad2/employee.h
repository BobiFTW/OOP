#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
	char* name;
	unsigned stash;
	double salary;

	void setSalary(double salary = 3000);

	void copy(const Employee& other);
	void move(Employee&& other);
public:

	Employee();
	Employee(const char* name, unsigned stash, double salary);

	Employee(const Employee& other);
	Employee(Employee&& other);

	Employee& operator=(const Employee& other);
	Employee& operator=(Employee&& other);

	~Employee();

};
#endif // !EMPLOYEE_H
