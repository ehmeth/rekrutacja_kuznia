#ifndef _UCZEN_H_
#define _UCZEN_H_

#include <iostream>
#include <string>
#include "sekretariat.h"

class Uczen
{
	public:
	enum jezyk {angielski = 0, niemiecki, DUNNO};
	enum wybor {UNINITIALIZED=-1, A = 0,B,C,D,E,F,MAX_WYBOR};
	static const int liczba_wyborow = 3;
	//enum przypisanie_kandydata { blad = 0, PIERWSZ_W, DRUGI_W, TRZECI_W, WYBOR_PO_JEZYKU, WYBOR_POZA_PREFERENCJA };
	//enum sposob { ublad = 0, uPIERWSZ_W, uDRUGI_W, uTRZECI_W, uWYBOR_PO_JEZYKU, aWYBOR_POZA_PREFERENCJA };

	private:
		std::string nazwisko;
		std::string imie;
		int punkty;
		wybor wyborUcznia[liczba_wyborow];	// TODO: magic number
		jezyk wyborJezyka;
		sekretariat::przypisanie_kandydata sposobPrzydzialu;




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
		/* metoda podaj_wybor -  TODO uzupelnic
		Argumenty wejscia: .
		Wartosc zwracana:  */
		//bool Uczen::zapisz_sposob(sekretariat::przypisanie_kandydata z_kandydat);


		Uczen();
		Uczen(std::string aImie, std::string aNazwisko, int aPunkty, 
			jezyk aJezyk, wybor aWybor1, wybor aWybor2, wybor aWybor3);
		// , sekretariat::przypisanie_kandydata asposobPrzydzialukonstruktor
};
#endif
