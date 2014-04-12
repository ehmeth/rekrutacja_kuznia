// NIE DOKONCZONY

#include "Nabor.h"

bool sekretariat::start (std::string plik_csv)
{
	Nabor nowyNabor(plik_csv);
//	Uczen kandydat;
//	oddzial klasy[uczen::wybor::MAX_WYBOR];
//	
//	for(int i = 0; i < rozmiar; i++) // przypisanie uczniow do oddzialow
//	{
//		bool kandydatDodany = false;
//		
//		if (nowyNabor.podaj_ucznia(i, &kandydat))
//		{
//			if (kandydat.podaj_jezyk == uczen::jezyk::niemiecki) // kandydat z jez. niemieckim
//			{
//				klasa[C].dodajUcznia(kandydat);				
//			}
//			else // dodawanie po preferencjach kandydata
//			{
//				
//				for (int j = 0; j < 3; j++) // j = preferencje kandydata
//				{
//					int X = kandydat.podaj_wybor(j);
//					if(klasa[X].dodajUcznia(kandydat))
//					{
//						kandydatDodany = true; // kandydat dodany wg swoich preferencji
//						break;
//					}					
//					
//				}
//				if (kandydatDodany == false) 
//				// nieudane przypisanie po preferencjach, przypisanie do pierwszego wolnego miejsca
//				{
//					for (int j = 0; j < 6; j++) // j = numery wszystkich oddzialow
//					{
//						if(klasa[j].dodajUcznia(kandydat))
//						// TO DO						
//					}
//				}
//				//dodaje ucznia do pierwszej klasy w ktorej sa wolne miejsca
//			}
//		}
//	}
}



bool sekretariat::stworzOddzialy ()
{
} 

	////dodane przez marka
	//konstruktor:
	
sekretariat::sekretariat(std::string plik_csv)
	{
		start(plik_csv);
	}
