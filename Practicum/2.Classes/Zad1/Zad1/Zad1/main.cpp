#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "time.h"
#include "event.h"
Time::Time() {
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::Time(int timestamp_in_seconds) {
	this->seconds = timestamp_in_seconds;
	
	while (this->seconds >= 60) {
		this->minutes++;
		this->seconds -= 60;
	}

	while (this->minutes >= 60) {
		this->hours++;
		this->minutes -= 60;
	}

}

void Time::setHours(const int hours) {
	this->hours = hours;
}

int Time::getHours() const{
	return hours;
}

void Time::setMinutes(const int minutes) {
	this->minutes = minutes;
}

int Time::getMinutes() const {
	return minutes;
}

void Time::setSeconds(const int seconds) {
	this->seconds = seconds;
}

int Time::getSeconds() const {
	return seconds;
}

Time Time::get_difference(const Time other_time) const {

	int h, m, s;
	bool asc;
	if (hours < other_time.hours) {
		asc = true;
	}
	else if (hours > other_time.hours) {
		asc = false;
	}
	else {

		if (minutes < other_time.minutes) {
			asc = true;
		}
		else if (minutes > other_time.minutes) {
			asc = false;
		}
		else {

			if (seconds < other_time.seconds) {
				asc = true;
			}
			else {
				asc = false;
			}

		}

	}

	if (asc) {

		h = other_time.hours - hours;
		m = other_time.minutes - minutes;
		s = other_time.seconds - seconds;

	}
	else {

		h = hours - other_time.hours;
		m = minutes - other_time.minutes;
		s = seconds - other_time.seconds;

	}

	if (s < 0) {
		s += 60;
		m--;
	}

	if (m < 0) {
		m += 60;
		h--;
	}

	Time result{ h, m, s };

	return result;
};

void Time::print_time() const {
	std::cout << hours << ":" << minutes << ":" << seconds;
}

Event::Event() {

	strcpy(this->title, "\0");
	strcpy(this->organiser, "\0");
	this->start_time = Time();
	this->end_time = Time();

}

Event::Event(char* title, char* organiser, Time start_time, Time end_time) {

	strcpy(this->title, title);
	strcpy(this->organiser, organiser);
	this->start_time = start_time;
	this->end_time = end_time;

}

bool Event::intersectsWith(const Event other_event) const {

}


int main() {

	return 0;

}
