/*
 * Week.hpp
 *      Author: Isaac Maffeis 1041473
 */

#ifndef WEEK_HPP_
#define WEEK_HPP_
#include <iostream>
#include <vector>
#include <memory>
#include "day.hpp"
using namespace std;

class Week{
	vector<shared_ptr<Day>> week;
public:
	Week();
	vector<shared_ptr<Day>> *getWeek(); // restituisce un riferimento al vettore contenente i riferimenti ai giorni della settimana
	void modifyEventWeek(shared_ptr<Event>,int,DayEnum); // permette di modificare un evento fornendo l'evento nuovo, la posizione del vecchio e il giorno
	~Week();
};

#endif /* WEEK_HPP_ */
