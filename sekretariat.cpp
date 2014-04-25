#include <iostream>
#include <string>

#include "sekretariat.h"




bool sekretariat::start(std::string plik_csv)
{
	Nabor nowyNabor(plik_csv);
	Uczen kandydat;

	bool kandydatDodany = false;
	//int uczniowwklasie[MAX.WYBOR];
	// uczniowwklasie = {0};       wyzerowanie elementów

	for (int i = 0; i < nowyNabor.ilosc(); i++)
	{
		if (nowyNabor.podaj_ucznia(i, &kandydat))
		{
			if (kandydat.podaj_jezyk() == kandydat.niemiecki)
			{
				t_oddzial[kandydat.C].dodajUcznia(kandydat);
				// uczniowwklasie[kandydat.C] ++;
			}
			else
			{

				for (int j = 0; j < 3; j++)
				{
					if (t_oddzial[kandydat.podaj_wybor(j)].dodajUcznia(kandydat))
					{
						// uczniowwklasie[kandydat.podaj_wybor(j)] ++;
						kandydatDodany = true;
						break;
					}

				}
				if (kandydatDodany == false)

				{
					/* W nastepnych liniach 45-57 zmieniony jest caly tok rozumowania. Przyjmujemy ze wartosc minimalna = 0, sprawdzamy po kolei klasy, w ktorej jest
					najmniej uczniow. Jak ju¿ mamy min to wtedy dorzucamy ucznia do danej klasy*/


					//int min = 0;
					for (int j = 0; j < kandydat.MAX_WYBOR; j++)
					{
						//		if (uczniowwklasie[j] <= min)
						//		{
						//			min = uczniowwklasie[j];
						//		}
						//	}
						//		if (t_oddzial[min].dodajUcznia(kandydat))
						{
							kandydatDodany = true;
							break;
						}
					}
				}

			}
		}

	}
	return kandydatDodany;
}


bool sekretariat::stworzOddzialy()
{

	bool t_zapisOddzialu[Uczen::MAX_WYBOR] = { false };

	std::string nazwaPlikuWynikowego = "";

	for (int j = 0; j < Uczen::MAX_WYBOR; j++)
	{

		nazwaPlikuWynikowego = "klasa";
		nazwaPlikuWynikowego += ((char)(65 + j));
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

	for (int j = 0; j < Uczen::MAX_WYBOR; j++)
	{

		czyZapisane = czyZapisane && t_zapisOddzialu[j];
	}


	return czyZapisane;

}



sekretariat::sekretariat(std::string plik_csv)
{
	start(plik_csv);
}
