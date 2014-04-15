// NIE DOKONCZONY

#include "Nabor.h"

bool sekretariat::start (std::string plik_csv)
{
	Nabor nowyNabor(plik_csv,6,22);
	Uczen kandydat;
	oddzial klasa[Uczen::MAX_WYBOR];
	bool kandydatDodany = false;

	for (int i = 0; i < nowyNabor.ilosc(); i++) // przypisanie uczniow do oddzialow
	{
		if (nowyNabor.podaj_ucznia(i, &kandydat))
		{
			if (kandydat.podaj_jezyk() == kandydat.niemiecki) // dodawanie kandydat z jez. niemieckim do klasy C
			{
				klasa[kandydat.C].dodajUcznia(kandydat);
			}
			else // dodawanie po preferencjach pozostalych kandydatow do pozostalych klas
			{

				for (int j = 0; j < 3; j++) // j = preferencje kandydata, sa 3
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

	klasa[kandydat.A].wypiszListeUczniow("klasaA.csv");
	klasa[kandydat.B].wypiszListeUczniow("klasaB.csv");
	klasa[kandydat.C].wypiszListeUczniow("klasaC.csv");
	klasa[kandydat.D].wypiszListeUczniow("klasaD.csv");
	klasa[kandydat.E].wypiszListeUczniow("klasaE.csv");
	klasa[kandydat.F].wypiszListeUczniow("klasaF.csv");

	return kandydatDodany;
}



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
