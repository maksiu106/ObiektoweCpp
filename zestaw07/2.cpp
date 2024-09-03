#include <iostream>

template<int N, int M>
struct Pow{
	enum {val = Pow<N,M-1>::val * N};
};

template<int N>
struct Pow<N,0> {
	enum {val = 1};
};

int main() {
	std::cout << "2^3 to jest: " << Pow<2,3>::val << std::endl;
	std::cout << "3^3 to jest: " << Pow<3,3>::val << std::endl;
	std::cout << "4^2 to jest: " << Pow<4,2>::val << std::endl;
	std::cout << "1^7 to jest: " << Pow<1,7>::val << std::endl;
}
