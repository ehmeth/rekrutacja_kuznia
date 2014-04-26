#ifndef _SEKRETERIAT_H_
#define _SEKRETERIAT_H_

#include "Uczen.h"
#include "oddzial.h"
#include "Nabor.h"

class sekretariat 
{
public:
	/*	sekretariat(std::string plik_csv)  - konstruktor wywoluje funkcje start(plik_csv);
	Args:
		plik_csv - nazwa pliku z nazwiskami kandydatow do gimnazjum
	*/
	sekretariat(std::string plik_csv);

	/*	start - funkcja wywolywana do startu procesu: tworzy obiekt nabor z pliku zewnetrznego
	Args:
		string plik_csv - nazwa pliku wejsciowego z danymi o kandydatach.
	Return:
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

private:

	/*	t_oddzial - tablica, w ktorej sa wszystkie zamowione przez szkole oddzialy 
		np. oddzialy[0] oznacza oddzial A
	Typ:
		oddzial - klasa, opisujaca oddzialy w gimnazjum, 
		np. oddzia³ A jezykowa ma 20 uczniow. 
	Rozmiar:
		Uczen::wybor::MAX_WYBOR - ostatni element enuma "wybor" z klasy "Uczen.h",
		oznacza ilosc oddzialow zamowionych przez szkole, z ktorych kandydaci wybieraja, 
		gdzie beda sie uczyc. 
	*/
	oddzial t_oddzial[Uczen::MAX_WYBOR]; // TODO: slowo kluczowe "klasa" jest niefortunne
	
	/*	temp_Oddzial - oddzial tymczasowy, do ktorego trafiaja uczniowie nie dodani po preferencjach,
		albo zabraklo miejsca, albo cos nie poszlo itd. 
	*/
	oddzial temp_Oddzial;

	/*	t_iluWOddziale - tablica zawiera odpowidz na pytanie: ilu jest uczniow w oddziale.
		Potrzebna jest do przydzielania uczniow z temp_Oddzialy, do oddzialu o najmniejszej liczbie uczniow
	Typ:
		int
	Rozmiar:
		Uczen::wybor::MAX_WYBOR - tyle ile jest oddzialow
	*/
	int t_iluWOddziale[Uczen::MAX_WYBOR];

	/*	dodajUczniaPoJezyku funkcja dodale ucznia do oddzialu jezykowego. 
		Potrzebna jest, ¿eby sktócic cholernie dluga funkcje start. :)
	Args:

	Return:
		true	jesli dodano kandydato do oddzialu
		false	jesli nie dodano, (nie mam miejsca w oddziale)
	*/
	bool dodajUczniaJezyk(Nabor nowy);

};


#endif // _SEKRETERIAT_H_
