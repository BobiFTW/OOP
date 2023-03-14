#ifndef SET_H
#define SET_H

class Set {
private:

	int* elements;

	int numElements;
	int capacity;

	void resize();

public:

	void copy(const int* elements, int numElements, int capacity);
	void move(Set&& other);
	Set();
	Set(Set const& other);
	Set& operator= (Set const& other);
	~Set();

	Set(Set&& other);
	Set& operator= (Set&& other);
	friend Set& operator+ (Set setL, const Set setR);

	bool addElement(const int element);
	bool deleteElement(const int element);

	void print();

	void setUnion(const Set other_set);
	void setIntersection(const Set other_set);

};

#endif // !SET_H
