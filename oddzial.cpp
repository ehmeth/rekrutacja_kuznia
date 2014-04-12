#include "oddzial.h"
#include <fstream>
#include <string>
using namespace std;

// kostruktor do zrobienia

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
	 ofstream outfile (oddzial_csv.c_str());
if (outfile.is_open())
  {
  	for (int i = 0; i <liczba_uczniow_w_oddziale; i++) {
		outfile << lista_uczniow_w_oddziale[i].podaj_nazwisko() << '\n';
  	}

    outfile.close();
  } else {
    cout << "Unable to open outfile";
  }

  return false;
}

bool oddzial::segregujUczniow()
	{
		return false;
	}
