/*
 * day.hpp
 *      Author: Isaac Maffeis 1041473
 */

#ifndef DAY_HPP_
#define DAY_HPP_
#include "event.hpp"
#include <iostream>
#include <memory>
#include <list>
using namespace std;

enum DayEnum {
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thursday = 4,
	Friday = 5,
	Saturday = 6,
	Sunday = 7
};

class Day {
	DayEnum name;
	list<shared_ptr<Event>> eventList;
	string enumDaytoString(DayEnum);
	string printEventList();
public:
	Day(DayEnum name);
	DayEnum getDayEnum(); // restituisce il tipo enumerativo relativo al giorno
	list<shared_ptr<Event>>* getList(); // restituisce il riferimento alla lista composta da riferimenti di eventi
	string printDay(); // restituisce una stringa contenente gli eventi di quel giorno
	void modifyEvent(shared_ptr<Event>, int); // permette di modificare un evento del planner, fornendo un riderimento a un evento sostitutivo e la posizone dove effettuare il cambio
	~Day();
};

#endif /* DAY_HPP_ */
