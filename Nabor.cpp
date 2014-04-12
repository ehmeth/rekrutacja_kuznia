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
	return Nabor::ilu;
}

Nabor::Nabor(std::string sciezka_do_pliku)
:sciezka(sciezka_do_pliku) 
	{
	if(wpis_z_pliku(Nabor::sciezka, Nabor::tab) == false ) 
	{
		cout<<"Blad podczas otwierania pliku! -- Nabor::Nabor"<<endl;
		getchar();
	}
	}

bool Nabor::podaj_ucznia(int ktory, Uczen *kto)
	{
	if(ktory<0 || ktory>Nabor::ilu) return false;
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
		if(str == "A") return Uczen::A;
		if(str == "B") return Uczen::B;
		if(str == "C") return Uczen::C;
		if(str == "D") return Uczen::D;
		if(str == "E") return Uczen::E;
		if(str == "F") return Uczen::F;
	return Uczen::UNINITIALIZED; 
	}

Uczen::jezyk Nabor::str_to_jezyk(std::string str)
	{
		for(int i = 0; i<str.length(); i++)
		{
			if(str[i] == '\0') break;
			str[i] = tolower(str[i]);
		}
		if(str == "angielski") return Uczen::angielski;
		if(str == "niemiecki") return Uczen::niemiecki;
	return Uczen::DUNNO; 
	}

bool Nabor::wpis_z_pliku(const string sciezka, Uczen tab[])
	{
	Uczen::jezyk jezyk;
	Uczen::wybor wybor1;
	Uczen::wybor wybor2;
	Uczen::wybor wybor3;
	
	const int niemecki_dodatkowe_punkty = 101,max_indeks_n = 6, ilosc_komorek_danych = 7; 
	int n = 0, i = 0, punkty = 0;
	
	string s, temp[ilosc_komorek_danych];
	const std::string delimiter = ";";

	ifstream plik;
	plik.open(sciezka.c_str());
    if (plik.good() == false)
    {
        cout <<"Nie udalo sie otworzyc pliku -- Nabor::wpis_z_pliku"<<endl;
        getchar();
        return false;
    }
 	while(getline(plik,s))
 	{
 		n = 0;
		size_t pos = 0;
		while ((pos = s.find(delimiter)) != std::string::npos)
		{
			if(n > max_indeks_n)
			{
				cout<<"Zly format pliku, zbyt du?a ilosc kom?rek danych w wierszu -- Nabor::wpis_z_pliku"<<endl;
				getchar();
				return false;
			}
			if (  n < 0)
			{
				cout<<"Ujemna liczba kom?rek danych w wierszu...? -- Nabor::wpis_z_pliku"<<endl;
				getchar();
				return false;
			}
 		    temp[n] = s.substr(0, pos);
 		    s.erase(0, pos + delimiter.length());
 		    n++;
		}
		punkty = atoi(temp[punkty_e].c_str()); 
		jezyk = str_to_jezyk(temp[wybor_3]); 
		if(jezyk == Uczen::niemiecki) punkty += niemecki_dodatkowe_punkty;
		wybor1 = str_to_wybor(temp[jezyk_e]); 
		wybor2 = str_to_wybor(temp[wybor_1]); 
		wybor3 = str_to_wybor(temp[wybor_2]); 
		tab[i] = Uczen(temp[Imie_e],temp[Nazwisko_e],punkty,jezyk, wybor1, wybor2,wybor3); 
		i++;
 	}
 	Nabor::ilu = i;
    plik.close();
    sortuj(Nabor::ilu,Nabor::tab);
    return true;
	}

void Nabor::sortuj(int ilosc, Uczen tab[])
	{
	Uczen temp;
	for(int i = ilosc - 1; i>=0; i--)
		for(int l = 0; l<i; l++)
			{
				if(tab[l].podaj_liczba_punktow() < tab[l+1].podaj_liczba_punktow())
					{
						std::swap(tab[l], tab[l+1] );

					}
			}
	}

