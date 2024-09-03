#include <iostream>

//wzorzec dekorator pozwala umieścić obiekty
//w innych obiektach je opakowujących
//i dzięku temu nadać im nowe obowiązki
//dekorator nadpisując daną metodę
//wywołuje ją niezmienioną samą w sobie
//ale przed albo po jej wywołaniu robi dodatkowe rzeczy
//Można zmieniać właściwości obiektu nie zmieniając jego klasy

class klasa {
public:
	virtual ~klasa() {}
	virtual std::string operacja() {return "operacja domyślna";}
};

class konkretna_klasa : public klasa {
public:
	std::string operacja() override {
		return "konkretna klasa - konkretna operacja";
	}
};

//bazowy dekorator
class dekorator : public klasa {
protected:
	klasa* instancja;
public:
	dekorator(klasa* k) : instancja(k) {}
	std::string operacja() override {
		return instancja->operacja();
	}
};

//konkretny dekorator, obudowujący działanie samej metody obiektu
class konkretny_dekorator : public dekorator {
public:
	konkretny_dekorator(klasa* k) : dekorator(k) {}
	std::string operacja() override {
		return "To jest obudowanie operacji, a to: " + instancja->operacja();
	}
};

int main() {
	klasa* obiekt = new konkretna_klasa();
	std::cout << "\tWywołanie metody nieobudowanego, prostego obiektu" << std::endl;
	std::cout << obiekt->operacja() << std::endl;

	klasa* dekorator = new konkretny_dekorator(obiekt);
	std::cout << "\tWywołanie metody na dekoratorze tego obiektu" << std::endl;
	std::cout << dekorator->operacja() << std::endl;

	delete obiekt;
	delete dekorator;
}
