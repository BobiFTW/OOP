#ifndef SHORT_TASK_H
#define SHORT_TASK_H

#include <iostream>
#include "task.hpp"
class ShortTask : public Task {
public:
	ShortTask(std::string _desc, size_t _size, double _progress) : Task(_desc, _size, _progress, 1) {};

	double work(double time);

	void print();
	void print(std::ostream& stream);
};

#endif // !SHORT_TASK_H
