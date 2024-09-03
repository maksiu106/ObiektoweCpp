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

//funktor symbolizujący dodawanie
template<typename LHS, typename RHS>
class AddExpr {
	LHS lhs;
	RHS rhs;
public:
	AddExpr(const LHS &l, const RHS &r) : lhs(l), rhs(r) {};
	double operator()(double x) {
		return lhs(x)+rhs(x);
	}
};

//przeładowanie operatora dodawania
template<typename LHS, typename RHS>
AddExpr<LHS,RHS> operator+(const LHS &l, const RHS &r) {
	return AddExpr<LHS,RHS>(l,r);
};

//specjalizacje dla dodawania stałej
template<typename LHS>
AddExpr<LHS,Constant> operator+(const LHS &l, double r) {
	return AddExpr<LHS, Constant>(l,Constant(r));
};
template<typename RHS>
AddExpr<Constant,RHS> operator+(double l,const RHS &r) {
	return AddExpr<Constant, RHS>(Constant(l),r);
};

//powtórzenie tego dla DivExpr
template<typename LHS, typename RHS>
class DivExpr {
	LHS lhs;
	RHS rhs;
public:
	DivExpr(const LHS &l, const RHS &r) : lhs(l), rhs(r) {};
	double operator()(double x) {
		return lhs(x) / rhs(x);
	}
};
template<typename LHS, typename RHS>
DivExpr<LHS,RHS> operator/(const LHS &l, const RHS &r) {
	return DivExpr<LHS,RHS>(l,r);
};
template<typename LHS>
DivExpr<LHS,Constant> operator/(const LHS &l, double r) {
	return DivExpr<LHS, Constant>(l,Constant(r));
};
template<typename RHS>
DivExpr<Constant,RHS> operator/(double l,const RHS &r) {
	return DivExpr<Constant, RHS>(Constant(l),r);
};
//powtórzenie tego dla SinExpr
template<typename T>
class SinExpr {
	T argument;
public:
	SinExpr(const T &arg) : argument(arg) {};
	double operator()(double x) {
		return sin(argument(x));
	}
};
template<typename T>
SinExpr<T> sin(const T &x) {
	return SinExpr<T>(x);
}

int main() {
	Variable x;
	double result = integrate(1./sin(x+1.), 0, 1, 0.001);
	std::cout << "Całkowanie funkcji w zakresie od 0 do 1" << std::endl;
	std::cout << "Całka z f(x) = 1/sin(x+1): " << result << std::endl;
}


