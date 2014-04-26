#ifndef _UCZEN_H_
#define _UCZEN_H_

#include <string>

class Uczen
{
	public:
	enum jezyk {angielski = 0, niemiecki, DUNNO};
	enum wybor {UNINITIALIZED=-1, A = 0,B,C,D,E,F,MAX_WYBOR};

	private:
		std::string nazwisko;
		std::string imie;
		int punkty;
		static const int liczba_wyborow = 3;
		wybor wyborUcznia[liczba_wyborow];
		jezyk wyborJezyka;

	public:
		std::string podaj_nazwisko();
		int podaj_liczba_punktow();
		jezyk podaj_jezyk();
		wybor podaj_wybor(int ktoryWybor);
		Uczen();

		Uczen(std::string aImie, std::string aNazwisko, int aPunkty,
        jezyk aJezyk, wybor aWybor1, wybor aWybor2, wybor aWybor3);
};
#endif
