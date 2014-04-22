// NIE DOKONCZONY

#include "Nabor.h"
#include "Uczen.h"
#include <string>


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
	// TODO: nie sprawdzamy, co zwrocila funkcja wypiszListeUczniow
	//t_zapisOddzialu[] w tablicy znajduj¹ siê wartosci true gdy udalosie zapisac
	bool t_zapisOddzialu[Uczen::wybor::MAX_WYBOR] = { false };

	std::string nazwaPlikuWynikowego = "";

	for (int j = 0; j < Uczen::wybor::MAX_WYBOR; j++)
	{	
		//Nazwa pliku powstanie z sumy stringow i litery: "klasa" + (char)(65 + j) + ".csv"
		nazwaPlikuWynikowego = "klasa";
		nazwaPlikuWynikowego += ((char)(65 + j)); //((char)(65 + 0)) == A;
		nazwaPlikuWynikowego += ".csv";

		if (t_oddzial[j].wypiszListeUczniow(nazwaPlikuWynikowego)) 
		{
			t_zapisOddzialu[j] = true;
		}
		else
		{
			t_zapisOddzialu[j] = false;

			std::cout << "ERROR w metodzie sekretariat::stworzOddzialy ();"
			<< std::endl << "Nie zapisano do pliku oddzialu " << (char)(65 + j) << std::endl;
		}
	}

	bool czyZapisane = true;

	for (int j = 0; j < Uczen::wybor::MAX_WYBOR; j++)
	{
		//jesli ktorakolwiek z wartosci t_zapisOddzialu[j] bedzie false to czyZapisane tez bedzie false;
		czyZapisane = czyZapisane && t_zapisOddzialu[j];
	}


	return czyZapisane;

}


sekretariat::sekretariat(std::string plik_csv)
{
	start(plik_csv);
}
