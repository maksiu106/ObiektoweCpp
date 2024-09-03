#include <iostream>
#include <vector>

template<size_t N>
double inner(double *x, double *y) {
	return (*x)*(*y) + inner<N-1>(++x, ++y);
}

template<>
double inner<1>(double *x, double *y) {
	return (*x)*(*y);
}

int main() {
	double x[] = {1.0, 1.0, 2.0};
	double y[] = {1.0, 1.0, 2.0};
	std::cout << "Iloczyn skalarny wektorów (1,1,2) oraz (1,1,2) wynosi: " << inner<3>(x,y) << std::endl;
}
