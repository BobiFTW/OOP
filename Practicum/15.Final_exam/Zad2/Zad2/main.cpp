#include <iostream>
#include <iomanip>
#include "long_task.hpp"
#include "short_task.hpp"
#include "task.hpp"

int main() {
	ShortTask t1("Kill child", 10, 0.5);

	std::cout << std::boolalpha << t1.isFinished() << " " << t1.work(2) << "\n";
	t1.print();

	LongTask t2("Brutually annihilate child's entire family", 10, 0.6, 2);

	std::cout << std::boolalpha << t2.isFinished() << " " << t2.work(2) << "\n";
	t2.print();

	return 0;
}