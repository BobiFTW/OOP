#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "string.h"

String::String (const char* str = "") {
	if (this->str != nullptr) {
		delete[] this->str;
	}
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
}

String::String (const String& str) {
	if (this->str != nullptr) {
		delete[] this->str;
	}
	this->str = new char[strlen(str.str) + 1];
	strcpy(this->str, str.str);
}

String& String::operator= (const char* str) {

	String copyStr(str);
	if (this != &copyStr) {
		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->str = new char[strlen(str) + 1];
		strcpy(this->str, str);
	}

	return *this;
}

String& String::operator= (String const& str) {

	if (this != &str) {
		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->str = new char[strlen(str.str) + 1];
		strcpy(this->str, str.str);
	}

	return *this;
}

String::~String() {
	delete this->str;
}

String::String(String&& str) {

	if (this->str != nullptr) {
		delete[] this->str;
	}
	this->str = new char[strlen(str.str) + 1];

	strcpy(this->str, str.str);

	str.str = nullptr;

}

String& String::operator=(String&& str) {

	if (this != &std::move(str)) {

		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->str = new char[strlen(str.str) + 1];

		strcpy(this->str, str.str);

		str.str = nullptr;

	}

	return *this;
}

char String::operator[](unsigned index) {
	return this->str[index];
}

String operator+(const char* lStr, const String& rStr) {
	return  rStr + lStr;
}

String String::operator+(const String& str) const {
	char* copy = new char[strlen(this->str) + strlen(str.str) + 1];
	strcpy(copy, this->str);
	strcat(copy, str.str);
	String s(copy);
	delete[] copy;
	return s;

}

String String::operator+(const char* str) const {
	char* copy = new char[strlen(str) + strlen(this->str) + 1];
	strcpy(copy, str);
	strcat(copy, this->str);
	String s(copy);
	delete[] copy;
	return s;
}