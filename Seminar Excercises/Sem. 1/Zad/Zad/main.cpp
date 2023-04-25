#include <iostream>
#include <cmath>

struct Point2D {
	double x;
	double y;
};

void readPoint(Point2D& p) {
	std::cin >> p.x >> p.y;
}

double dist(const Point2D& p1, const Point2D& p2) {
	double xDist = p1.x - p2.x;
	double yDist = p1.y - p2.y;
	return sqrt(xDist * xDist + yDist * yDist);
}

struct Triangle {
	Point2D a;
	Point2D b;
	Point2D c;
};

void readTriangle(Triangle& t) {
	readPoint(t.a);
	readPoint(t.b);
	readPoint(t.c);
}

double perimenter(const Triangle& t) {
	return dist(t.a, t.b) + dist(t.a, t.c) + dist(t.b, t.c);
}

double area(const Triangle& t) {
	double halfP = perimenter(t) / 2;

	return sqrt(halfP * (halfP - dist(t.a, t.b)) * (halfP - dist(t.a, t.c)) * (halfP - dist(t.b, t.c)));
}

double* getAreas(const Triangle* triangles, unsigned count) {
	double* areas = new double[count];

	for (unsigned i = 0; i < count; i++) {
		areas[i] = area(triangles[i]);
	}

	return areas;
}
void swap(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

void sort(double* areas, unsigned count) {
	for (unsigned i = 0; i < count - 1; i++) {
		for (unsigned p = 0; p < count; p++) {
			if (areas[i] > areas[p]) {
				swap(areas[i], areas[p]);
			}
		}
	}
}

void printAreasSorted(const Triangle* triangles, unsigned count) {
	double* areas = getAreas(triangles, count);

	sort(areas, count);

	for (unsigned i = 0; i < count; i++) {
		std::cout << areas[i] << " ";
	}
	std::cout << "\n";
}
int main() {
	unsigned N;
	std::cin >> N;

	Triangle* t = new Triangle[N];
	for (unsigned i = 0; i < N; i++) {
		readTriangle(t[i]);
	}

	printAreasSorted(t, N);

	delete[] t;
	return 0;
}