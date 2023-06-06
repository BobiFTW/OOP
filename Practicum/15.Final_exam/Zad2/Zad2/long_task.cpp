#include <iostream>
#include "task.hpp"
#include "long_task.hpp"

double LongTask::work(double time) {
	return (time - this->time * (1 - progress) > 0) ? time - progress : 0;
}

void LongTask::print() {
	std::cout << "Long, ";
	Task::print();
}

void LongTask::print(std::ostream& stream) {
	stream << "Long, ";
	Task::print(stream);
}
