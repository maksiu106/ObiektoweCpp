#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

//szablon funktoru
template<class T>
class SeqenceGen {
	T value;
	T step;
public:
	SeqenceGen(T x, T y) {
		value = x;
		step = y;
	}

	T operator()() {
		T temp = value;
		value += step;
		return temp;
	}
};

template <class Iterator, class Funktor>
Iterator generuj(Iterator value, int n, Funktor f) {
	for (int i=0; i<n; ++i) {
		*value = f();
		++value;
	}
	return value;
}

int main() {
	std::vector<int> v(20);
	generuj(v.begin(), 20, SeqenceGen<int>(1,2));

	std::cout << "Elementy w wektorze: " << std::flush;
	for (int i : v) {
		std::cout << i << " " << std::flush;
	}

	auto iterator = std::find_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4));
	std::cout << "\nZnaleziony element wiekszy od 4 to: " << *iterator << std::endl;
}
