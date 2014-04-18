// NIE DOKONCZONY

#include "Nabor.h"
#include "sekretariat.h"
#include <iostream>


// TODO: dlaczego funkcja start jest tak cholernie dluga? 
//odpPZ: moze by ja podzielic na dodajPoJezyku, dodajPoWyborze, dodajPozostalych

bool sekretariat::start (std::string plik_csv)
{
	Nabor nowyNabor(plik_csv);	// TODO: nie robimy magic numbers
	Uczen kandydat;
	oddzial klasa[Uczen::MAX_WYBOR]; // TODO: slowo kluczowe "klasa" jest niefortunne
	enum przypisanie_kandydata { blad = 0, PIERWSZY_W, DRUGI_W, TRZECI_W, WYBOR_PO_JEZYKU, WYBOR_POZA_PREFERENCJA};
	przypisanie_kandydata kandydatDodany = blad;
	

	for (int i = 0; i < nowyNabor.ilosc(); i++) // przypisanie uczniow do oddzialow
	{
		kandydatDodany = blad;
		if (nowyNabor.podaj_ucznia(i, &kandydat))
		{
			if (kandydat.podaj_jezyk() == kandydat.niemiecki) // dodawanie kandydat z jez. niemieckim do klasy C
			{
				if (klasa[kandydat.C].dodajUcznia(kandydat)); // TODO: nie sprawdzamy, co zwrocila funkcja dodajUcznia  
				// odpPZ: 
				{
					kandydatDodany = WYBOR_PO_JEZYKU; // kandydat dodany wg jezyka
					
				}
				kandydatDodany = blad;
			}
			else // dodawanie po preferencjach pozostalych kandydatow do pozostalych klas
			{

				for (int j = 0; j < Uczen::liczba_wyborow; j++) // TODO: magic number; j = preferencje kandydata, sa 3.odpPZ:poprawiono
				{
					if(klasa[kandydat.podaj_wybor(j)].dodajUcznia(kandydat))
					{
						switch (j)
						{
						
						case 0: kandydatDodany = PIERWSZY_W; break;   // kandydat dodany wg swoich preferencji
						case 1: kandydatDodany = DRUGI_W; break;
						case 2: kandydatDodany = TRZECI_W; break;
						default: kandydatDodany = blad;
						}
						
						break;
					}
					kandydatDodany = blad;
				}
				if (kandydatDodany == blad)
				// nieudane przypisanie po preferencjach, przypisanie do pierwszego wolnego miejsca
				{
					// TODO: przy takim algorytmie klasa A bedzie najbardziej obciazona i w niej pierwszej zabraknie miejsc.
					// W tym momencie kandydaci z konca listy nie dostana sie do niej, nawet jak bedzie to ich pierwszy wybor.
					// Czy nie mozna wymyslic lepszego sposobu?

					for (int j = 0; j < kandydat.MAX_WYBOR; j++) // j = numery wszystkich oddzialow
					{
						int minLiczbaUczniow = 0;
						if (minLiczbaUczniow > klasa[j].podajLiczbeUczniow())
						{
							int minLiczbaUczniow = klasa[j].podajLiczbeUczniow();
						}
						
						if (klasa[j].dodajUcznia(kandydat))
						{
							kandydatDodany = WYBOR_POZA_PREFERENCJA; // kandydat dodany wg swoich preferencji
							break;
						}
					}
				}			
			}
			//std::cout << kandydatDodany << kandydat.podaj_nazwisko();
			
		}
	} // for (int i = 0; i < nowyNabor.ilosc(); i++)
	
	klasa[kandydat.A].wypiszListeUczniow("klasaA.csv"); // TODO: nie sprawdzamy, co zwrocila funkcja wypiszListeUczniow
	klasa[kandydat.B].wypiszListeUczniow("klasaB.csv"); // TODO: Uczen::B ?
	klasa[kandydat.C].wypiszListeUczniow("klasaC.csv");
	klasa[kandydat.D].wypiszListeUczniow("klasaD.csv");
	klasa[kandydat.E].wypiszListeUczniow("klasaE.csv");
	klasa[kandydat.F].wypiszListeUczniow("klasaF.csv");
	//getchar();

	if (kandydatDodany==blad)
	{
		return false;
	}
	else return true;
		// TODO: co TAK NAPRAWDE zostanie tutaj zwrocone i dlaczego?
}


// TODO: po co ta funkcja?
bool sekretariat::stworzOddzialy ()
{
	return false;

}

	////dodane przez marka
	//konstruktor:

sekretariat::sekretariat(std::string plik_csv)
{
	start(plik_csv);
}
