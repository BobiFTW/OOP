#ifndef LANDMARK_H
#define LANDMARK_H

class Landmark {
private:
	double x;
	double y;

	char desc[128];

public:
	Landmark(double x = 0, double y = 0, const char desc[128] = "");

	double getX();
	double getY();
	char* getDesc();

};

#endif // !LANDMARK_H
