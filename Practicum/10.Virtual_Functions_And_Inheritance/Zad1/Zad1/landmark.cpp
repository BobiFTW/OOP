#define _CRT_SECURE_NO_WARNINGS
#include "landmark.hpp"
#include <cstring>

Landmark::Landmark(double x, double y, const char desc[128]) {
	this->x = x;
	this->y = y;
	strcpy(this->desc, desc);
}

double Landmark::getX() {
	return x;
}

double Landmark::getY() {
	return y;
}

char* Landmark::getDesc() {
	return desc;
}
