#ifndef _Nabor_h
#define _Nabor_h
#include <iostream>
#include "Uczen.h"
#include "oddzial.h"
#include "sekretariat.h"

using namespace std;

class Nabor
{	
	public:
		
	int ilosc();// Zwraca ilosc uczniow w tabelii
	
	bool podaj_ucznia(int ktory, Uczen * kto);//Zmienia wartosci zmiennej kto na wartosci ucznia z tabeli o indeksie "ktory"
												// zwrafa false w przypadku braku danego wiersza w tabeli i true gdy iwersz istnieje																																						
	Nabor(std::string nazwa);//Pobiera sciezke do pliku i tworzy tabele uczniow posortowana wedlug punktow; 
							//osoby z niemieckim jako podstawowym umieszczane sa na poczatku tabeli
							
	private:	
	const static int wielkosc_naboru = 132;
	string sciezka;
	Uczen tab[wielkosc_naboru];
	int ilu;
	
	Uczen::wybor str_to_wybor(string tab);
	Uczen::jezyk str_to_jezyk(string tab);
	bool wpis_z_pliku(const string sciezka, Uczen tab[] );
	void sortuj(int ilosc, Uczen tab[]);
};
#endif
