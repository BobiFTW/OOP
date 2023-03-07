#ifndef SET_H
#define SET_H

class Set {
private:

	int* elements;

	int numElements;
	int capacity;

	void resize();

public:

	Set();
	Set(Set const& other_set);
	Set& operator= (Set const* other_set);
	~Set();

	bool addElement(const int element);
	bool deleteElement(const int element);

	void print();

	void setUnion(const Set other_set);

};	

#endif // !SET_H
