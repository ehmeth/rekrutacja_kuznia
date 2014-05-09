#include <iostream>
#include <string>

#include "sekretariat.h"
using namespace std;

bool sekretariat::start(std::string plik_csv)
{
	Nabor nowyNabor(plik_csv);
	if (nowyNabor.pobranieDanych(plik_csv) == false)
	{
		cout << "Blad podczas wpisywania danych z pliku!" << endl;
		return false;
	}

	Uczen kandydat;

	bool kandydatDodany = false;

	for (int i = 0; i < nowyNabor.ilosc(); i++)
	{
		if (nowyNabor.podaj_ucznia(i, &kandydat))
		{
			if (kandydat.podaj_jezyk() == kandydat.niemiecki)
			{
				t_oddzial[kandydat.C].dodajUcznia(kandydat);
			}
			else
			{
				for (int j = 0; j < 3; j++)
				{
					if (t_oddzial[kandydat.podaj_wybor(j)].dodajUcznia(kandydat))
					{
						kandydatDodany = true;
						break;
					}
				}
				if (kandydatDodany == false)
				{
					for (int j = 0; j < kandydat.MAX_WYBOR; j++)
					{
						if (t_oddzial[j].dodajUcznia(kandydat))
						{
							kandydatDodany = true;
							break;
						}
					}
				}
			}
		}
	}
	stworzOddzialy();

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

		t_oddzial[j].podajNumerKlasy(j);

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
