#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#include "sekretariat.h"
#include <vector>
#include <iterator>
using namespace std;

sekretariat::sekretariat(std::string plik_csv)
{
    start(plik_csv);
}

bool sekretariat::start(std::string plik_csv)
{
    std::cout << "Rekrutacja: przydzielanie kandydatow do oddzialow.\nPobieram dane: ";

    Nabor nowyNabor(plik_csv);
    if ( false == nowyNabor.pobranieDanych(plik_csv) )
    {
        cout << "Blad podczas wpisywania danych z pliku!" << endl;
        return false;
    }
    else
    {
        std::cout << "OK" << std::endl ;
    }

    Uczen kandydat;

    bool kandydatDodany     = false;
    dodajUczniaPoJezyku(&nowyNabor,&kandydat,Uczen::niemiecki,Uczen::C);

    dodajUczniaPreferen(&nowyNabor,&kandydat);

    kandydatDodany = czyWszyscyDodani();
    stworzOddzialy();

    return kandydatDodany;
}


bool sekretariat::stworzOddzialy()
{
    //tablica do przechowywania informacji true jesli zapis do pliku sie powiudl
    bool t_czyZapisalemOddzial[Uczen::MAX_WYBOR] = { false };

    std::string nazwaPlikuWynikowego = "";

    for (int j = 0; j < Uczen::MAX_WYBOR; j++)
    {
        //budowa nowej nazwy pliku wynikowego jako sumy trzech skladnkow
        nazwaPlikuWynikowego = "klasa";
        nazwaPlikuWynikowego += ((char)(65 + j)); //np dla j = 0 to jest litera 'A'
        nazwaPlikuWynikowego += ".csv";


        if (tab_oddzial[j].wypiszListeUczniow(nazwaPlikuWynikowego))
        {
            t_czyZapisalemOddzial[j] = true;
        }
        else
        {
            t_czyZapisalemOddzial[j] = false;

            std::cout << std::endl << "ERROR w metodzie sekretariat::stworzOddzialy ();"
                      <<   std::endl << "nie zapisano do pliku oddzialu " << (char)(65 + j) << std::endl;
        }
    }

    bool czyZapisaneOddzialy = true;

    for (int j = 0; j < Uczen::MAX_WYBOR; j++)
    {
        czyZapisaneOddzialy = (czyZapisaneOddzialy && t_czyZapisalemOddzial[j]); //true jesli (true && true)
    }

    return czyZapisaneOddzialy; //true jesli wszystkie elementy tablicy t_czyZapisalemOddzial sa true;
}

