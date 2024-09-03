#include <iostream>

template<int N>
struct silnia {
	enum {val = N*silnia<N-1>::val};
};

template<>
struct silnia<0> {
  enum {val = 1};
};

int main() {
	std::cout << "Silnia z 5 wynosi: " << silnia<5>::val << std::endl;
	std::cout << "Natomiast z 6: " << silnia<6>::val << std::endl;
}
