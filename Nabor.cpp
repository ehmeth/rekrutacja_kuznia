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
    //Ilosc wersow w pliku jest rowna ilosci uczniow
	return ileWersow;
}

Nabor::Nabor(string sciezkaDoPliku)
{
	setlocale(LC_ALL, "");
    
	if (sciezkaDoPliku == "")
	{
		cout << "Brak sciezki do pliku! -- Nabor::Nabor" << endl;
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
	if (str[0] == 'A') return Uczen::A;
	if (str[0] == 'B') return Uczen::B;
	if (str[0] == 'C') return Uczen::C;
	if (str[0] == 'D') return Uczen::D;
	if (str[0] == 'E') return Uczen::E;
	if (str[0] == 'F') return Uczen::F;
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
	
	const int dodPunktyNiem = 101, maxKomorek = 12, ilInformacjiWPliku = 13;
	int indeksInfZPliku = 0, punktyUcznia = 0; 

	string sZawartoscDanych, temp[ilInformacjiWPliku];
	const string delimiter = ";";

	ifstream plik;
	plik.open(sciezkaDoPliku.c_str());
    
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku -- Nabor::wpis_z_pliku" << endl;
		return false;
	}
    
    //Odczytanie informacji z pliku i zapisanie ich wkolejnych miejscach tabeli.
	while (getline(plik, sZawartoscDanych))
    {
		indeksInfZPliku = 0;
		size_t pos = 0;
        
		while ((pos = sZawartoscDanych.find(delimiter)) != string::npos)
		{
			if (indeksInfZPliku > maxKomorek)
			{
				cout << "Zly format pliku, zbyt duza ilosc komorek danych w wierszu. Uczen(Wers w pilku) nr: " << ileWersow << "  -- Nabor::wpis_z_pliku" << endl;
				return false;
			}
            
            //Przypisanie do tymczasowej tablicy kolejnych stringow z pliku.
			temp[indeksInfZPliku] = sZawartoscDanych.substr(0, pos);
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
        
        //Dodanie punktow uczniom z niemieckim jako jezykiem prowadzacym w celu ustawienia ich na pocz¹tku tabliy po posortowaniu.
		if (jezykWPodstawowce == Uczen::niemiecki) punktyUcznia += dodPunktyNiem;
		wybor1Ucznia = strDoWybor(temp[wybor_1]);                               
		wybor2Ucznia = strDoWybor(temp[wybor_2]);
		wybor3Ucznia = strDoWybor(temp[wybor_3]);
        
        //stworzenie ucznia i wpisanie go do tablicy.
		tabUczniow.push_back(Uczen(temp[ImieEnum], temp[NazwiskoEnum], punktyUcznia, jezykWPodstawowce, wybor1Ucznia, wybor2Ucznia, wybor3Ucznia));
	}
	plik.close();
	ileWersow = tabUczniow.size();
    
    //Sortowanie malejace otrzymanej tabeli.
	sortowanieMalejace(tabUczniow);
	return true;
}

void Nabor::sortowanieMalejace(vector <Uczen> tabUczniow)
{
	for (int i = ileWersow - 1; i >= 0; i--)
	for (int x = 0; x < i; x++)
	{
		if (tabUczniow[x].podaj_liczba_punktow() < tabUczniow[x + 1].podaj_liczba_punktow())
		{
			swap(tabUczniow[x], tabUczniow[x + 1]);

		}
	}
}

//Funckje wykorzystywane do okreslania poprawnosci formatu danych.
bool czyInt(std::string str)
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
		if (!(isalpha(str[i]) || str[i] == 63 )) //Sprawdza czy string w csv sk³ada siê z samych liter.
		{
			return false;
		}
	}
	return true;
}