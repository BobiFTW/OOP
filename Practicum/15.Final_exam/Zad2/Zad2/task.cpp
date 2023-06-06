#include <cmath>
#include "task.hpp"

void Task::setProgress(double progress) {
	if (progress < 0) {
		progress = 0;
	}
	else if (progress > 1) {
		progress = 1;
	}
	this->progress = progress;
}

void Task::setTime(double time) {
	if (time < 0) {
		time = 0;
	}

	this->time = time;
}

const double EPSILON = 0.001;
bool Task::isFinished() {
	return (abs(progress - 1) < EPSILON);
}

void Task::print() {
	std::cout << desc << " " << size << " " << progress << "\n";
}

void Task::print(std::ostream& stream) {
	stream << desc << " " << size << " " << progress << "\n";
}
