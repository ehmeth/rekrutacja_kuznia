#ifndef _SEKRETARIAT_H_
#define _SEKRETARIAT_H_

#include <string>
#include <iostream>

class sekretariat
{
	public:
	/*	start - funkcja wywolywana do startu procesu: tworzy obiekt nabor z pliku zewnetrznego
	Arg.we:
	string plik_csv - nazwa pliku wejsciowego z danymi o kandydatach.
	Zwracane:
	true - poprawnie stworzono 6 klas, 
	false - nie udalo sie		
	*/	
		
		bool start (std::string plik_csv);
		enum przypisanie_kandydata { BRAK = 0, PIERWSZY_W, DRUGI_W, TRZECI_W, WYBOR_PO_JEZYKU, WYBOR_POZA_PREFERENCJA };
		bool stworzOddzialy (); 
	////dodane przez marka
	//konstruktor:
	
	sekretariat(std::string plik_csv);
	
};


#endif // _SEKRETARIAT_H_
