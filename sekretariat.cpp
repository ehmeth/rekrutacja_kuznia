// NIE DOKONCZONY

#include "Nabor.h"


// TODO: dlaczego funkcja start jest tak cholernie dluga?
bool sekretariat::start (std::string plik_csv)
{
	Nabor nowyNabor(plik_csv,6,22);	// TODO: nie robimy magic numbers
	Uczen kandydat;
	oddzial klasa[Uczen::MAX_WYBOR]; // TODO: slowo kluczowe "klasa" jest niefortunne
	bool kandydatDodany = false;

	for (int i = 0; i < nowyNabor.ilosc(); i++) // przypisanie uczniow do oddzialow
	{
		if (nowyNabor.podaj_ucznia(i, &kandydat))
		{
			if (kandydat.podaj_jezyk() == kandydat.niemiecki) // dodawanie kandydat z jez. niemieckim do klasy C
			{
				klasa[kandydat.C].dodajUcznia(kandydat); // TODO: nie sprawdzamy, co zwrocila funkcja dodajUcznia
			}
			else // dodawanie po preferencjach pozostalych kandydatow do pozostalych klas
			{

				for (int j = 0; j < 3; j++) // TODO: magic number; j = preferencje kandydata, sa 3. 
				{
					if(klasa[kandydat.podaj_wybor(j)].dodajUcznia(kandydat))
					{
						kandydatDodany = true; // kandydat dodany wg swoich preferencji
						break;
					}

				}
				if (kandydatDodany == false)
				// nieudane przypisanie po preferencjach, przypisanie do pierwszego wolnego miejsca
				{
					// TODO: przy takim algorytmie klasa A bedzie najbardziej obciazona i w niej pierwszej zabraknie miejsc.
					// W tym momencie kandydaci z konca listy nie dostana sie do niej, nawet jak bedzie to ich pierwszy wybor.
					// Czy nie mozna wymyslic lepszego sposobu?

					for (int j = 0; j < kandydat.MAX_WYBOR; j++) // j = numery wszystkich oddzialow
					{
						if (klasa[j].dodajUcznia(kandydat))
						{
							kandydatDodany = true; // kandydat dodany wg swoich preferencji
							break;
						}
					}
				}
				//dodaje ucznia do pierwszej klasy w ktorej sa wolne miejsca
			}
		}
	} // for (int i = 0; i < nowyNabor.ilosc(); i++)

	klasa[kandydat.A].wypiszListeUczniow("klasaA.csv"); // TODO: nie sprawdzamy, co zwrocila funkcja wypiszListeUczniow
	klasa[kandydat.B].wypiszListeUczniow("klasaB.csv"); // TODO: Uczen::B ?
	klasa[kandydat.C].wypiszListeUczniow("klasaC.csv");
	klasa[kandydat.D].wypiszListeUczniow("klasaD.csv");
	klasa[kandydat.E].wypiszListeUczniow("klasaE.csv");
	klasa[kandydat.F].wypiszListeUczniow("klasaF.csv");

	return kandydatDodany; // TODO: co TAK NAPRAWDE zostanie tutaj zwrocone i dlaczego?
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
