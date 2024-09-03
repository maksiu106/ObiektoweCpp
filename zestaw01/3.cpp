#include <iostream>

template <int N, class T> //pozatypowy parametr szablonu - wymiar wektora
T dot_product(T *a, T* b) {
	T result = 0;
	for (int i=0; i<N; ++i) {
		result += a[i]*b[i];
	}
	return result;
}

template <int N, class T>
void print_vector(T *a) {
	for (int i=0; i<N; ++i) {
		std::cout << a[i] << "  " << std::flush;
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "Ten program policzy iloczyn skalarny dwoch wektorow" << std::endl;
	int v1[3] = {10, 2, 3};
	int v2[3] = {0, 5, 1};
	std::cout << "\tWektor pierwszy: " << std::flush;
	print_vector<3>(v1);
	std::cout << "\tWektor drugi: " << std::flush;
	print_vector<3>(v2);
	std::cout << "\tIch iloczyn skalarny wynosi: " << dot_product<3>(v1, v2) << std::endl;

	std::cout << "Powtorzenie obliczen dla innego typu i wymiaru wektorow" << std::endl;
	double v3[4] = {10.2, 2.5, 3.4, 2.0};
	double v4[4] = {0.1, 5.4, 1.5, 4.2};
	std::cout << "\tWektor pierwszy: " << std::flush;
	print_vector<4>(v3);
	std::cout << "\tWektor drugi: " << std::flush;
	 print_vector<4>(v4);
	std::cout << "\tIch iloczyn skalarny wynosi: " << dot_product<4>(v3, v4) << std::endl;
}
