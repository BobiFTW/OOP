#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "time.h"
#include "event.h"

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
