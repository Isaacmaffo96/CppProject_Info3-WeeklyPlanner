/*
 * day.cpp
 *      Author: Isaac Maffeis 1041473
 */

#include "day.hpp"

Day::Day(DayEnum name) :
		name(name) {
}

list<shared_ptr<Event>>* Day::getList() {
	return &eventList;
}

string Day::printDay() {
	return enumDaytoString(name) + ":\t" + printEventList();
}

DayEnum Day::getDayEnum() {
	return name;
}

string Day::printEventList() {
	list<shared_ptr<Event>>::const_iterator i;
	string result;
	for (i = eventList.begin(); i != eventList.end(); ++i) {
		shared_ptr<Event> e = *i;
		string s = (*e).print();
		result.append(s);
	}
	return result;
}

void Day::modifyEvent(shared_ptr<Event> e, int t) { // t è la posizione dove effettuare il cambio
	list<shared_ptr<Event>>::iterator i;  // iteratore principale
	list<shared_ptr<Event>>::iterator i2; // iteratore istante precedente
	int k = 0; // k è la posizione effettiva nell'orario a inizio evento k = 10 equivale alle ore 10 inizia l'evento
	int k2 = 0; // posizione di k all'istante precedente (del ciclo for)
	int j = 0; // j è la posizione effettiva nell'orario j = 10 equivale alle ore 10
	for (i = eventList.begin(); i != eventList.end(); ++i) {
		if (k == t) { // la posizione dove effettuare la modifica coincide, grazie a k ci si posiziona sempre a inizio evento
			if (e->getDuration() == (*i)->getDuration()) { // la durata dell'evento coincide
				if (e->getPriority() == (*i)->getPriority()) { // la priorità coincide
					eventList.insert(i, e);	// inserisco il nuovo evento custom
					eventList.remove(*i);	// rimuovo quello al suo posto
				} else
					throw invalid_argument(
							"Non si può cambiare l'evento selezionato perchè ha una priorità diversa");
				break;
			} else if (e->getDuration() < (*i)->getDuration()) { // durata evento da aggiungere inferiore all'evento presente
				if (e->getPriority() == (*i)->getPriority()) { // la priorità coincide
					eventList.insert(i, e);	// inserisco il nuovo evento custom prima del precedente
					(*i)->setDuration((*i)->getDuration() - e->getDuration()); // cambio la durata del precedente
					break;
				} else
					throw invalid_argument(
							"Non si può cambiare l'evento selezionato perchè ha una priorità diversa");
			} else
				throw invalid_argument(
						"Durata superiore all'evento da sostituire");
		} else if (k > t) {	// una volta passato il punto desiderato (evento a cavallo)
			j = k2; // posizione di inizio evento es. j = 10 (Workout inizia alle 10)
			int r = (*i2)->getDuration();	// durata dell'evento di partenza
			for (int h = 1; h <= r; h++) { // per tutte le ore dell'evento
				j++; // incremoento di un ora (es. workout inizia alle 10 e dura più di un ora, controllo le ore 11)
				if (j == t) { // la posizione dove effettuare la modifica coincide, ma siamo a evento in corso
					if (e->getPriority() == (*i2)->getPriority()) { // la priorità coincide
						if (e->getDuration() > (*i2)->getDuration()) // la durata dell'evento è superiore
							throw invalid_argument(
									"Durata superiore all'evento da sostituire");
						if (j + e->getDuration() > 24)
							throw invalid_argument(
									"Giornata superiore alle 24 ore");
						(*i2)->setDuration(h); // cambio la durata del precedente (i2)
						eventList.insert(i, e);	// inserisco il nuovo evento custom in posizione successiva (i)
						if ((h + e->getDuration()) < r) {// l'evento è stato inserito all'interno del precedente
							shared_ptr<Event> e2 ((*i2)->clone()); // creo un clone dell'oggetto
							e2->setDuration(r - (h + e->getDuration()));
							eventList.insert(i, e2); // inserisco la seconda parte dell'evento
						}
					} else
						throw invalid_argument(
								"Non si può cambiare l'evento selezionato perchè ha una priorità diversa");
				}
			}
			return;
		}
		k2 = k;
		k += (*i)->getDuration();
		if (k > 23) { // l'iteratore uscirebbe dal ciclo for, devo controllare l'ultimo elemento
			if (k > t) { // una volta passato il punto desiderato (evento a cavallo) come ultimo evento
				j = k2; // posizione di inizio evento es. j = 10 (Workout inizia alle 10)
				int r = k - k2; // durata dell'evento di partenza
				for (int h = 1; h <= r; h++) { // per tutte le ore dell'evento
					j++; // incremoento di un ora (es. workout inizia alle 10 e dura più di un ora, controllo le ore 11)
					if (j == t) { // la posizione dove effettuare la modifica coincide, ma siamo a evento in corso
						if (e->getPriority() == (*i)->getPriority()) { // la priorità coincide
							if (e->getDuration() > (*i)->getDuration()) // la durata dell'evento è superiore
								throw invalid_argument(
										"Durata superiore all'evento da sostituire");
							if (j + e->getDuration() > 24)
								throw invalid_argument(
										"Giornata superiore alle 24 ore");
							(*i)->setDuration(h); // cambio la durata del precedente
							i2 = i; // copio l'iteratore per non perdere la posizione, incremento poi solo i
							eventList.insert(++i, e); // inserisco il nuovo evento custom in posizione successiva (++i)
							if ((h + e->getDuration()) < r) { // l'evento è stato inserito all'interno del precedente
								shared_ptr<Event> e2 ((*i2)->clone()); // creo un clone dell'oggetto
								e2->setDuration(r - (h + e->getDuration()));
								eventList.insert(i, e2); // inserisco la seconda parte dell'evento, i è già stato incrementato
							}
						} else
							throw invalid_argument(
									"Non si può cambiare l'evento selezionato perchè ha una priorità diversa");
					}
				}
				return;
			}
		}
		i2 = i;	// tengo traccia dell'iteratore all'istante precedente
	}
}

Day::~Day() {
}

string Day::enumDaytoString(DayEnum name) {
	switch (name) {
	case DayEnum::Monday:
		return "Lun";
	case DayEnum::Tuesday:
		return "Mar";
	case DayEnum::Wednesday:
		return "Mer";
	case DayEnum::Thursday:
		return "Gio";
	case DayEnum::Friday:
		return "Ven";
	case DayEnum::Saturday:
		return "Sab";
	case DayEnum::Sunday:
		return "Dom";
	default:
		throw new exception;
	}
	return "error";
}
