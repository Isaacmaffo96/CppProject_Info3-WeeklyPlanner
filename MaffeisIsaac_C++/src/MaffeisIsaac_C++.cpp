//============================================================================
// Name        : MaffeisIsaac_C++.cpp
// Author      : Isaac Maffeis 1041473
// Version     : 1.24
// Copyright   : 
// Description : Weekly planner
//				In questo main vengono eseguiti vari test funzionali, viene
//				simulato un uso normale da parte dell'utente, poi si vanno a
// 				testare i casi più critici e le eccezioni.
//				Successivamente è presente una fase di simulazione nella quale
//				si interagisce tramite la console.
//				Il funzionamento è il seguente: Viene scelto il profilo
//				fornendo informazioni sulla professione, età, workout e hobby,
//				di seguito il programma crea e mostra il piano settimanale,
//				l'utente poi può procedere a modificare gli eventi di suo interesse
//============================================================================

#include <iostream>
#include <exception>
#include <memory>
#include "event.hpp"
#include "constraints.hpp"
#include "weekManagement.hpp"
#include "day.hpp"
using namespace std;

int main() {
	vector<HobbyEnum> hobbies;
	hobbies.push_back(HobbyEnum::Football);
	hobbies.push_back(HobbyEnum::VideoGames);
	hobbies.push_back(HobbyEnum::Reading);
//	Constraint *c1 = new Constraint(Profession::Worker, 15, true, hobbies);
//	WeekManagement *wm1 = new WeekManagement(*c1);
//	wm1->printWeeklyPlan();
//	//---Test funzionale completo 1 ---
//	Constraint *c2 = new Constraint(Profession::Worker, 25, true, hobbies);
//	WeekManagement *wm2 = new WeekManagement(*c2);
//	wm2->printWeeklyPlan();
//	try {
//		wm2->modifyEvent(20, DayEnum::Monday, 1, "Amici");
//		wm2->modifyEvent(17, DayEnum::Wednesday, 2, "Amici");
//		wm2->modifyEvent(23, DayEnum::Thursday, 1, "Amici");
//		wm2->modifyEvent(18, DayEnum::Friday, 1, "Golf");
//		wm2->modifyEvent(21, DayEnum::Friday, 3, "Amici");
//		wm2->modifyEvent(22, DayEnum::Saturday, 2, "Amici");
//		wm2->modifyEvent(20, DayEnum::Saturday, 1, "Gara");
//		wm2->modifyEvent(15, DayEnum::Sunday, 1, "Amici");
//		wm2->modifyEvent(0, DayEnum::Sunday, 1, "Amici");
//		// Test eccezioni
////		wm2->modifyEvent(12, DayEnum::Monday, 1, "Amici");	// priorità diversa
////		wm2->modifyEvent(4, DayEnum::Thursday, 1, "Amici"); // priorità diversa
////		wm2->modifyEvent(21, DayEnum::Monday, 2, "Amici");  // durata superiore
////		wm2->modifyEvent(17, DayEnum::Monday, 3, "Amici");  // durata superiore
//	} catch (invalid_argument &e) {
//		cout << "Impossibile modificare l'evento --> " << e.what() << endl;
//	}
//	wm2->printWeeklyPlan();
// //---fine test 1 ---

//	Constraint *c3 = new Constraint(Profession::Worker, 65, false, hobbies);
//	WeekManagement *wm3 = new WeekManagement(*c3);
//	wm3->printWeeklyPlan();
//	Constraint *c4 = new Constraint(Profession::Student, 15, false, hobbies);
//	WeekManagement *wm4 = new WeekManagement(*c4);
//	wm4->printWeeklyPlan();
//	Constraint *c5 = new Constraint(Profession::Student, 25, true, hobbies);
//	WeekManagement *wm5 = new WeekManagement(*c5);
//	wm5->printWeeklyPlan();
//	Constraint *c6 = new Constraint(Profession::Student, 65, false, hobbies);
//	WeekManagement *wm6 = new WeekManagement(*c6);
//	wm6->printWeeklyPlan();

//  // Test da Console
	cout
			<< "Benvenuto in Weekly Planner, organizza la tua settimana in pochi click"
			<< endl;
	cout
			<< "Abbiamo bisogno di alcuni dati per cominciare, per prima cosa è un Lavoratore o uno Studente?\n"
			<< "0 Lavoratore - 1 Studente" << endl;
	int x = 0;
	cin >> x;
	while (x != 0 && x != 1) {
		cout << "Valore non valido: " << "0 Lavoratore - 1 Studente" << endl;
		cin >> x;
	}
	Profession profession = (Profession) x;
	cout << "ora inserisca l'età:" << endl;
	cin >> x;
	while (x < 0 || x > 110) {
		cout << "Inserisca un valore valido" << endl;
		cin >> x;
	}
	int age = x;
	cout << "Vuole svolgere attività fisica (Workout) ? :"
			<< "0 No Workout - 1 Sì Workout" << endl;
	cin >> x;
	while (x != 0 && x != 1) {
		cout << "Valore non valido: " << "0 No Workout - 1 Sì Workout" << endl;
		cin >> x;
	}
	bool workout = (bool) x;
	vector<HobbyEnum> hobbiesInput;
	if (workout) {
		cout << "Per finire selezioni massimo 3 Hobby dalla lista:\n"
				<< "0 Calcio - 1 Corsa - 2 Nuoto - 3 Fotografia - 4 Lettura - 5 Tv - 6 VideoGames - 7 Pittura - 8 Relax - 9 Altro\n"
				<< "10 Per terminare" << endl;
		for (int i = 0; i < 3; i++) {
			cin >> x;
			if (x == 10)
				break;
			while (x < 0 || x > 9) {
				cout << "Valore non valido: "
						<< "0 Calcio - 1 Corsa - 2 Nuoto - 3 Fotografia - 4 Lettura - 5 Tv - 6 VideoGames - 7 Pittura - 8 Relax - 9 Altro\n"
						<< "10 Per terminare" << endl;
				cin >> x;
				if (x == 10)
					break;
			}
			if (x == 10)
				break;
			HobbyEnum hobby = (HobbyEnum) x;
			hobbiesInput.push_back(hobby);
		}
	} else {
		cout << "Per finire selezioni massimo 4 Hobby dalla lista:\n"
				<< "0 Calcio - 1 Corsa - 2 Nuoto - 3 Fotografia - 4 Lettura - 5 Tv - 6 VideoGames - 7 Pittura - 8 Relax - 9 Altro\n"
				<< "10 Per terminare" << endl;
		for (int i = 0; i < 4; i++) {
			cin >> x;
			if (x == 10)
				break;
			while (x < 0 || x > 9) {
				cout << "Valore non valido: "
						<< "0 Calcio - 1 Corsa - 2 Nuoto - 3 Fotografia - 4 Lettura - 5 Tv - 6 VideoGames - 7 Pittura - 8 Relax - 9 Altro\n"
						<< "10 Per terminare" << endl;
				cin >> x;
				if (x == 10)
					break;
			}
			if (x == 10)
				break;
			HobbyEnum hobby = (HobbyEnum) x;
			hobbiesInput.push_back(hobby);
		}
	}
	Constraint *cInput = new Constraint(profession, age, workout, hobbiesInput);
	WeekManagement *wmInput = new WeekManagement(cInput);

	wmInput->printWeeklyPlan();

	cout << "Vuole modificare il planner? 0 No - 1 Sì\n"
			<< "Si possono modificare solo eventi non essenziali (Tempo libero, Hobby, Workout)"
			<< endl;
	cin >> x;
	while (x != 0 && x != 1) {
		cout << "Valore non valido: " << "0 No - 1 Sì" << endl;
		cin >> x;
	}
	if (x == 1) {
		do {
			cout << "Selezioni il giorno: "
					<< "1 Lunedì - 2 Martedì - 3 Mercoledì - 4 Giovedì - 5 Venerdì - 6 Sabato - 7 Domenica"
					<< endl;
			cin >> x;
			while (x < 1 || x > 7) {
				cout << "Valore non valido: "
						<< "1 Lunedì - 2 Martedì - 3 Mercoledì - 4 Giovedì - 5 Venerdì - 6 Sabato - 7 Domenica"
						<< endl;
				cin >> x;
			}
			DayEnum dayenum = (DayEnum) x;
			cout << "Selezionare l'orario di inizio: " << "dalle 00 alle 23"
					<< endl;
			cin >> x;
			while (x < 0 || x > 23) {
				cout << "Valore non valido: " << "dalle 00 alle 23" << endl;
				cin >> x;
			}
			int start = x;
			cout << "Come si chiama il nuovo evento?" << endl;
			string name;
			cin >> name;
			cout << "Selezionare la durata dell'evento: "
					<< "valori interi da 1 a 23" << endl;
			cin >> x;
			while (x < 1 || x > 24) {
				cout << "Valore non valido: " << "valori interi da 1 a 24"
						<< endl;
				cin >> x;
			}
			int duration = x;
			try {
				wmInput->modifyEvent(start, dayenum, duration, name);
				wmInput->printWeeklyPlan();
			} catch (invalid_argument &e) {
				cout<<"Impossibile modificare l'evento --> "<<e.what()<<endl;
			}
			cout << "Vuole modificare altri eventi? 0 No - 1 Sì" << endl;
			cin >> x;
			while (x != 0 && x != 1) {
				cout << "Valore non valido: " << "0 No - 1 Sì" << endl;
				cin >> x;
			}
		} while (x == 1);
	}
	return 0;
}
