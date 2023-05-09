#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "question.hpp"


void Question::setQ(const char* q) {
	if (q != nullptr) {
		if (this->q != nullptr) {
			delete[] this->q;
		}
		this->q = new char[strlen(q) + 1];
		strcpy(this->q, q);
	}
}

void Question::setA(const char* a) {
	if (a != nullptr) {
		if (this->a != nullptr) {
			delete[] this->a;
		}
		this->a = new char[strlen(a) + 1];
		strcpy(this->a, a);
	}
}

void Question::free() {
	delete[] q;
	delete[] a;
}

void Question::copy(const Question& other) {
	setQ(other.q);
	setA(other.a);
}

void Question::move(Question&& other) {
	q = other.q;
	a = other.a;

	other.q = nullptr;
	other.a = nullptr;
}

Question::Question() {
	setQ("");
	setA("");
}

Question::Question(const char* q, const char* a) {
	setQ(q);
	setA(a);
}

Question::Question(const Question& other) {
	copy(other);
}

Question::Question(Question&& other) {
	move(std::move(other));
}

Question& Question::operator=(const Question& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	
	return *this;
}

Question& Question::operator=(Question&& other) {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

Question::~Question() {
	free();
}
