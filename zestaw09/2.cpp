#include <memory>
#include <iostream>

int main() {
	int number = 7;
	int* a = &number;
	std::cout << "Rozmiar raw pointer od int: " << sizeof(a) << std::endl;

	std::unique_ptr<int> b(new int(7));
	std::cout << "Rozmiar unique pointer od int: " << sizeof(b) << std::endl;
}
