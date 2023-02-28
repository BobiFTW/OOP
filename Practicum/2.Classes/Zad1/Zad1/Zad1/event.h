#ifndef EVENT_H
#define EVENT_H
#include "time.h"
class Event {
	private:
		char title[128];
		char organiser[128];
		Time start_time;
		Time end_time;
	public:
		Event();
		Event(char* title, char* organiser, Time start_time, Time end_time);
		Time get_duration();
		bool intersectsWith(const Event other_event) const;
};
#endif // !EVENT_H
