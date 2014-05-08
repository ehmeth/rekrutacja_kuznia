#include "sekretariat.h"


// Potrzeba nam programu, który obrobi automatem przydzielanie dzieciaków z rekrutacji do otwieranych klas. Wymagania s¹ nastêpuj¹ce:
// - W przysz³ym roku szko³a planuje otworzyæ 6 pierwszych klas.
// - Dostajemy listê dzieciaków, którzy zostali przyjêci do szko³y. Wstêpnie mo¿na przyj¹æ, ¿e nie bêdzie ich wiêcej ni¿ 132.
// - Do ka¿dego ucznia s¹ przypisane nastêpuj¹ce dane:
//    - imiê
//    - nazwisko
//    - lista uzyskanych punktów podczas rekrutacji (0-100)
//    - g³ówny jêzyk obcy nauczony w poprzedniej szkole (angielski albo niemiecki)
//    - pierwszy wybór klasy (A-F)
//    - drugi wybór klasy (A-F)
//    - trzeci wybór klasy (A-F)
// - Dane mog¹ zostaæ dostarczone w formie pliku csv
// - Maksymalna liczba uczniów przydzielonych do jednej klasy to 22
// - Ka¿dy uczeñ, którego g³ównym jêzykiem obcym w poprzedniej szkole by³ niemiecki musi trafiæ do klasy C, niezale¿nie od pozosta³ych informacji. Mo¿na przyj¹æ, ¿e bêdzie ich mniej ni¿ 22.
// - Reszta uczniów powinna trafiæ do preferowanych klas zgodnie z iloœci¹ uzyskanych przez nich punktów i kolejnoœci¹ wyboru klasy.
// - Wynikiem dzia³ania programu powinno byæ 6 plików zawieraj¹cych imiona i nazwiska uczniów przydzielonych do danej klasy. Wpisy powinny byæ posortowane alfabetycznie wed³ug nazwiska.


int main()
{
    sekretariat oSekretariat("lista.csv");

    return 0;
}
