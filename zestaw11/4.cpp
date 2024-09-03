#include <iostream>
#include <concepts>

//użycie konceptów przy przeciążaniu funkcji
//trzeba kompilować z flagą std=c++20

template <class T>
void foo(T a) {
	std::cout << "Do funckji przekazano argument " << a << " - nie jest to liczba całkowita, więc używam ogólnego szablonu" <<std::endl;
}

void foo(std::integral auto a) {
	std::cout << "Do funckji przekazano argument " << a << " - jest to liczba całkowita, więc używam funkcji przeciążonej dla integrali." << std::endl;;
}

int main() {
	int arg1 = 2;
	double arg2 = 3.2;
	std::string arg3 = "HEJECZKA";

	foo(arg1);
	foo(arg2);
	foo(arg3);
}
