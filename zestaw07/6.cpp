#include <iostream>

//trzbea użyć klas pomocniczych, bo specjalizacja częściowa jest niedozwolona dla funkcji
template<size_t N, typename T>
struct inner {
	static T dot(T* x, T* y) {
		return (*x)*(*y) + inner<N-1, T>::dot(++x, ++y);
	}
};

template<typename T>
struct inner<1, T> {
	static T dot(T* x, T* y) {
		return (*x)*(*y);
	}
};

template<size_t N, typename T>
T dot(T* x, T* y) {
	return inner<N, T>::dot(x, y);
}

int main() {
	double x[] = {1.0, 1.0, 2.0};
	double y[] = {1.0, 1.0, 2.0};
	std::cout << "Iloczyn skalarny wektorów (1,1,2) oraz (1,1,2) typu double wynosi: " << dot<3, double>(x,y) << std::endl;
}
