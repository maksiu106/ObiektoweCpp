#include <iostream>

//szablony liczące silnię
template<int N>
struct silnia {
	enum {val = N*silnia<N-1>::val};
};

template<>
struct silnia<0> {
  enum {val = 1};
};

//szablony liczące potęgę
template <int N>
double pow(double x) {
	if (N%2 == 0) return pow<N/2>(x*x);
	else return x*pow<N/2>(x*x);
}

template<>
double pow<1>(double x) {
	return x;
};

template<>
double pow<0>(double x) {
	return 1;
};

//szablon liczący rozwinięcie funkcji sinus
template<int N>
double sin(double x) {
	if (N%2 == 0) return sin<N-1>(x) - pow<2*N-1>(x)/(double)silnia<2*N-1>::val;
	else return sin<N-1>(x) + pow<2*N-1>(x)/(double)silnia<2*N-1>::val;
}

template<>
double sin<0>(double x) {
	return 0;
}

int main() {
	std::cout << "Rozwinięcie 3-ego stopnia dla sinusa wokół punktu 0 wynosi: " << sin<3>(0) << std::endl;
	std::cout << "Rozwinięcie 2-ego stopnia dla sinusa wokół punktu 1.57079 wynosi: " << sin<2>(1.57079) << std::endl;
	std::cout << "Rozwinięcie 6-ego stopnia dla sinusa wokół punktu 1.57079 wynosi: " << sin<6>(1.57079) << std::endl;
}
