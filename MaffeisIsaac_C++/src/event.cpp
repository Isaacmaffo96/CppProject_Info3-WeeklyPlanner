/*
 * event.cpp
 *      Author: Isaac Maffeis 1041473
 */

#include "event.hpp"

/* --------Event--------*/

Event::Event(int duration, string name, string category, Priority priority) :
		duration(duration), name(name), category(category), priority(priority) {
}

//Event::Event(const Event &other) {	//default
//	duration = other.duration;
//	name = other.name;
//	category = other.category;
//	priority = other.priority;
//}

string Event::print() {
	return "event";
}

Priority Event::getPriority() {
	return priority;
}

string Event::printEvent() {
	return category + ", " + name + ", " + to_string(duration) + "hours.";
}

void Event::setDuration(int k) {
	this->duration = k;
}

int Event::getDuration() {
	return duration;
}

Event::~Event() {
}

/* --------Primary -> Event--------*/

Primary::Primary(int duration, string name) :
		Event(duration, name, "primary", Priority::primary) {
}

//string Primary::print(){
//	return "print primary";
//}

Primary::~Primary() {
}

/* --------Sleep -> Primary -> Event-------*/

Sleep::Sleep(int duration) :
		Primary(duration, "sleep") {
}

Sleep::~Sleep() {
}

string Sleep::print() {
	string result;
	for (int i = 0; i < duration; i++)
		result.append("Dormire\t");
	return result;
}

/* --------Eat -> Primary -> Event--------*/

Eat::Eat(int duration) :
		Primary(duration, "Eat"), meal(Meal::meal) {
}

Eat::Eat(int duration, Meal meal) :
		Primary(duration, "Eat"), meal(meal) {
}

Eat::~Eat() {
}

string Eat::print() {
	string result;
	for (int i = 0; i < duration; i++) {
		if (meal == Meal::lunch)
			result.append("Pranzo\t");
		else if (meal == Meal::dinner)
			result.append("Cena\t");
		else
			result.append("Pasto\t");
	}
	return result;
}

/* --------Employment -> Event--------*/

Employment::Employment(int duration, string name) :
		Event(duration, name, "Employment", Priority::secondary) {
}

//string Employment::print(){
//	return "print employment";
//}

Employment::~Employment() {
}

/* --------Work -> Employment -> Event--------*/

Work::Work(int duration) :
		Employment(duration, "Lavoro") {
}

Work::~Work() {
}

string Work::print() {
	string result;
	for (int i = 0; i < duration; i++)
		result.append("Lavoro\t");
	return result;
}

/* --------Study -> Employment -> Event--------*/

Study::Study(int duration) :
		Employment(duration, "Studiare") {
}

Study::~Study() {
}

string Study::print() {
	string result;
	for (int i = 0; i < duration; i++)
		result.append("Study\t");
	return result;
}

/* --------GetReady -> Employment -> Event--------*/

GetReady::GetReady(int duration) :
		Employment(duration, "GetReady") {
}

GetReady::~GetReady() {
}

string GetReady::print() {
	string result;
	for (int i = 0; i < duration; i++)
		result.append("Prepar.\t");
	return result;
}

/* --------NonEssential -> Event--------*/

NonEssential::NonEssential(int duration, string name) :
		Event(duration, name, "Non Essential", Priority::tertiary) {
}

//string NonEssential::print(){
//	return "print Non Essential";
//}

NonEssential::~NonEssential() {
}

/* --------Hobby -> NonEssential -> Event--------*/

Hobby::Hobby(int duration, HobbyEnum hobby) :
		NonEssential(duration, "Hobby"), hobby(hobby) {
}

Hobby::~Hobby() {
}

string Hobby::print() {
	string result;
	for (int i = 0; i < duration; i++) {
		if (hobby == HobbyEnum::Football)
			result.append("Calcio\t");
		else if (hobby == HobbyEnum::Painting)
			result.append("Pittura\t");
		else if (hobby == HobbyEnum::Photography)
			result.append("Fotogr.\t");
		else if (hobby == HobbyEnum::Reading)
			result.append("Lettura\t");
		else if (hobby == HobbyEnum::Running)
			result.append("Corsa\t");
		else if (hobby == HobbyEnum::Swimming)
			result.append("Nuoto\t");
		else if (hobby == HobbyEnum::VideoGames)
			result.append("Gaming\t");
		else if (hobby == HobbyEnum::Tv)
			result.append("Tv\t");
		else if (hobby == HobbyEnum::Relax)
			result.append("Relax\t");
		else
			result.append("Hobby\t");
	}
	return result;
}

/* --------Workout -> NonEssential -> Event--------*/

Workout::Workout(int duration) :
		NonEssential(duration, "Workout") {
}

Workout::~Workout() {
}

string Workout::print() {
	string result;
	for (int i = 0; i < duration; i++)
		result.append("Workout\t");
	return result;
}

/* --------FreeTime -> NonEssential -> Event--------*/

FreeTime::FreeTime(int duration) :
		NonEssential(duration, "Free") {
}

FreeTime::~FreeTime() {
}

string FreeTime::print() {
	string result;
	for (int i = 0; i < duration; i++)
		result.append(name + "\t");
	return result;
}

/* --------Custom -> NonEssential -> Event--------*/

Custom::Custom(int duration, string name) :
		NonEssential(duration, name) {
}

Custom::~Custom() {
}

string Custom::print() {
	string result;
	for (int i = 0; i < duration; i++) {
		if (name.length() > 7)
			result.append(name.substr(0, 6) + "\t");
		else
			result.append(name + "\t");
	}
	return result;
}
