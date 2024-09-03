#include <iostream>

//pierwsza zadeklarowana wartosc to wartosc zwracana
template <class T, class U>
T convert(U argument) {
	return static_cast<T>(argument);
}

int main() {
	std::cout << "Przetestuje teraz napisana funkcje konwertujaca" << std::endl;
	std::cout << "\tKonwersja argumentu 10 na typ float: " << convert<float, int>(10) << std::endl;
	std::cout << "\tKonwersja argumentu 'a' na typ int: " << convert<int, char>('a') << std::endl;
	std::cout << "\tKonwersja argumentu 97 na typ char: " << convert<char>(97) << std::endl;
}
