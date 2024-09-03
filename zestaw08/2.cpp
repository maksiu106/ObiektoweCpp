#include <iostream>
#include <math.h>

//szablon całkujący
template<typename  F>
double integrate(F f, double  min, double max, double ds) {
	double calka = 0;
	for(double x = min; x < max; x += ds) {
		calka += f(x);
	}
	return calka*ds;
}

//funktor zwracający zmienną - samą siebie
class Variable {
public:
	double operator()(double x) {
	return x;
  }
};

//funktor zwracający stałą
class Constant {
	double c;
public:
	Constant(double var) : c(var) {};
	double operator()(double var) {
		return c;
	}
};

int main() {
	Variable x;
	Constant c(1);
	double result1 = integrate(x, 0, 1, 0.001);
	double result2 = integrate(c, 0, 1, 0.001);

	std::cout << "Całkowanie funkcji w zakresie od 0 do 1" << std::endl;
	std::cout << "Całka z f(x) = x: " << result1 << std::endl;
	std::cout << "Całka z f(x) = 1: " << result2 << std::endl;
}


