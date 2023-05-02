#include <iostream>
#include "client.hpp"
#include "employee.hpp"
int main() {
	Client cl1("PEshoooOOO!");
	Employee em1("GOshoooOOO!");
	cl1.updateFile();
	em1.updateFile();

	return 0;
}