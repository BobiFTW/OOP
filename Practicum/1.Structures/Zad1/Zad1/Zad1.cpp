#include <iostream>
#include <cstring>

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

	void set_time() {
		std::cin >> hour >> minute >> second;
	}

	void print_time() {
		std::cout << hour << " " << minute << " " << second;
	}

};

struct Event {
	
	char title[128];
	char organiser[128];
	Time start_time;
	Time end_time;
	Time get_duration() {
		return start_time.get_difference(end_time);
	}

	void setEvent() {
		std::cout << "Title: ";
		std::cin.getline(title, 128);
		std::cout << "Organiser: ";
		std::cin.getline(organiser, 128);
		std::cout << "Start time: ";
		start_time.set_time();
		std::cout << "End time: ";
		end_time.set_time();
	}
};

int main() {

	//2. b)
	std::cout << "Sample event\n";
	Event sample;
	sample.setEvent();

	std::cout << "n: ";
	unsigned n;
	std::cin >> n;

	Event* events = new Event[n];
	Time durationTotal{ 0, 0, 0 };

	//2. v)

	for (unsigned i = 0; i < n; i++) {

		std::cin.ignore();
		events[i].setEvent();

		durationTotal.second += events[i].get_duration().second;
		durationTotal.minute += events[i].get_duration().minute;
		durationTotal.hour += events[i].get_duration().hour;

	}

	while (durationTotal.second >= 60) {
		durationTotal.minute++;
		durationTotal.second -= 60;
	}

	while (durationTotal.minute >= 60) {
		durationTotal.hour++;
		durationTotal.minute -= 60;
	}

	durationTotal.print_time();

	delete[] events;

	return 0;

}