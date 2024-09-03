#include <iostream>

template<int N> //pozatypowy parametr szablonu
class A {};

template <int K, template <int N> class klasa>
void f(klasa<K>) {
	std::cout << K << std::endl;
}

int main() {
	A<10> klasa1;
	A<50> klasa2;

	std::cout << "Wydedukowana wartosc pozatypowego argumentu szablonu dla pierwszej klasy: " << std::flush;
	f(klasa1);
	std::cout << "Wydedukowana wartosc pozatypowego argumentu szablonu dla drugiej klasy: " << std::flush;
	f(klasa2);
}
