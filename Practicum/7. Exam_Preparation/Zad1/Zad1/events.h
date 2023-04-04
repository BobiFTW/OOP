#ifndef EVENTS_H
#define EVENTS_H

#include "date.h"
#include "time.h"

class Event {
private:

	char desc[101];
	Date date;
	Time time;

public:
	Event();
	Event(char desc[101], Date date, Time time);

};
#endif // !EVENTS_H
