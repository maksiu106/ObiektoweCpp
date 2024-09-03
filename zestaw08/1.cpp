#include <iostream>
#include <math.h>

//szablon wyrażenia zapamiętujący stan funkcji
class sina {
	double a;
public:
	sina(double var): a(var) {};
	double operator()(double x) {return sin(a*x);}
};

//szablon całkujący
template<typename  F>
double integrate(F f, double  min, double max, double ds) {
	double calka = 0;
	for(double x = min; x < max; x += ds) {
		calka += f(x);
	}
	return calka*ds;
}

int main() {
	std::cout << "Całkowanie różnych sinusów w zakresie od 0 do pi" << std::endl;
	std::cout << "Całka z sin(0): " << integrate(sina(0), 0, 3.1415926, 0.01) << std::endl;
	std::cout << "Całka z sin(x): " << integrate(sina(1), 0, 3.1415926, 0.01) << std::endl;
	std::cout << "Całka z sin(2x): " << integrate(sina(2), 0, 3.1415926, 0.01) << std::endl;
}
