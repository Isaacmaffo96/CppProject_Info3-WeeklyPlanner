/*
 * weekManagement.cpp
 *      Author: Isaac Maffeis 1041473
 */

#include <memory>
#include "weekManagement.hpp"

WeekManagement::WeekManagement(Constraint *constraints) :
		constraint(constraints) {
	this->week = new Week();
	generatePlanner();
}

void WeekManagement::generatePlanner() {

	vector<shared_ptr<Day>>::const_iterator i;
	calculateSleepHours();

	for (i = week->getWeek()->begin(); i != week->getWeek()->end(); ++i) {
		dayHoursAvilable = 24;
		shared_ptr<Day> d = *i;
		if (constraint->getProfession() == Profession::Worker) {
			if ((*d).getDayEnum() == DayEnum::Saturday)
				workerSaturday(d.get());
			else if ((*d).getDayEnum() == DayEnum::Sunday)
				profileSunday(d.get());
			else
				workerWeekdays(d.get()); // dal Lunedì al Venerdì
		} else if (constraint->getProfession() == Profession::Student) {
			if ((*d).getDayEnum() == DayEnum::Saturday)
				studentSaturday(d.get());
			else if ((*d).getDayEnum() == DayEnum::Sunday)
				profileSunday(d.get());
			else
				studentWeekdays(d.get()); // dal Lunedì al Venerdì
		}
	}
}

void WeekManagement::calculateSleepHours() {
	if (constraint->getAge() < 18)
		sleepHours = 8;
	else if (constraint->getAge() > 17 && constraint->getAge() < 65)
		sleepHours = 7;
	else
		sleepHours = 6;
}

void WeekManagement::workerWeekdays(Day *d) {
	if (sleepHours == 8)
		createSleepEvent(sleepHours - 1, d);
	else if (sleepHours == 6) {
		createFreeTimeEvent(1, d);
		createSleepEvent(sleepHours, d);
	} else
		createSleepEvent(sleepHours, d);
	createGetReadyEvent(1, d);
	createWorkEvent(4, d);
	createEatEvent(1, d, Meal::lunch);
	createWorkEvent(4, d);
	if ((*d).getDayEnum() == DayEnum::Monday
			|| (*d).getDayEnum() == DayEnum::Wednesday
			|| (*d).getDayEnum() == DayEnum::Friday) {
		if (constraint->getWorkout()) {
			createWorkoutEvent(2, d); // workout 3 volte alla settimana per 2 ore il lunedì, mercoledì e venerdì
		}
	}
	if (dayHoursAvilable > 5) {
		createHobbyEvent(2, d);	// aggiungo l'hobby in posizione k nella lista
	}
	createEatEvent(1, d, Meal::dinner);
	if ((*d).getDayEnum() != DayEnum::Friday) {
		createHobbyEvent(2, d); // aggiungo l'hobby in posizione k nella lista
		if (sleepHours == 8) {
			createFreeTimeEvent(1, d);
			createSleepEvent(1, d);
		} else
			createFreeTimeEvent(2, d);
	} else { // venerdì sera tempo libero
		if (sleepHours == 8) {
			createFreeTimeEvent(3, d);
			createSleepEvent(1, d);
		} else
			createFreeTimeEvent(4, d);
	}
	if (dayHoursAvilable < 0)
		throw exception();
}

void WeekManagement::studentWeekdays(Day *d) {
	if (sleepHours == 8)
		createSleepEvent(sleepHours, d);
	else if (sleepHours == 7) {
		createFreeTimeEvent(1, d);
		createSleepEvent(sleepHours, d);
	} else {
		createFreeTimeEvent(1, d);
		createSleepEvent(sleepHours, d);
		createFreeTimeEvent(1, d);
	}
	createGetReadyEvent(1, d);
	createStudyEvent(2, d);
	createFreeTimeEvent(1, d);
	createEatEvent(1, d, Meal::lunch);
	createStudyEvent(2, d);
	if ((*d).getDayEnum() == DayEnum::Monday
			|| (*d).getDayEnum() == DayEnum::Wednesday
			|| (*d).getDayEnum() == DayEnum::Friday) {
		if (constraint->getWorkout()) {
			createWorkoutEvent(2, d); // workout 3 volte alla settimana per 2 ore il lunedì, mercoledì e venerdì
		}
	}
	if (dayHoursAvilable > 7) {
		createHobbyEvent(2, d);
	}
	createStudyEvent(2, d);
	createEatEvent(1, d, Meal::dinner);
	createStudyEvent(1, d);
	createHobbyEvent(2, d);
	createFreeTimeEvent(1, d);
	if (dayHoursAvilable < 0)
		throw exception();
}

void WeekManagement::workerSaturday(Day *d) {
	if (sleepHours == 8)
		createSleepEvent(sleepHours - 1, d);
	else if (sleepHours == 6) {
		createFreeTimeEvent(1, d);
		createSleepEvent(sleepHours, d);
	} else
		createSleepEvent(sleepHours, d);
	createGetReadyEvent(1, d);
	createFreeTimeEvent(1, d);
	createHobbyEvent(2, d);
	createFreeTimeEvent(1, d);
	createEatEvent(1, d, Meal::lunch);
	createHobbyEvent(2, d);
	createFreeTimeEvent(1, d);
	createHobbyEvent(2, d);
	createFreeTimeEvent(1, d);
	createEatEvent(1, d, Meal::dinner);
	createFreeTimeEvent(4, d);
	if (dayHoursAvilable < 0)
		throw exception();
}

