// NIE DOKONCZONY

#include "Nabor.h"
#include "Uczen.h"


// TODO: dlaczego funkcja start jest tak cholernie dluga?
bool sekretariat::start (std::string plik_csv)
{
	Nabor nowyNabor(plik_csv);	// TODO: nie robimy magic numbers
	Uczen kandydat;
	//przenosze tablice klasa[] do sekcji private klasy sekretariat.h z nowa nazwa t_oddzial, 
	//zeby tablica t_oddzialy byla dostepna dla wszystkich metod klasy sekretariat.h	// TODO: slowo kluczowe "klasa" jest niefortunne
	bool kandydatDodany = false;

	for (int i = 0; i < nowyNabor.ilosc(); i++) // przypisanie uczniow do oddzialow
	{
		if (nowyNabor.podaj_ucznia(i, &kandydat))
		{
			if (kandydat.podaj_jezyk() == kandydat.niemiecki) // dodawanie kandydat z jez. niemieckim do klasy C
			{
				t_oddzial[kandydat.C].dodajUcznia(kandydat); // TODO: nie sprawdzamy, co zwrocila funkcja dodajUcznia
			}
			else // dodawanie po preferencjach pozostalych kandydatow do pozostalych klas
			{

				for (int j = 0; j < 3; j++) // TODO: magic number; j = preferencje kandydata, sa 3. 
				{
					if (t_oddzial[kandydat.podaj_wybor(j)].dodajUcznia(kandydat))
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
						if (t_oddzial[j].dodajUcznia(kandydat))
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

	//przenosze zapisanie wszystkich oddzialow do metody klasy sekretariat::stworzOddzialy()
	return kandydatDodany; // TODO: co TAK NAPRAWDE zostanie tutaj zwrocone i dlaczego?
}


// TODO: po co ta funkcja?
bool sekretariat::stworzOddzialy ()
{
	bool czyZapisane;

	if (t_oddzial[Uczen::A].wypiszListeUczniow("klasaA.csv"))
	{
		czyZapisane = true;
	}
	else
	{
		czyZapisane = false;
		cout << "ERROR w metodzie sekretariat::stworzOddzialy ();\nNie zapisano do pliku oddzialu A\n";
	}
	 // TODO: nie sprawdzamy, co zwrocila funkcja wypiszListeUczniow
	t_oddzial[Uczen::B].wypiszListeUczniow("klasaB.csv"); // TODO: Uczen::B ?
	t_oddzial[Uczen::C].wypiszListeUczniow("klasaC.csv");
	t_oddzial[Uczen::D].wypiszListeUczniow("klasaD.csv");
	t_oddzial[Uczen::E].wypiszListeUczniow("klasaE.csv");
	t_oddzial[Uczen::F].wypiszListeUczniow("klasaF.csv");

	return czyZapisane;

}


sekretariat::sekretariat(std::string plik_csv)
{
	start(plik_csv);
}
