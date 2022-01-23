/*
 * WeekManagement.hpp
 *      Author: Isaac Maffeis 1041473
 */

#ifndef WEEKMANAGEMENT_HPP_
#define WEEKMANAGEMENT_HPP_
#include <iostream>
#include <vector>
#include "week.hpp"
#include "constraints.hpp"
using namespace std;

class WeekManagement {
	Week *week;
	Constraint *constraint;
	unsigned int k = 0;
	int sleepHours;
	int dayHoursAvilable;
	void calculateSleepHours();
	void generatePlanner();
	void createSleepEvent(int, Day*);
	void createEatEvent(int, Day*, Meal);
	void createWorkEvent(int, Day*);
	void createStudyEvent(int, Day*);
	void createGetReadyEvent(int, Day*);
	void createHobbyEvent(int, Day*);
	void createWorkoutEvent(int, Day*);
	void createFreeTimeEvent(int, Day*);
	void workerWeekdays(Day*);
	void workerSaturday(Day*);
	void studentWeekdays(Day*);
	void studentSaturday(Day*);
	void profileSunday(Day*);
public:
	WeekManagement(Constraint*);
	void modifyEvent(int,DayEnum,int,string); // permette di modificare un evento del piano fornendo la posizione del vecchio, il giorno, la durata del nuovo e il nome del nuovo
	void printWeeklyPlan(); // stampa il piano settimanale completo
	~WeekManagement();
};

#endif /* WEEKMANAGEMENT_HPP_ */
