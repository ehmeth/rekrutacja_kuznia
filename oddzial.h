#ifndef _oddzial_h
#define _oddzial_h
#include <string>
#include "Uczen.h"
class oddzial
{
	public:
/*	dodajUcznia - dodaje ucznia do oddzialu jesli jest miejsce, 
	Arg.we:
	uczen kandydat - obiekt klasy uczen; pobiera od ucznia dane o jezyku, punktach i preferencjach
	Zwracane:
	true - udalo sie przypisac ucznia do klasy, 
	false - nie udalo sie
*/	
	bool dodajUcznia (Uczen kandydat);
	
	
/*	wypiszListeUczniow - eksportuje liste uczniow do pliku zewnetrznego, 
	Arg.we:
	oddzial_csv - nazwa pliku, w ktorym zostana zapisani uczniowie z danej klasy
	Zwracane:
	true - udalo sie wyeksportowac dane do pliku zewnetrzego, 
	false - nie udalo sie

*/
	bool wypiszListeUczniow (std::string oddzial_csv); 
	
	private:
	static const int  max_licz_uczniow = 22;
	int liczba_uczniow_w_oddziale;
	Uczen lista_uczniow_w_oddziale[max_licz_uczniow];
	
	bool segregujUczniow ();
	
	// kostruktor do zrobienia
	//oddzial()
	//oddzial(int liczba_uczniow_w_oddziale)  //konstruktor
};
#endif
