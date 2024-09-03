#include <iostream>

template<typename  F>
double integrate(F f, double  min, double max, double ds) {
	double calka = 0;
	for(double x = min; x < max; x += ds) {
		calka += f(x);
	}
	return calka*ds;
}

//przeładowanie dla funkcji dwuargumentowej
template<typename F>
double integrate(F f, double min_x, double max_x, double min_y, double max_y, double ds) {
	double calka = 0;
	for(double x = min_x; x < max_x; x += ds) {
		for(double y = min_y; y < max_y; y += ds) {
			calka += f(x, y);
		}
	}
	return calka*ds*ds;
}

class First {
public:
	double operator()(double x) {return x;}
	double operator()(double x, double) {return x;}
};

class Second {
public:
	double operator()(double, double y) {return y;}
};

class Constant {
	double c;
public:
	Constant(double arg) : c(arg){};
	double operator()(double) {return c;}
	double operator()(double, double) {return c;}
};

template<typename LHS, typename RHS>
class AddExpr {
	LHS lhs;
	RHS rhs;
public:
	AddExpr(const LHS &l, const RHS &r) : lhs(l), rhs(r) {};
	double operator()(double x) {
		return lhs(x)+rhs(x);
	}
	double operator()(double x,double y) {
		return lhs(x,y)+rhs(x,y);
	}
};
template<typename LHS, typename RHS>
AddExpr<LHS,RHS> operator+(const LHS &l, const RHS &r) {
	return AddExpr<LHS,RHS>(l,r);
};

int main() {
	First x;
	Second y;
	std::cout << "Całkowanie funkcji f(x,y) = x+y w granicach x od 0 do 1 oraz y od 0 do 2: " << integrate(x+y, 0, 1, 0, 2, 0.001) << std::endl;
}
