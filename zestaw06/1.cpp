#include <iostream>
using std::cin;
using std::cout;

#include "kolor.h"
#include "fab_kol.h"

template <int r=0, int g=0, int b=0>
class MojaPolityka
{
public:
    Kolor nieznanyKolor(std::string nazwa) {
    	std::cout << "Znaleziono nieznany kolor, więc poliyka automaytycznie ustawia go na kolor podany jako parametr szablonu" << std::endl;
    	return Kolor(r, g ,b);
    }
};

FabrykaKolorow<> fabryka;
FabrykaKolorow<MojaPolityka<0, 255, 0> > moja_fabryka;

int main()
{
    try {
        cout << fabryka.zwrocKolor("zielony") << '\n';
        cout << fabryka.zwrocKolor("green") << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }

    cout << moja_fabryka.zwrocKolor("zielony") << '\n';
    cout << moja_fabryka.zwrocKolor("green") << '\n';

    return 0;
}

