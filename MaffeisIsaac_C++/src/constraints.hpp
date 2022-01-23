/*
 * constraints.hpp
 *      Author: Isaac Maffeis 1041473
 */

#ifndef CONSTRAINTS_HPP_
#define CONSTRAINTS_HPP_
#include <iostream>
#include <vector>
using namespace std;

enum Profession {
	Worker = 0, Student = 1,
};

enum HobbyEnum {
	Football = 0,
	Running = 1,
	Swimming = 2,
	Photography = 3,
	Reading = 4,
	Tv = 5,
	VideoGames = 6,
	Painting = 7,
	Relax = 8,
	Other = 9
};

class Constraint {
	Profession profession;
	int age;
	bool workout;
	vector<HobbyEnum> hobbies;
public:
	Constraint(Profession, int, bool, vector<HobbyEnum>);
	Profession getProfession(); // restituisce la professione (tipo enumerativo)
	int getAge();	// restituisce l'età (intero)
	bool getWorkout(); // restituisce la scelta sul workout 0 no 1 si
	vector<HobbyEnum>* getHobbyList(); // restituisce il riferimento al vettore contenente la lista degli hobby selezionati
	HobbyEnum getHobby(int k);  // restituisce il tipo enumerativo hobby
	string printProfessions();	// stampa la lista delle professioni
	string printProfession();	// stampa la professione scelta
	string printHobbies();		// stampa la lista degli hobby disponibili
	string printHobby();		// stampa la lista degli hobby scelta
	string printWorkout();		// stampa la scelta di effettuare workout: si/no
	~Constraint();
};

#endif /* CONSTRAINTS_HPP_ */
