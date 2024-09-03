#include <iostream>

template <int N>
int pow(int x) {
	if (N%2 == 0) return pow<N/2>(x*x);
	else return x*pow<N/2>(x*x);
}

template<>
int pow<1>(int x) {
	return x;
};

template<>
int pow<0>(int x) {
	return 1;
};

int main() {
	std::cout << "2^3 to jest: " << pow<3>(2) << std::endl;
	std::cout << "3^3 to jest: " << pow<3>(3) << std::endl;
	std::cout << "4^2 to jest: " << pow<2>(4) << std::endl;
	std::cout << "1^7 to jest: " << pow<7>(1) << std::endl;
}
