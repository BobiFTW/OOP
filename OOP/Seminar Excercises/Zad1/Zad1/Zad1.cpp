#include <iostream>
#include <cmath>
struct Point {
	double x;
	double y;
};

void readPoint(Point& p) {
	std::cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
	std::cout << p.x << " " << p.y << "\n";
}

double dist(const Point& p1, const Point& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

struct Triangle {
	Point a;
	Point b;
	Point c;
};

void triangleValidation(const Triangle& t) {
	if (dist(t.a, t.b) + dist(t.a, t.c) >= dist(t.b, t.c) 
	|| dist(t.a, t.b) + dist(t.b, t.c) >= dist(t.a, t.c)
	|| dist(t.b, t.c) + dist(t.a, t.c) >= dist(t.a, t.b)) {
		throw std::exception("Triangle doesn't exist");
	}
}

void readTriangle(Triangle& t) {
	readPoint(t.a);
	readPoint(t.b);
	readPoint(t.c);
}

void printTriangle(const Triangle& t) {
	printPoint(t.a);
	printPoint(t.b);
	printPoint(t.c);
}

double perimeter(const Triangle& t) {
	return dist(t.a, t.b) + dist(t.a, t.c) + dist(t.b, t.c);
}

double area(const Triangle& t) {
	const double halfP = perimeter(t) / 2;
	return sqrt(halfP * (halfP - dist(t.a, t.b)) * (halfP - dist(t.a, t.c)) * (halfP - dist(t.b, t.c)));
}

double* getAreas(const Triangle* t, int n) {

	double* areas = new double[n];

	for (int i = 0; i < n; i++) {
		areas[i] = area(t[i]);
	}

	return areas;

}

void sortAreas(double* areas, int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (areas[i] < areas[j]) {
				std::swap(areas[i], areas[j]);
			}
		}
	}

}

void printAreasSorted(const Triangle* triangles, int n) {
	double* areas = getAreas(triangles, n);

	sortAreas(areas, n);
	
	for (int i = 0; i < n; i++) {
		std::cout << areas[i] << " ";
	}

	delete[] areas;
}

int main() {

	int N;
	std::cin >> N;

	Triangle* triangle = new Triangle[N];

	for (int i = 0; i < N; i++) {
		readTriangle(triangle[i]);
	}


	return 0;
}