void sekretariat::dodajUczniaPoJezyku(Nabor * pNabor, Uczen * pUczen, Uczen::jezyk obcyJezyk, Uczen::wybor doOddzialu)
{
    unsigned int nrKandydata = 0;
    while ( pNabor->podaj_ucznia(nrKandydata,pUczen) )
    {
        if (obcyJezyk == pUczen->podaj_jezyk())
        {
            pUczen->przydzielamDo("j.niemiecki");
            //dodajUcznia zwraca true, jesli dodal kandydata do oddzialu
            if( false == tab_oddzial[doOddzialu].dodajUcznia(*pUczen))
            {
                pUczen->przydzielamDo("");
                deq_OddzialTymczasowy.push_back(*pUczen);
            }

        }
        else
        {
            deq_OddzialTymczasowy.push_back(*pUczen);
        }
    nrKandydata++;
    }
}
void sekretariat::dodajUczniaPreferen(Nabor * pNabor, Uczen * pUczen)
{
    for (int j = 0; j < 3/*Uczen::MAX_WYBOR*/; j++)
    {

stringstream ss;
ss << j+1;
string ktoraPreferencja = ss.str();
       for( deque<Uczen>::iterator ite = deq_OddzialTymczasowy.begin(); ite != deq_OddzialTymczasowy.end(); ite ++)
        {

            *pUczen = *ite;
            switch (pUczen->podaj_wybor(j))
            {
                case Uczen::A :
                    {
                        pUczen->przydzielamDo(ktoraPreferencja);
                        if(false == tab_oddzial[Uczen::A].dodajUcznia(*pUczen))
                        {
                            pUczen->przydzielamDo("");
                        }
                        else
                        {
                            deq_OddzialTymczasowy.erase(ite);
                            ite--;
                        }
                        break;
                    }
                case Uczen::B :
                     {
                        pUczen->przydzielamDo(ktoraPreferencja);
                        if(false == tab_oddzial[Uczen::B].dodajUcznia(*pUczen))
                        {
                            pUczen->przydzielamDo("");
                        }
                        else
                        {
                            deq_OddzialTymczasowy.erase(ite);
                            ite--;
                        }
                        break;
                    }
                case Uczen::C :
                    {
                        pUczen->przydzielamDo(ktoraPreferencja);
                        if(false == tab_oddzial[Uczen::C].dodajUcznia(*pUczen))
                        {
                            pUczen->przydzielamDo("");
                        }
                        else
                        {
                            deq_OddzialTymczasowy.erase(ite);
                            ite--;
                        }
                        break;
                    }
                case Uczen::D :
                    {
                        pUczen->przydzielamDo(ktoraPreferencja);
                        if(false == tab_oddzial[Uczen::D].dodajUcznia(*pUczen))
                        {
                            pUczen->przydzielamDo("");
                        }
                        else
                        {
                            deq_OddzialTymczasowy.erase(ite);
                            ite--;
                        }
                        break;
                    }
                case Uczen::E :
                    {
                        pUczen->przydzielamDo(ktoraPreferencja);
                        if(false == tab_oddzial[Uczen::E].dodajUcznia(*pUczen))
                        {
                            pUczen->przydzielamDo("");
                        }
                        else
                        {
                            deq_OddzialTymczasowy.erase(ite);
                            ite--;
                        }
                        break;
                    }
                case Uczen::F :
                     {
                        pUczen->przydzielamDo(ktoraPreferencja);
                        if(false == tab_oddzial[Uczen::F].dodajUcznia(*pUczen))
                        {
                            pUczen->przydzielamDo("");
                        }
                        else
                        {
                            deq_OddzialTymczasowy.erase(ite);
                            ite--;
                        }
                        break;
                    }
               default :
                    {
                        pUczen->przydzielamDo("innyOddzial");
                        std::cout<< "Uwaga, Kandydat nie przydzielony do istniejacych oddzialow";
                        innyOddzial.push_back(*pUczen);
                        deq_OddzialTymczasowy.erase(ite);
                        ite--;
                        break;
                    }

            }

        }//for( deque<Uczen>::iterator ite = deq_OddzialTymczasowy.begin(); ite < deq_OddzialTymczasowy.end(); ite ++)

    }//for (int j = 0; j < Uczen::MAX_WYBOR; j++)

    std::cout << std::endl << "Dodano kandydatow po preferencjach\nPozostali:";
}
bool sekretariat::czyWszyscyDodani()
{

    if ( ! innyOddzial.empty())
    {   // true: zapisz kandydatow nie przydzielonych do pliku
        Uczen kandydat;
        std::ofstream outInnyOddzial("klasa_Kandydaci_Nieprzydzieleni.csv");
        if (outInnyOddzial.is_open())
        {
            for( vector<Uczen>::iterator ite = innyOddzial.begin(); ite != innyOddzial.end(); ite ++)
            {
                kandydat = *ite;
                outInnyOddzial
                    << kandydat.podaj_nazwisko()    << ";"
                    << (char)(kandydat.podaj_wybor(0) + 65)     << ";"
                    << (char)(kandydat.podaj_wybor(1) + 65)     << ";"
                    << (char)(kandydat.podaj_wybor(2) + 65)     << ";"
                    << kandydat.podaj_jezyk()       << ";"
                    << kandydat.podaj_liczba_punktow() << ";"
                    <<'\n';
            }
        }
        outInnyOddzial.close();

        int i = 0;
        for( vector<Uczen>::iterator ite = innyOddzial.begin(); ite != innyOddzial.end(); ite ++)
        {
            kandydat = *ite;
            std::cout << std::endl << i + 1 << " " << kandydat.podaj_nazwisko()
            << ";  Preferencje :";
            for (int j = 0; j < 3; j++)//licza 3, bo uczen ma trzy preferencje
            {
                std::cout<<(char) (kandydat.podaj_wybor(j) + 65) << ",";
            }
            std::cout <<"; Punkty " << kandydat.podaj_liczba_punktow();
            i++;
        }
        return false;
    }
    else
    {   //false:
        std::ofstream outInnyOddzial("klasa_Kandydaci_Nieprzydzieleni.csv");
        std::cout << "Wszyscy kandydaci zostali przydzieleni do oddzialow.";
        outInnyOddzial.close();
        return true;
    }

}
