#include "Uczen.h"
using namespace std;


Uczen::Uczen()

	{
		nazwisko = "";
		imie = "";
		punkty = -1;
		wyborJezyka = DUNNO;
		wyborUcznia[0] = UNINITIALIZED;
		wyborUcznia[1] = UNINITIALIZED;
		wyborUcznia[2] = UNINITIALIZED;
	}


Uczen::Uczen(std::string aNazwisko,std::string aImie,int aPunkty,
			jezyk aJezyk,wybor aWybor1,wybor aWybor2,wybor aWybor3)

	{
		nazwisko = aNazwisko;
		imie = aImie;
		punkty = aPunkty;
		wyborJezyka = aJezyk;
		wyborUcznia[0] = aWybor1;
		wyborUcznia[1] = aWybor2;
		wyborUcznia[2] = aWybor3;
	}

std::string Uczen::podaj_nazwisko()
{
	return imie + " " + nazwisko;	// TODO: dlaczego imie jako pierwsze, skoto ma segregowac po nazwiskach?
}

int Uczen::podaj_liczba_punktow()
{
	return punkty;
}
Uczen::wybor Uczen::podaj_wybor(int ktoryWybor)
{
	return wyborUcznia[ktoryWybor];
}
Uczen::jezyk Uczen::podaj_jezyk()
{
	return wyborJezyka;
}
