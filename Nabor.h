#ifndef _NABOR_H
#define _NABOR_H
#include "Uczen.h"
#include <vector>
#include <array>

class Nabor
{
	public:
		enum indeksyDanychPlik{ ImieEnum = 0, NazwiskoEnum, punktyEnum,ocenaPierwsza,
			punktyDodatkoweEnum = 8,wybor_1, wybor_2, wybor_3, jezykEnum
		};

	int ilosc();
		 // Zwraca ilosc uczniow w tabelii

	bool podaj_ucznia( int numerUcznia, Uczen * pUczen);
		//Pobiera indeks ucznia i wskaünik na zmiennπ typu Uczen zwraca false w przypadku braku danego wiersza w tabeli i true gdy wiersz istnieje

	Nabor(std::string sciezkaDoPliku);
	   //Pobiera sciezke do pliku i tworzy tabele uczniow posortowana wedlug punktow osoby z niemieckim jako podstawowym umieszczane sa na poczatku tabeli

	bool pobranieDanych(std::string sciezkaDoPliku);


	private:
	std::vector <Uczen> tabUczniow;
	int ileWersow;

	Uczen::wybor strDoWybor(std::string str);
	Uczen::jezyk strDoJezyk(std::string str);
	void sortowanieMalejace(std::vector <Uczen> tabUczniow);
};
#endif // _NABOR_H
