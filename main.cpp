#include "sekretariat.h"


// Potrzeba nam programu, kt�ry obrobi automatem przydzielanie dzieciak�w z rekrutacji do otwieranych klas. Wymagania s� nast�puj�ce:
// - W przysz�ym roku szko�a planuje otworzy� 6 pierwszych klas.
// - Dostajemy list� dzieciak�w, kt�rzy zostali przyj�ci do szko�y. Wst�pnie mo�na przyj��, �e nie b�dzie ich wi�cej ni� 132.
// - Do ka�dego ucznia s� przypisane nast�puj�ce dane:
//    - imi�
//    - nazwisko
//    - lista uzyskanych punkt�w podczas rekrutacji (0-100)
//    - g��wny j�zyk obcy nauczony w poprzedniej szkole (angielski albo niemiecki)
//    - pierwszy wyb�r klasy (A-F)
//    - drugi wyb�r klasy (A-F)
//    - trzeci wyb�r klasy (A-F)
// - Dane mog� zosta� dostarczone w formie pliku csv
// - Maksymalna liczba uczni�w przydzielonych do jednej klasy to 22
// - Ka�dy ucze�, kt�rego g��wnym j�zykiem obcym w poprzedniej szkole by� niemiecki musi trafi� do klasy C, niezale�nie od pozosta�ych informacji. Mo�na przyj��, �e b�dzie ich mniej ni� 22.
// - Reszta uczni�w powinna trafi� do preferowanych klas zgodnie z ilo�ci� uzyskanych przez nich punkt�w i kolejno�ci� wyboru klasy.
// - Wynikiem dzia�ania programu powinno by� 6 plik�w zawieraj�cych imiona i nazwiska uczni�w przydzielonych do danej klasy. Wpisy powinny by� posortowane alfabetycznie wed�ug nazwiska.


int main()
{
	sekretariat oSekretariat("C:\\Users\\user\\Desktop\\GiT\\rekrutacja_kuznia\\lista.csv");
	getchar();
	return 0;
}
