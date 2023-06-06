#include <iostream>
#include "task.hpp"
#include "short_task.hpp"

double ShortTask::work(double time) {
	return (time + progress - 1 > 0) ? time - progress : 0;
}

void ShortTask::print() {
	std::cout << "Short, ";
	Task::print();
}

void ShortTask::print(std::ostream& stream) {
	stream << "Short, ";
	Task::print(stream);
}
