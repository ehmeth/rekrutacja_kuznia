#ifndef _SEKRETERIAT_H_
#define _SEKRETERIAT_H_

#include <string>
#include "Uczen.h"
#include "oddzial.h"
class sekretariat
{
public:
	/*	start - funkcja wywolywana do startu procesu: tworzy obiekt nabor z pliku zewnetrznego
	Arg.we:
	string plik_csv - nazwa pliku wejsciowego z danymi o kandydatach.
	Zwracane:
	true - poprawnie stworzono 6 klas, 
	false - nie udalo sie		
	*/	
	bool start (std::string plik_csv);
	
	/*	stworzOddzialy - funkcja tworzy pliki wynikowe z tablicy t_oddzialy[]
	Arg.we: brak

	Zwracane:
	true  - jesli wszystkie oddzialy sa dodane prawidlowo
	false - jesli chocby jeden z oddzialow nie zapisano
	*/
	bool stworzOddzialy (); 
	
	sekretariat(std::string plik_csv);

private:

	/*t_oddzial - tablica, w ktorej sa wszystkie zamowione przez szkole oddzialy np. oddzialy[0] oznacza oddzial A
	type
		oddzial - klasa, opisujaca oddzialy w gimnazjum, np. oddzia³ A jezykowa ma 20 uczniow. 
	range
		Uczen::wybor::MAX_WYBOR - ostatni element enuma "wybor" z klasy "Uczen.h", oznacza ilosc oddzialow zamowionych przez szkole, 
								z ktorych kandydaci do gimnazjum wybieraja, gdzie beda sie uczyc. 
	*/
	oddzial t_oddzial[Uczen::wybor::MAX_WYBOR]; // TODO: slowo kluczowe "klasa" jest niefortunne
	
};


#endif // _SEKRETERIAT_H_
