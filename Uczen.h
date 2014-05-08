#ifndef _UCZEN_H_
#define _UCZEN_H_

#include <string>
#include <iostream>

class Uczen
{
public:
    enum jezyk {angielski = 0, niemiecki, DUNNO};
    enum wybor {UNINITIALIZED=-1, A = 0,B,C,D,E,F,MAX_WYBOR};

private:
    std::string nazwisko;
    std::string imie;
    int punkty; //uczniowi przyznaje sie punkty za jezyk niemiecki +101, oraz za oceny z ostatniego roku szkolnego
    static const int liczba_wyborow = 3;//uczen okresla trzy oddzialy ktore go interesuja
    wybor wyborUcznia[liczba_wyborow];//uczen podaje swoje preferencje, w ktorym oddziale chce sie znalezc
    jezyk wyborJezyka;//uczen podaje jaki jezyk byl w podstawowce
    /*Name: ktoryPrzydzial - do trzymania informacji o sposobie dodania do oddzialu,
            np.
            UNINITIALIZED   oznacza, ze kandydat zostal dodany do oddzialu z braku miejsca w oddziale
            A .. F          oznacza dodanie po preferencjach
            MAX_WYBOR       oznacza dodanie wedlug kryterium, ze z jezykiem niemieckim do C.
    */
    std::string ktoryPrzydzial;
public:
    /* metoda podaj_nazwisko - zwraca stringa zawierajacego nazwisko i imie ucznia*/
    std::string podaj_nazwisko();
    /* metoda liczba_punktow -
    Wartosc zwracana: liczbe punktow ucznia; */
    int podaj_liczba_punktow();
    /* metoda podaj_jezyk -
    Wartosc zwracana: jezyka ucznia - 0 dla angielski, 1 dla niemiecki; */
    jezyk podaj_jezyk();
    /* metoda podaj_wybor -
    Argumenty wejscia: int ktory - przyjmuje wartosc wyboru oddzialu, ktory preferuje uczen.
    Wartosc zwracana: zwraca wybor odzialu preferowany przez ucznia; */
    wybor podaj_wybor(int);
    /*zapiszPunkty - metoda zapisuje liczbe punktow z procesu rekrutacji. miedzy innymi w klasie Nabor dodaje sie
    dodatkowe punkty za jezyk niemiecki, zeby ulatwic sekretariatowi przydzial do oddzialu c
    (wedlug zalecenia gimnazjum: z jezykiem niemieckim do oddzialu c, uczen trafil na poczatek listy uczniow:
     vector <Uczen> tabUczniow*/
    int zapiszPunkty( int ileOtrzymuje);
    /*Name: przydzielamDo - metoda zwraca ktory wybor zadecydowal o przydzieleniu do oddzialu
    Args: doOddzialu - nazwa oddzialu np. "A"
    Return: string, w ktorym jest zapisana odpowiednia duza litera lub "UNINITIALIZED", np. jesli uczen dostal sie
            do oddzialu, bo podal wyborUcznia[0] =  wybor::A, to w tym stringu bedzie "A"
    */
    std::string przydzielamDo(std::string doOddzialu);
    /*Name: pokazPrzydzial - metoda zwraca nazwe oddzialu np. "A", do ktorej przydzialono kandydata
     Return: string, w ktorym jest zapisana odpowiednia duza litera lub "UNINITIALIZED",
             UNINITIALIZED   oznacza, ze kandydat zostal dodany do oddzialu z braku miejsca w oddziale
             A .. F          oznacza dodanie po preferencjach
             MAX_WYBOR       oznacza dodanie wedlug kryterium, ze z jezykiem niemieckim do C.
             np. jesli uczen dostal sie do oddzialu, bo podal wyborUcznia[0] =  wybor::A, to w tym stringu bedzie "A"
         */
    std::string pokazPrzydzial();

    /*Name: zapisz_ktoryWyborZdecydowal - podczas rekrutacji prowadzonej przez sekretariat::start, zapisuje sie
            ktory wybor zdecydowal o dolaczeniu kandydata do danego oddzialu*/
    void zapisz_ktoryWyborZdecydowal( int tenWybor);
    /*nazwa: enumWyborToString - konwertuje typ enum wybor do string*/
    std::string enumWyborToString (wybor enumWybor);

    Uczen();
    Uczen(std::string aImie, std::string aNazwisko, int aPunkty,
          jezyk aJezyk, wybor aWybor1, wybor aWybor2, wybor aWybor3);
};
#endif
