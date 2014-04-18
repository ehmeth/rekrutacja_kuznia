#include "oddzial.h"
#include <fstream>
#include <string>
using namespace std;

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
	// TODO: dlaczego tutaj jest uzyte :: ? Do ktorego obiektu klasy oddzial odnosi sie taki zapis? odp: usuniêto ::
	// TODO: Po co tej funkcji potrzebne sa jakiekolwiek argumenty?   
	//  odp: argumenty niepotrzebne,nale¿¹ do klasy uczeñ wiêc metoda "widzi" je
	segregujUczniow();

	ofstream outfile(oddzial_csv.c_str());
	if (outfile.is_open())
	{
		for (int i = 0; i < liczba_uczniow_w_oddziale; i++)
		{
			outfile << lista_uczniow_w_oddziale[i].podaj_nazwisko() << '\n';
		}
		outfile.close();
		return true;
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
