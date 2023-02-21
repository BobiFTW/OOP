#include <iostream>

struct Time {

	int hour;
	int minute;
	int second;
	Time get_difference(const Time other_time) const {

		int h, m, s;
		bool asc;
		if (hour < other_time.hour) {
			asc = true;
		}
		else if(hour > other_time.hour){
			asc = false;
		}
		else {

			if (minute < other_time.minute) {
				asc = true;
			}
			else if (minute > other_time.minute) {
				asc = false;
			}
			else {

				if (second < other_time.second) {
					asc = true;
				}
				else {
					asc = false;
				}

			}

		}

		if (asc) {

			h = other_time.hour - hour;
			m = other_time.minute - minute;
			s = other_time.second - second;

		}
		else {

			h = hour - other_time.hour;
			m = minute - other_time.minute;
			s = second - other_time.second;

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

};

struct Event {
	
	char title[128];
	char organiser[128];
	Time start_time;
	Time end_time;
	Time get_duration() {
		return start_time.get_difference(end_time);
	}

};

Time start_time;
Time end_time;
Time durr = start_time.get_difference(end_time);

int main() {

	return 0;

}