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
    segregujUczniow();
    std::ofstream outfile(oddzial_csv.c_str());
    //Nazwa: minPunktow - do znajdowania minimalnej liczby punktow w oddziale
    int minPunktow = lista_uczniow_w_oddziale[0].podaj_liczba_punktow();
    if (outfile.is_open())
    {
        for (int i = 0; i < liczba_uczniow_w_oddziale; i++)
        {
            outfile
            //std::cout <<std::endl
                    << lista_uczniow_w_oddziale[i].podaj_nazwisko1() << ";"
                    << lista_uczniow_w_oddziale[i].podaj_imie1() << ";"
                    << lista_uczniow_w_oddziale[i].podaj_liczba_punktow() << ";"
                    << lista_uczniow_w_oddziale[i].pokazPrzydzial()
                    <<'\n';
            if (lista_uczniow_w_oddziale[i].podaj_liczba_punktow() < minPunktow)
            {
                minPunktow = lista_uczniow_w_oddziale[i].podaj_liczba_punktow();
            }
        }
        outfile
        //std::cout
        << "\n\nNajmniejsza liczba punktow z rekrutacji w oddziale :" << minPunktow;

        outfile.close();
        return true;
    }
    else
    {
        std::cout << std::endl << "Error in: bool oddzial::wypiszListeUczniow(std::string oddzial_csv)\nNie udalo sie otworzyc pliku: " << oddzial_csv << std::endl;
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
