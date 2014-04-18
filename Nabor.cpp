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
	return ileWersow; //Ilosc wersow w pliku jest rowna ilosci uczniow
}

Nabor::Nabor(std::string sciezkaDoPliku)
{
	if (sciezkaDoPliku == "")
	{
		cout << "Brak sciezki do pliku! -- Nabor::Nabor" << endl;
	}
	if (pobranieDanych(sciezkaDoPliku) == false)
	{
		cout << "Blad podczas wpisywania danych z pliku! -- Nabor::Nabor" << endl;
	}
}

bool Nabor::podaj_ucznia(int numerUcznia, Uczen *pUczen)
{
	if (numerUcznia<0 || numerUcznia >= ileWersow)
	{
		cout << "Uczen o podanym indeksie nie istnieje -- Nabor::podaj_ucznia" << endl;
		return false;
	}
	*pUczen = tabUczniow[numerUcznia];
	return true;
}


/*---------------------- Metody Prywatne -------------------- */
bool czyInt(string str);
bool czyTabChar(string str);
Uczen::wybor Nabor::strDoWybor(string str)
{
	str[0] = toupper(str[0]);
	if (str == "A") return Uczen::A;
	if (str == "B") return Uczen::B;
	if (str == "C") return Uczen::C;
	if (str == "D") return Uczen::D;
	if (str == "E") return Uczen::E;
	if (str == "F") return Uczen::F;
	cout << "Klasa podana przy preferowanych wyborze jest bledana. Uczen((Wers w pilku) nr" << ileWersow << "Nabor::strDoWybor" << endl;
	return Uczen::UNINITIALIZED;
}

Uczen::jezyk Nabor::strDoJezyk(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\0') break;
		str[i] = tolower(str[i]);
	}
	if (str == "angielski") return Uczen::angielski;
	if (str == "niemiecki") return Uczen::niemiecki;
	cout << "Jezyk prowadzacy podany w pliku jest bledny. Uczen((Wers w pilku) nr" << ileWersow << "Nabor::strDoJezyk" << endl;
	return Uczen::DUNNO;
}

bool Nabor::pobranieDanych(const string sciezkaDoPliku)
{
	Uczen::jezyk jezykWPodstawowce;
	Uczen::wybor wybor1Ucznia;
	Uczen::wybor wybor2Ucznia;
	Uczen::wybor wybor3Ucznia;
	
	const int dodPunktyNiem = 101, maxKomorek = 6, ilInformacjiWPliku = 7;
	int indeksInfZPliku = 0, punktyUcznia = 0; 

	string sZawartoscDanych, temp[ilInformacjiWPliku];
	const std::string delimiter = ";";

	ifstream plik;
	plik.open(sciezkaDoPliku.c_str());
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku -- Nabor::wpis_z_pliku" << endl;
		return false;
	}

			while (getline(plik, sZawartoscDanych))//Odczytanie ilosci uczniow w pliku
		{
			ileWersow++;
		}
		plik.clear(); //Wyczyszczenie bufora i ustawienie wska�nika wen�trz pliku na jego pocz�tek 
		plik.seekg(0, plik.beg);


	tabUczniow = new Uczen[ileWersow];//Tworzenie tablicy od ilosci uczniow z pliku
	ileWersow = 0;

	while (getline(plik, sZawartoscDanych))//Odczytanie informacji z pliku i zapisanie ich w kolejnych miejscach tabeli
	{
		indeksInfZPliku = 0;
		size_t pos = 0;
		while ((pos = sZawartoscDanych.find(delimiter)) != std::string::npos)
		{
			if (indeksInfZPliku > maxKomorek)
			{
				cout << "Zly format pliku, zbyt duza ilosc komorek danych w wierszu. Uczen(Wers w pilku) nr: " << ileWersow << "  -- Nabor::wpis_z_pliku" << endl;
				return false;
			}
			temp[indeksInfZPliku] = sZawartoscDanych.substr(0, pos); //Przypisanie do tymczasowej tablicy kolejnych stringow z pliku
			sZawartoscDanych.erase(0, pos + delimiter.length());
			indeksInfZPliku++;
		}
		temp[indeksInfZPliku] = sZawartoscDanych.substr(0, pos);
		sZawartoscDanych.erase(0, pos + delimiter.length());

	//------ Koniec pobierania pojedynczego wersu z pliku ----------

		if (!czyInt(temp[punktyEnum]))
		{
			cout << "Zly format pliku, koluma punkty! Uczen(Wers w pilku) nr: " << ileWersow << " -- Nabor::wpis_z_pliku" << endl;
		}
		punktyUcznia = atoi(temp[punktyEnum].c_str());
		if (punktyUcznia<0 || punktyUcznia>100)
		{
			cout << "Blad! Niepoprawna ilosc punktow! Uczen(Wers w pilku) nr: " << ileWersow << " -- Nabor::wpis_z_pliku" << endl;
			return false;
		}

		bool poprawnyFormatDanych = true;
		for (int i = 0; i < jezykEnum; i++)
		{
			if (i == 2) continue;
			poprawnyFormatDanych = czyTabChar(temp[i]);
			
			if (!poprawnyFormatDanych)
			{
				cout << "Bledny format danych. Uczen(Wers w pliku) nr: " << ileWersow << " -- Nabor::wpis_z_pliku" << endl;
				cout << temp[i] << endl;
				return false;
			}
		}
		for (unsigned int i = wybor_1; i <= wybor_3; i++)
		{
			if (temp[i].length()> 1)
			{
				cout << "Bledny format preferowanego wyboru ucznia. Uczen(Wers w pliku) nr" << ileWersow << endl;
				return false;
			}
		}
		jezykWPodstawowce = strDoJezyk(temp[jezykEnum]);
		if (jezykWPodstawowce == Uczen::niemiecki) punktyUcznia += dodPunktyNiem;//Dodanie punkt�w uczniom z niemieckim jako jezykiem prowadzacym 
																				//w celu ustawienia ich na pocz�tku tabliy po posortowaniu
		wybor1Ucznia = strDoWybor(temp[wybor_1]);                               
		wybor2Ucznia = strDoWybor(temp[wybor_2]);
		wybor3Ucznia = strDoWybor(temp[wybor_3]);
		tabUczniow[ileWersow] = Uczen(temp[ImieEnum], temp[NazwiskoEnum], punktyUcznia, jezykWPodstawowce, wybor1Ucznia, wybor2Ucznia, wybor3Ucznia);
																								//stworzenie ucznia i wpisanie go do tablicy
		ileWersow++;
	}
	plik.close();
	sortowanieMalejace(tabUczniow);//Sortowanie malejace otrzymanej tabeli
	return true;
}

void Nabor::sortowanieMalejace(Uczen tabUczniow[])
{
	for (int i = ileWersow - 1; i >= 0; i--)
	for (int x = 0; x < i; x++)
	{
		if (tabUczniow[x].podaj_liczba_punktow() < tabUczniow[x + 1].podaj_liczba_punktow())
		{
			std::swap(tabUczniow[x], tabUczniow[x + 1]);

		}
	}
}

//Funckje wykorzystywane do okreslania poprawnosci formatu danych
bool czyInt(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
		{
			return false;
		}
	}
	return true;
}

bool czyTabChar(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!(isalpha(str[i]) || str[i] == 63 )) //Sprawdza czy string w csv sk�ada si� z samych liter
			//oraz ze wzgl�du na to �e polskie litery nie s� reprezentowane przez '?' W csv, akceptuje te� mo�liwo�� wyst�pienia '?'
		{
			return false;
		}
	}
	return true;
}