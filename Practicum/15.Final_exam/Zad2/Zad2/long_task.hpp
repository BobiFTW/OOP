#ifndef LONG_TASK_H
#define LONG_TASK_H

#include <iostream>
#include "task.hpp"

class LongTask : public Task {
public:
	LongTask(std::string _desc, size_t _size, double _progress, double _time) : Task(_desc, _size, _progress, _time) {};

	double work(double time);

	void print();
	void print(std::ostream& stream);
};
#endif // !LONG_TASK_H
