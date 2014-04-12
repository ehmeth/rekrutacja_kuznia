#ifndef _sekreteriat_h_
#define _sekreteriat_h_

#include <string>

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
		bool stworzOddzialy (); 
	////dodane przez marka
	//konstruktor:
	
	sekretariat(std::string plik_csv);
	
};
#endif
