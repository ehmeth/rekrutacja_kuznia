#ifndef _UCZEN_H_
#define _UCZEN_H_

#include <iostream>
#include <string>

class Uczen
{
	public:
	enum jezyk {angielski = 0, niemiecki, DUNNO};
	enum wybor {UNINITIALIZED=-1, A = 0,B,C,D,E,F,MAX_WYBOR};

	private:
		std::string nazwisko;
		std::string imie;
		int punkty;
		wybor wyborUcznia[3];	// TODO: magic number
		jezyk wyborJezyka;



	public:
			// metoda podaj_nazwisko - zwraca stringa zawierajacego nazwisko i imie ucznia;
		std::string podaj_nazwisko();
			/* metoda liczba_punktow -
			Wartosc zwracana: liczbe punktow ucznia; */
		int podaj_liczba_punktow();
			/* metoda podaj_jezyk -
			Wartosc zwracana: jezyka ucznia - 0 dla angielski, 1 dla niemiecki; */
		jezyk podaj_jezyk();
			/* metoda podaj_wybor -
			Argumenty wejscia: int ktory - przyjmuje wartosc wyboru oddzialu, ktory preferuje uczen.
			Wartosc zwracana: zwraca wybor odzialu preferowany przez ucznia; */
		wybor podaj_wybor(int ktoryWybor);

		Uczen();
		Uczen(std::string aNazwisko,std::string aImie,int aPunkty,jezyk aJezyk,wybor aWybor1,wybor aWybor2,wybor aWybor3); //konstruktor
};
#endif
