#ifndef TASK_H
#define TASK_H

#include <iostream>
class Task {
protected:
	std::string desc;
	size_t size;
	
	double progress;
	void setProgress(double progress);

	double time;
	void setTime(double time);

public:
	Task(std::string _desc, size_t _size, double _progress, double _time) : desc(_desc), size(_size) {
		setProgress(_progress);
		setTime(_time);
	};

	bool isFinished();

	virtual double work(double time) = 0;

	void print();
	void print(std::ostream& stream);

};
#endif // !SIMPLE_TASK_H
