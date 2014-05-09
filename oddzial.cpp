#include <fstream>
#include <string>
#include <iostream>
#include "Uczen.h"
#include "oddzial.h"


bool oddzial::dodajUcznia(Uczen kandydat)
{
	if (liczba_uczniow_w_oddziale < oddzial::max_licz_uczniow)
	{
		lista_uczniow_w_oddziale[liczba_uczniow_w_oddziale] = kandydat;
		liczba_uczniow_w_oddziale++;
		return true;
	}
	return false;
}

bool oddzial::wypiszListeUczniow(std::string oddzial_csv)
{
	int numerWyboru = -1, minimalnaLiczbaPunktow = lista_uczniow_w_oddziale[0].podaj_liczba_punktow();
	segregujUczniow();
	std::ofstream outfile(oddzial_csv.c_str());
	if (outfile.is_open())
	{
		for (int i = 0; i < liczba_uczniow_w_oddziale; i++)
		{
			for (int x = 0; x < 3; x++) if (numerKlasy == lista_uczniow_w_oddziale[i].podaj_wybor(x) )
			{
				numerWyboru = x+1;
				break;
			}
			outfile << lista_uczniow_w_oddziale[i].podaj_nazwisko() << "  ";
			if (lista_uczniow_w_oddziale[i].podaj_liczba_punktow() > punktyNiemiecki)
				outfile << (lista_uczniow_w_oddziale[i].podaj_liczba_punktow() - punktyNiemiecki) << ' ' <<
					numerWyboru <<'\n';
			else outfile << lista_uczniow_w_oddziale[i].podaj_liczba_punktow() << ' ' <<
				numerWyboru << '\n';

				if (minimalnaLiczbaPunktow > lista_uczniow_w_oddziale[i].podaj_liczba_punktow()) minimalnaLiczbaPunktow = lista_uczniow_w_oddziale[i].podaj_liczba_punktow();
		}
		outfile <<"Minimalna liczba punktow" << minimalnaLiczbaPunktow << "\n";
		outfile.close();
		return true;
	}
	else
	{
		std::cout << "nie udalo sie otworzyc pliku: " << oddzial_csv << std::endl;
	}
	return false;
}

void oddzial::segregujUczniow()

{
	for (int i = liczba_uczniow_w_oddziale - 1; i >= 0; i--)
	for (int l = 0; l<i; l++)
	{
		if (lista_uczniow_w_oddziale[l].podaj_nazwisko() > lista_uczniow_w_oddziale[l + 1].podaj_nazwisko())
		{
			std::swap(lista_uczniow_w_oddziale[l], lista_uczniow_w_oddziale[l + 1]);
		}
	}
}
