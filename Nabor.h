#ifndef _Nabor_h
#define _Nabor_h
#include "Uczen.h"
#include "oddzial.h"
#include "sekretariat.h"

class Nabor
{
	public:

	int ilosc();// Zwraca ilosc uczniow w tabelii

	bool podaj_ucznia(int ktory, Uczen * kto);//Zmienia wartosci zmiennej kto na wartosci ucznia z tabeli o indeksie "ktory"
												// zwrafa false w przypadku braku danego wiersza w tabeli i true gdy iwersz istnieje
	Nabor(std::string sciezka_do_pliku, int liczbaOddzialow, int uczniowWOddziale);//Pobiera sciezke do pliku i tworzy tabele uczniow posortowana wedlug punktow;
																					//osoby z niemieckim jako podstawowym umieszczane sa na poczatku tabeli
																//Pobiera iloœæ oddzialow i uczniow w oddziale.

	private:
	int wielkosc_naboru;
	std::string sciezka;
	Uczen *tab;
	int ilu;

	Uczen::wybor str_to_wybor(std::string tab);
	Uczen::jezyk str_to_jezyk(std::string tab);
	bool wpis_z_pliku(std::string sciezka, Uczen tab[] );
	void sortuj(int ilosc, Uczen tab[]);
};
#endif