void WeekManagement::studentSaturday(Day *d) {
	if (sleepHours == 8)
		createSleepEvent(sleepHours, d);
	else if (sleepHours == 7) {
		createFreeTimeEvent(1, d);
		createSleepEvent(sleepHours, d);
	} else {
		createFreeTimeEvent(1, d);
		createSleepEvent(sleepHours, d);
		createFreeTimeEvent(1, d);
	}
	createGetReadyEvent(1, d);
	createStudyEvent(2, d);
	createHobbyEvent(2, d);
	createEatEvent(1, d, Meal::lunch);
	createStudyEvent(2, d);
	createFreeTimeEvent(1, d);
	createHobbyEvent(2, d);
	createStudyEvent(1, d);
	createEatEvent(1, d, Meal::dinner);
	createFreeTimeEvent(3, d);
	if (dayHoursAvilable < 0)
		throw exception();
}

void WeekManagement::profileSunday(Day *d) {
	createFreeTimeEvent(2, d);
	createSleepEvent(8, d); // domenica 8 ore fisse
	createGetReadyEvent(1, d);
	createFreeTimeEvent(1, d);
	createEatEvent(1, d, Meal::lunch);
	createFreeTimeEvent(6, d);
	createEatEvent(1, d, Meal::dinner);
	if (sleepHours > 7 && constraint->getProfession() == Profession::Worker) {
		createFreeTimeEvent(3, d);
		createSleepEvent(1, d);
	} else
		createFreeTimeEvent(4, d);
	if (dayHoursAvilable < 0)
		throw exception();
}

void WeekManagement::createSleepEvent(int duration, Day *d) {
	shared_ptr<Event> e(new Sleep(duration));
	(*d).getList()->push_back(e);
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::createEatEvent(int duration, Day *d, Meal meal) {
	Event *eat;
	switch (meal) {
	case Meal::lunch:
		eat = new Eat(duration, Meal::lunch);
		break;
	case Meal::dinner:
		eat = new Eat(duration, Meal::dinner);
		break;
	default:
		eat = new Eat(duration, Meal::meal);
		break;
	}
	shared_ptr<Event> e(eat);
	(*d).getList()->push_back(e);
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::createWorkEvent(int duration, Day *d) {
	shared_ptr<Event> e(new Work(duration));
	(*d).getList()->push_back(e);
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::createStudyEvent(int duration, Day *d) {
	shared_ptr<Event> e(new Study(duration));
	(*d).getList()->push_back(e);
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::createGetReadyEvent(int duration, Day *d) {
	shared_ptr<Event> e(new GetReady(duration));
	(*d).getList()->push_back(e);
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::createHobbyEvent(int duration, Day *d) {
	Event *hobby;
	HobbyEnum hobbyEnum = constraint->getHobby(k);
	switch (hobbyEnum) {
	case HobbyEnum::Football:
		hobby = new Hobby(duration, HobbyEnum::Football);
		break;
	case HobbyEnum::Painting:
		hobby = new Hobby(duration, HobbyEnum::Painting);
		break;
	case HobbyEnum::Photography:
		hobby = new Hobby(duration, HobbyEnum::Photography);
		break;
	case HobbyEnum::Reading:
		hobby = new Hobby(duration, HobbyEnum::Reading);
		break;
	case HobbyEnum::Running:
		hobby = new Hobby(duration, HobbyEnum::Running);
		break;
	case HobbyEnum::Swimming:
		hobby = new Hobby(duration, HobbyEnum::Swimming);
		break;
	case HobbyEnum::Tv:
		hobby = new Hobby(duration, HobbyEnum::Tv);
		break;
	case HobbyEnum::VideoGames:
		hobby = new Hobby(duration, HobbyEnum::VideoGames);
		break;
	case HobbyEnum::Relax:
		hobby = new Hobby(duration, HobbyEnum::Relax);
		break;
	default:
		hobby = new Hobby(duration, HobbyEnum::Other);
		break;
	}
	shared_ptr<Event> e(hobby);
	(*d).getList()->push_back(e);
	k++;	// passo al secondo hobby
	if (k == constraint->getHobbyList()->size())
		k = 0;	// riprendo dal primo hobby
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::createWorkoutEvent(int duration, Day *d) {
	shared_ptr<Event> e(new Workout(duration));
	(*d).getList()->push_back(e);
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::createFreeTimeEvent(int duration, Day *d) {
	shared_ptr<Event> e(new FreeTime(duration));
	(*d).getList()->push_back(e);
	dayHoursAvilable = dayHoursAvilable - duration;
}

void WeekManagement::modifyEvent(int t, DayEnum dayEnum, int duration,
		string name) {
	shared_ptr<Event> e(new Custom(duration, name));
	week->modifyEventWeek(e, t, dayEnum);
}

void WeekManagement::printWeeklyPlan() {
	cout << "Weekly Planner, Profilo: " << constraint->printProfession() << ", "
			<< constraint->getAge() << " anni, Workout: "
			<< constraint->printWorkout() << ", Hobby:"
			<< constraint->printHobby() << endl;
	cout
			<< "Ore\t 00-01\t01-02\t02-03\t03-04\t04-05\t05-06\t06-07\t07-08\t08-09\t09-10\t10-11\t11-12\t12-13\t13-14\t14-15\t15-16\t16-17\t17-18\t18-19\t19-20\t20-21\t21-22\t22-23\t23-00"
			<< endl;
	vector<shared_ptr<Day>>::const_iterator i; // non serve effettuare modifiche
	for (i = week->getWeek()->begin(); i != week->getWeek()->end(); ++i) {
		shared_ptr<Day> d = *i;
		cout << (*d).printDay() << endl;
	}
}

WeekManagement::~WeekManagement() {
	delete week;
	delete constraint;
}

