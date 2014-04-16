#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Nabor.h"
#include "Uczen.h"
#include <sstream>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;

/* Metody Publiczne : */
int Nabor::ilosc()
{
	return ilu; 
}

Nabor::Nabor(std::string sciezka_do_pliku)
{
	if (sciezka_do_pliku == "")
	{
		cout << "Brak sciezki do pliku! -- Nabor::Nabor" << endl;
		getchar();
	}
	if (wpis_z_pliku(sciezka_do_pliku, 0) == false)
	{
		cout << "Blad podczas wpisywania danych z pliku! -- Nabor::Nabor" << endl;
		getchar();
	}
}

Nabor::Nabor(std::string sciezka_do_pliku, unsigned int ilosc_grup, unsigned int ilosc_uczniow_na_grupe)
{
	ilu = ilosc_grup*ilosc_uczniow_na_grupe;
	if (sciezka_do_pliku == "")
	{
		cout << "Brak sciezki do pliku! -- Nabor::Nabor" << endl;
		getchar();
	}
	if (wpis_z_pliku(sciezka_do_pliku, 1) == false)
	{
		cout << "Blad podczas wpisywania danych z pliku! -- Nabor::Nabor" << endl;
		getchar();
	}
}

bool Nabor::podaj_ucznia(int ktory, Uczen *kto)
{
	if (ktory<0 || ktory>=ilu) 
	{
		cout << "Uczen o podanym indeksie nie istnieje -- Nabor::podaj_ucznia" << endl;
		return false;
	}
	*kto = tab[ktory];
	return true;
}




/* Metody Prywatne : */

enum indeksy
{
	Imie_e = 0,
	Nazwisko_e,
	punkty_e,
	wybor_1,
	wybor_2,
	wybor_3,
	jezyk_e
};

Uczen::wybor Nabor::str_to_wybor(string str)
{
	str[0] = toupper(str[0]);
	if (str == "A") return Uczen::A;
	if (str == "B") return Uczen::B;
	if (str == "C") return Uczen::C;
	if (str == "D") return Uczen::D;
	if (str == "E") return Uczen::E;
	if (str == "F") return Uczen::F;
	return Uczen::UNINITIALIZED;
}

Uczen::jezyk Nabor::str_to_jezyk(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\0') break;
		str[i] = tolower(str[i]);
	}
	if (str == "angielski") return Uczen::angielski;
	if (str == "niemiecki") return Uczen::niemiecki;
	return Uczen::DUNNO;
}

bool Nabor::wpis_z_pliku(const string sciezka, bool is_ilu) 
{
	Uczen::jezyk jezyk;
	Uczen::wybor wybor1;
	Uczen::wybor wybor2;
	Uczen::wybor wybor3;

	const int niemecki_dodatkowe_punkty = 101, max_indeks_n = 6, ilosc_komorek_danych = 7;
	int indeks_komorki_danych = 0, indeks_ucznia = 0, punkty = 0; 

	string zawartosc_komorki_danych, temp[ilosc_komorek_danych]; // TODO: zmienic nazwe s
	const std::string delimiter = ";";

	ifstream plik;
	plik.open(sciezka.c_str());
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku -- Nabor::wpis_z_pliku" << endl;
		getchar();
		return false;
	}
	if (!is_ilu)
	{
		while (getline(plik, zawartosc_komorki_danych))
		{
			indeks_ucznia++;
		}
		plik.clear(); //Wyczyszczenie bufora i ustawienie wskaŸnika wen¹trz pliku na jego pocz¹tek 
		plik.seekg(0, plik.beg);
		ilu = indeks_ucznia;
	}
	tab = new Uczen[ilu];
	indeks_ucznia = 0;
	while (getline(plik, zawartosc_komorki_danych))
	{
		indeks_komorki_danych = 0;
		size_t pos = 0;
		while ((pos = zawartosc_komorki_danych.find(delimiter)) != std::string::npos)
		{
			if (indeks_komorki_danych > max_indeks_n)
			{
				cout << "Zly format pliku, zbyt duza ilosc komorek danych w wierszu. Uczen: " << indeks_ucznia << "  -- Nabor::wpis_z_pliku" << endl;
				getchar();
				return false;
			}
			if (indeks_komorki_danych < 0)
			{
				cout << "Ujemna liczba komorek danych w wierszu...? Uczen: " << indeks_ucznia << " -- Nabor::wpis_z_pliku" << endl;
				getchar();
				return false;
			}
			temp[indeks_komorki_danych] = zawartosc_komorki_danych.substr(0, pos);
			zawartosc_komorki_danych.erase(0, pos + delimiter.length());
			indeks_komorki_danych++;
		}
		temp[indeks_komorki_danych] = zawartosc_komorki_danych.substr(0, pos);
		zawartosc_komorki_danych.erase(0, pos + delimiter.length());

		punkty = atoi(temp[punkty_e].c_str());
		if (punkty<0 || punkty>100)
		{
			cout << "Blad! Niepoprawna ilosc punktow! Uczen: " << indeks_ucznia << " -- Nabor::wpis_z_pliku" << endl;
			getchar();
			return false;
		}
		jezyk = str_to_jezyk(temp[jezyk_e]);
		if (jezyk == Uczen::niemiecki) punkty += niemecki_dodatkowe_punkty;
		wybor1 = str_to_wybor(temp[wybor_1]);
		wybor2 = str_to_wybor(temp[wybor_2]);
		wybor3 = str_to_wybor(temp[wybor_3]);
		tab[indeks_ucznia] = Uczen(temp[Imie_e], temp[Nazwisko_e], punkty, jezyk, wybor1, wybor2, wybor3);
		indeks_ucznia++;
	}
	plik.close();
	sortuj(ilu, tab);
	return true;
}

void Nabor::sortuj(int ilosc, Uczen tab[])
{
	for (int i = ilosc - 1; i >= 0; i--)
	for (int l = 0; l < i; l++)
	{
		if (tab[l].podaj_liczba_punktow() < tab[l + 1].podaj_liczba_punktow())
		{
			std::swap(tab[l], tab[l + 1]);

		}
	}
}