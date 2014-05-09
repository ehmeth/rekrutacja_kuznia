#ifndef _ODDZIAL_H
#define _ODDZIAL_H


class oddzial
{
public:
	void podajNumerKlasy(int numer)
	{
		numerKlasy = numer;
	}
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

	oddzial() 
	:liczba_uczniow_w_oddziale(0) {};

	private:
	int numerKlasy;
	static const int  max_licz_uczniow = 22;
	int liczba_uczniow_w_oddziale;
	Uczen lista_uczniow_w_oddziale[max_licz_uczniow];

	void segregujUczniow ();



};

#endif // _ODDZIAL_H
