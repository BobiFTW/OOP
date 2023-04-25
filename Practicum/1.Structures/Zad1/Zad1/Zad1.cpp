#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

struct Time {
	unsigned hour;
	unsigned minute;
	unsigned second;

	unsigned to_seconds() const {
		unsigned total = second;
		for (unsigned i = 0; i < hour; i++) {
			total += 3600;
		}

		for (unsigned i = 0; i < minute; i++) {
			total += 60;
		}

		return total;
	}
	
	bool exceeds(const Time& other) const {
		return to_seconds() > other.to_seconds();
	}
	
	Time get_diff(const Time& other) const;

	void read() {
		std::cin >> hour >> minute >> second;
	}

	void print() const {
		std::cout << hour << ":" << minute << ":" << second << "\n";
	}

	void add(const Time& other) {
		second += other.second;
		while (second >= 60) {
			minute++;
			second -= 60;
		}
		minute += other.minute;
		while (minute >= 60) {
			hour++;
			minute -= 60;
		}
		hour += other.hour;
	}
};

Time to_time(const unsigned& seconds) {
	Time t = { 0, 0, seconds };

	while (t.second >= 60) {
		t.minute++;
		t.second -= 60;
	}

	while (t.minute >= 60) {
		t.hour++;
		t.minute -= 60;
	}

	return t;
}

Time Time::get_diff(const Time& other) const {
	if (to_seconds() > other.to_seconds()) {
		return to_time(to_seconds() - other.to_seconds());
	}
	return to_time(other.to_seconds() - to_seconds());
}

struct Event {
	char title[128];
	char organiser[128];
	Time start_time;
	Time end_time;

	Time get_duration() const {
		return start_time.get_diff(end_time);
	}

	void read() {
		std::cin.ignore();
		std::cin.getline(title, 128);
		std::cin.getline(organiser, 128);
		start_time.read();
		end_time.read();
	}

	void print() {
		std::cout << title << "\n" << organiser << "\n";
		start_time.print();
		end_time.print();
	}
};

Time total_duration(const Event* events, unsigned count) {
	Time t = { 0, 0, 0 };
	for (unsigned i = 0; i < count; i++) {
		t.add(events[i].get_duration());
	}

	return t;
}

int main() {
	Event a;
	a.read();

	//a.print();

	unsigned n;
	std::cin >> n;

	Event* e = new Event[n];
	for (unsigned i = 0; i < n; i++) {
		e[i].read();
	}
	total_duration(e, n).print();

	delete[] e;
	return 0;
}