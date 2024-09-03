#include <iostream>

//szablon funkcji convert z pierwszego zestawu
template <class T, class U>
T convert(U argument) {
	return static_cast<T>(argument);
}

template<>
int convert(double argument) {
	std::cout << "wywołano specjalizację zwracającą int" << std::endl;
	return static_cast<int>(argument);
}

template<>
double convert(double argument) {
	std::cout << "wywołano specjalizację zwracającą double" << std::endl;
	return static_cast<double>(argument);
}

int main() {
	std::cout << "Wywołanie funkcji zwracającej int: " << std::flush;
	int a = convert<int>(7.0);
	std::cout << "Wywołanie funkcji zwracającej double: " << std::flush;
	double b = convert<double>(5.5);
}
