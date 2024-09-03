#include <iostream>

//wzorzec projektowy Singleton zapewnia, że w danym momencie
//istnieć będzie tylko jedna instancja danej klasy
//ponadto można mieć do niej globalny dostęp
//a jednocześnie mieć pewność, że z innych miejsc
//nic nie nadpisze tego obiektu

class A {
	A() {
		std::cout << "Stworzono obiekt klasy A!" << std::endl;
	}
	~A() {}
	A(const A&) = delete; //usunięty konstruktor kopiujący
	void operator=(const A&) = delete; //usunięty operator przypisania

public:
	static A* getInstance() {
		static A obiekt;
		return &obiekt;
	}
};

int main() {
	A* singleton = A::getInstance();
	std::cout << "Teraz spróbujemy stworzyć drugi." << std::endl;
	A* drugi = A::getInstance();
}
