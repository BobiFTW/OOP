#ifndef TIME_H
#define TIME_H

class Time {
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		Time();
		Time(int hours, int minutes, int seconds);
		Time(int timestamp_in_seconds);
		void setHours(int hours);
		int getHours() const;
		void setMinutes(int minutes);
		int getMinutes() const;
		void setSeconds(int seconds);
		int getSeconds() const;
		Time get_difference(const Time other_time) const;
		void print_time() const;
};
#endif // !TIME_H
