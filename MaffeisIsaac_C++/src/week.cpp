/*
 * week.cpp
 *      Author: Isaac Maffeis 1041473
 */

#include "week.hpp"

Week::Week() {
	for (int i = 1; i < 8; i++) {
		shared_ptr<Day> day(new Day((DayEnum)i)); // smart pointer
		week.push_back(day);
	}
}

void Week::modifyEventWeek(shared_ptr<Event> e, int t, DayEnum dayEnum) {
	vector<shared_ptr<Day>>::iterator i;
	for (i = week.begin(); i != week.end(); ++i) {
		if (dayEnum == (*i)->getDayEnum())
			(*i)->modifyEvent(e, t);
	}
}

vector<shared_ptr<Day>>* Week::getWeek() {
	return &week;
}

Week::~Week() {
}
