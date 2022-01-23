/*
 * constraints.cpp
 *      Author: Isaac Maffeis 1041473
 */

#include "constraints.hpp"

Constraint::Constraint(Profession profession, int age, bool workout,
		vector<HobbyEnum> hobbies) :
		profession(profession), age(age), workout(workout), hobbies(hobbies) {
	if (hobbies.size() < 4) { // Considerando che 1 hobby dura 2 ore per 3 volte alla settimana c'è spazio per 4 hobby nella settimana
		int i = 0;
		if (workout)
			i = 1;	// oppure solo 3 hobby se si fa workout
		for (i; i < 4 - hobbies.size(); i++)
			this->hobbies.push_back(HobbyEnum::Relax); // se si selezionano meno hobby si aggiunge relax alla lista
	}
}

string Constraint::printProfessions() {
	return "Student, Worker";
}

string Constraint::printProfession() {
	switch (profession) {
	case Profession::Worker:
		return "Lavoratore";
	case Profession::Student:
		return "Studente";
	}
	return "";
}

string Constraint::printHobbies() {
	return "Calcio, Corsa, Nuoto, Fotografia , Lettura, Tv, Gaming, Pittura, Relax,	Altro";
}

string Constraint::printHobby() {
	vector<HobbyEnum>::iterator i;
	string result;
	int k = 0;
	for (i = hobbies.begin(); i != hobbies.end(); ++i) {
		switch (*i) {
		case HobbyEnum::Football:
			result.append(" Calcio");
			break;
		case HobbyEnum::Painting:
			result.append(" Pittura");
			break;
		case HobbyEnum::Photography:
			result.append(" Fotografia");
			break;
		case HobbyEnum::Reading:
			result.append(" Lettura");
			break;
		case HobbyEnum::Relax:
			result.append(" Relax");
			break;
		case HobbyEnum::Running:
			result.append(" Corsa");
			break;
		case HobbyEnum::Swimming:
			result.append(" Nuoto");
			break;
		case HobbyEnum::Tv:
			result.append("Tv");
			break;
		case HobbyEnum::VideoGames:
			result.append(" Gaming");
			break;
		default:
			result.append(" Altro");
			break;
		}
		if (k < hobbies.size() - 1)
			result.append(",");
		else
			result.append(".");
		k++;
	}
	return result;
}

string Constraint::printWorkout(){
	return (workout) ? "Sì" : "No";
}

Profession Constraint::getProfession() {
	return profession;
}
int Constraint::getAge() {
	return age;
}
bool Constraint::getWorkout() {
	return workout;
}

vector<HobbyEnum>* Constraint::getHobbyList() {
	return &hobbies;
}

HobbyEnum Constraint::getHobby(int k) {
	return hobbies.at(k);
}

Constraint::~Constraint(){
}
