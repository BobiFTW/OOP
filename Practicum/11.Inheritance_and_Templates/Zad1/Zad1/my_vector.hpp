#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>

const int CAPACITY_DEFF = 64;
template <typename T>
class MyVector {
private:
	T* dynArr;

	unsigned count = 0;
	unsigned capacity = CAPACITY_DEFF;

	void resize(unsigned capactity);

	void copy(const MyVector<T>& other);
	void move(MyVector<T>&& other);
public:
	MyVector(unsigned capacity = CAPACITY_DEFF);

	MyVector(const MyVector<T>& other);
	MyVector(MyVector<T>&& other);

	MyVector<T>& operator=(const MyVector<T>& other);
	MyVector<T>& operator=(MyVector<T>&& other);

	~MyVector();

	void addElement(T element);

	T& operator[](unsigned index);

	template <typename R>
	R apply(R(*func) (T&));
};

template<typename T>
inline void MyVector<T>::resize(unsigned capactity) {
	if (this->capacity < capacity) {
		this->capacity = capacity;
		T* copyArr = new T[this->capacity];
		for (unsigned i = 0; i < count; i++) {
			copyArr[i] = dynArr[i];
		}
		delete[] dynArr;
		dynArr = copyArr;

		copyArr = nullptr;
	}
}

template<typename T>
inline void MyVector<T>::copy(const MyVector<T>& other) {
	count = other.count;
	capacity = other.capacity;

	dynArr = new T[capacity];
	for (unsigned i = 0; i < count; i++) {
		dynArr[i] = other.dynArr[i];
	}
}

template<typename T>
inline void MyVector<T>::move(MyVector<T>&& other) {
	count = other.count;
	capacity = other.capacity;

	dynArr = other.dynArr;
	other.dynArr = nullptr;
}

template<typename T>
inline MyVector<T>::MyVector(unsigned capacity) {
	this->capacity = capacity;
	dynArr = new T[this->capacity];
	count = 0;
}

template<typename T>
inline MyVector<T>::MyVector(const MyVector<T>& other) {
	copy(other);
}

template<typename T>
inline MyVector<T>::MyVector(MyVector<T>&& other) {
	move(std::move(other));
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other) {
		delete[] dynArr;
		copy(other);
	}

	return *this;
}
template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other) {
	if (this != &other) {
		delete[] dynArr;
		move(std::move(other));
	}

	return *this;
}
template<typename T>
inline MyVector<T>::~MyVector() {
	delete[] dynArr;
}
template<typename T>
inline void MyVector<T>::addElement(T element) {
	resize(count + 1);
	dynArr[count++] = element;

}
template<typename T>
inline T& MyVector<T>::operator[](unsigned index) {

		if (index >= capacity) {
			throw std::exception("Exception thrown: Index out of bounds");
		}

		return dynArr[index];

}

template<typename T>
template<typename R>
inline R MyVector<T>::apply(R(*func)(T&)) {
	for (unsigned i = 0; i < count; i++) {
		func(dynArr[i]);
	}
	return 0;
}

#endif // !MY_VECTOR_H

