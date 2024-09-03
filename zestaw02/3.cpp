#include <iostream>
#include <list>

template <class Iterator>
int accumulate (Iterator start, Iterator end) {
	int suma = 0;
	while (end != start) {
		suma += *start;
		++start;
	}
	return suma;
}

int main() {
	std::list<int> example;
	for (int i=0; i<10; ++i) {
		example.push_back(i);
	}

	std::cout << "Suma elementow w utworzonej liscie wynosi: " << accumulate (example.begin(), example.end()) << std::endl;
}
