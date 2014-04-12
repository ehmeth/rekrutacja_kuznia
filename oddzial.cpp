#include "oddzial.h"
#include <fstream>
#include <string>
using namespace std;

bool oddzial::dodajUcznia (Uczen kandydat)
{
	if (liczba_uczniow_w_oddziale < max_licz_uczniow)
	{
        lista_uczniow_w_oddziale[liczba_uczniow_w_oddziale] = kandydat;
        liczba_uczniow_w_oddziale++;
        return true;
	}
	return false;

}

bool oddzial::wypiszListeUczniow(std::string oddzial_csv)
{
	oddzial::segregujUczniow(oddzial::liczba_uczniow_w_oddziale,oddzial::lista_uczniow_w_oddziale);

    ofstream outfile (oddzial_csv.c_str());
        if (outfile.is_open())
        {
            for (int i = 0; i <liczba_uczniow_w_oddziale; i++) {
                outfile << lista_uczniow_w_oddziale[i].podaj_nazwisko() << '\n';
            }

            outfile.close();
         } else {
  }
  return false;
}

void oddzial::segregujUczniow(int liczba_uczniow, Uczen tab[])

	{

	for(int i = liczba_uczniow - 1; i>=0; i--)
		for(int l = 0; l<i; l++)
			{
				if(tab[l].podaj_nazwisko() < tab[l+1].podaj_nazwisko())
					{
						std::swap(tab[l], tab[l+1] );

					}
			}
	}
