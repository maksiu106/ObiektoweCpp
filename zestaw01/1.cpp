#include<iostream>

template <class T>
T maximum(T a, T b) {
	if (a > b) return a;
	else return b;
}

int main() {
	std::cout << "Przetestuje teraz napisana funkcje maksimum" << std::endl;
	std::cout << "\tNa argumentach 10 i 50 wynik wynosi: " << maximum(10,50) << std::endl;
	std::cout << "\tNa argumentach 10.5 i 10.2 wynik wynosi: " << maximum(10.5,10.2) << std::endl;
	std::cout << "\tNa argumentach 'Gerwazy' oraz 'Kunegunda' wynik wynosi: " << maximum("Gerwazy", "Kunegunda") << std::endl;
}
