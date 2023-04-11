#ifndef SORTED_H
#define SORTED_H

const int SIZE = 64;
template <typename T>
class Sorted {
private:
	T* element;

	unsigned elCount;
	unsigned elCapacity;

	void free() {
		if (this->element != nullptr) {
			delete[] this->element;
		}
	}

	void copy(const Sorted<T>& other) {
		this->elCount = other.elCount;
		this->elCapacity = other.elCapacity;

		this->element = new T[this->capacity];

		for (unsigned i = 0; i < this->elCount; i++) {
			this->element[i] = other.element[i];
		}
	}

	void move(Sorted<T>&& other) {
		this->elCount = other.elCount;
		this->elCapacity = other.elCapacity;
		this->element = other.element;

		other.element = nullptr;
	}
	
	int binSearch(T& key) {
		unsigned l = 0, r = this->elCount - 1;
		unsigned m = (l + r) / 2;
		while (l <= r) {

			if (this->element[m] == key) {
				return m;
			}

			if (this->element[m] < key) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}

			m = (l + r) / 2;
		}

		return -1;
	}

	void resize() {
		this->elCapacity *= 2;
		T* placeholder = new T[this->elCapacity];
		for (int i = 0; i < this->elCapacity; i++) {
			placeholder[i] = this->element[i];
		}

		delete[] this->element;
		this->element = placeholder;
	}

	void insert(unsigned index) {
		for (unsigned i = this->elCount; i >= index; i--) {
			this->element[i + 1] = this->element[i];
		}
	}

public:
	Sorted(){
		this->elCount = 0;
		this->elCapacity = SIZE;

		this->element = new T[this->elCapacity];
	}

	Sorted(const Sorted<T>& other) {
		this->copy(other);
	}

	Sorted<T>& operator=(const Sorted& other) {
		if (this != &other) {
			this->free();
			this->copy(other);
		}

		return *this;
	}

	Sorted(Sorted<T>&& other) {
		this->move(std::move(other));
	}

	Sorted<T>& operator=(Sorted&& other) {
		if (this != &other) {
			this->free();
			this->move(std::move(other));
		}

		return *this;
	}

	~Sorted() {
		this->free();
	}


	void add(T& element) {
		if (this->elCount + 1 >= this->elCapacity) {
			this->resize();
		}


		for (unsigned i = 1; i < this->elCount; i++) {
			if (element < this->element[i]) {
				insert(i);
				this->element[i] = element;
				this->elCount++;
				return;
			}
		}

		this->element[elCount++] = element;
	}

	void remove(T& element) {
		if (binSearch(element) == -1) {
			return;
		}

		for (unsigned i = binSearch(element); i < this->elCount - 1; i++) {
			this->element[i] = this->element[i + 1];
		}
		this->elCount--;
	}

	void print() {
		for (unsigned i = 0; i < this->elCount; i++) {
			std::cout << this->element[i] << "\n";
		}
	}
};

#endif // !SORTED_H
