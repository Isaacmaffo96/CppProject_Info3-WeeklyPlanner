/*
 * Event.hpp
 *      Author: Isaac Maffeis 1041473
 */

#ifndef EVENT_HPP_
#define EVENT_HPP_
#include<iostream>
#include "constraints.hpp"
using namespace std;

enum Meal {
	lunch = 0, dinner = 1, meal = 2
};

enum Priority {
	primary = 1, secondary = 2, tertiary = 3
};

class Event {
protected:
	int duration;
	string name;
	string category;
	Priority priority;
public:
	Event(int, string, string, Priority);
//	Event(const Event&);	// copy constructor
	virtual Event* clone() const = 0;	//clonare l'oggetto
	string printEvent();
	Priority getPriority();
	void setDuration(int);
	int getDuration();
	virtual string print()=0;
	virtual ~Event();
};

class Primary: public Event {
public:
	Primary(int duration, string name);
//	virtual string print() override;
	virtual ~Primary();
};

class Sleep: public Primary {
public:
	Sleep(int duration);
	virtual string print() override;
	Event* clone() const {
		return new Sleep(*this);
	}
	~Sleep();
};

class Eat: public Primary {
	Meal meal;
public:
	Eat(int duration);
	Eat(int duration, Meal);
	virtual string print() override;
	Event* clone() const {
		return new Eat(*this);
	}
	~Eat();
};

class Employment: public Event {
public:
	Employment(int duration, string name);
//	virtual string print() override;
	virtual ~Employment();
};

class Work: public Employment {
public:
	Work(int duration);
	virtual string print() override;
	Event* clone() const {
		return new Work(*this);
	}
	~Work();
};

class Study: public Employment {
public:
	Study(int duration);
	virtual string print() override;
	Event* clone() const {
		return new Study(*this);
	}
	~Study();
};

class GetReady: public Employment {
public:
	GetReady(int duration);
	virtual string print() override;
	Event* clone() const {
		return new GetReady(*this);
	}
	~GetReady();
};

class NonEssential: public Event {
public:
	NonEssential(int duration, string name);
//	virtual string print() override;
	virtual ~NonEssential();
};

class Hobby: public NonEssential {
	HobbyEnum hobby;
public:
	Hobby(int duration, HobbyEnum);
	Event* clone() const {
		return new Hobby(*this);
	}
	virtual string print() override;
	~Hobby();
};

class Workout: public NonEssential {
public:
	Workout(int duration);
	virtual string print() override;
	Event* clone() const {
		return new Workout(*this);
	}
	~Workout();
};

class FreeTime: public NonEssential {
public:
	FreeTime(int duration);
	virtual string print() override;
	Event* clone() const {
		return new FreeTime(*this);
	}
	~FreeTime();
};

class Custom: public NonEssential {
public:
	Custom(int duration, string name);
	virtual string print() override;
	Event* clone() const {
		return new Custom(*this);
	}
	~Custom();
};

#endif /* EVENT_HPP_ */
