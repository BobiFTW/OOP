#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
private:
	char* name;

	void copy(Animal const& other);
	void move(Animal&& other);
public:
	Animal();
	Animal(const char* name);

	Animal(Animal const& other);
	Animal(Animal&& other);

	Animal& operator=(Animal const& other);
	Animal& operator=(Animal&& other);
	
	~Animal();
	virtual void talk() = 0;
};
#endif // !ANIMAL_H
