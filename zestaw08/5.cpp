#include <iostream>

template<typename  F>
double integrate(F f, double  min, double max, double ds) {
	double calka = 0;
	for(double x = min; x < max; x += ds) {
		calka += f(x);
	}
	return calka*ds;
}

template<typename T>
class Variable {
public:
	T operator()(T x) {
		 return x;
	}
};

template<typename T>
class Constant {
	T c;
public:
	Constant(T c) :c(c){};
	T operator()(T x) {return c;}
};

//klasa przenosząca informacje o typie
template<typename T, typename R = Variable<T> >
class Expr {
	R r;
public:
	Expr() {};
	Expr(R rep) : r(rep) {};
	T operator()(T x) {return r(x);}
	R rep() const {return r;};
};

template<typename T, typename LHS, typename RHS>
class AddExpr {
	LHS lhs;
	RHS rhs;
public:
	AddExpr(const LHS &l,const RHS &r) :lhs(l),rhs(r) {};
	T operator()(T x) {
		return lhs(x)+rhs(x);
	}
};

//operatory dodawania
template<typename T,typename LHS,typename RHS >
Expr<T,AddExpr<T,LHS,RHS> > operator+(const Expr<T,LHS> &l, const Expr<T,RHS> &r) {
	return Expr<T,AddExpr<T,LHS,RHS> >(AddExpr<T,LHS,RHS>(l.rep(),r.rep()));
};

template<typename T,typename LHS >
Expr<T,AddExpr<T,LHS,Constant<T> > > operator+(const Expr<T,LHS>  &l, T r) {
	return Expr<T,AddExpr<T,LHS,Constant<T> > >(AddExpr<T,LHS,Constant<T> >(l.rep(),Constant<T>(r)));
};

int main() {
	Expr<int> x;
	std::cout << "Całkowanie od 0 do 3 funkcji f(x) = x, przy czym x jest typu int: " << integrate(x, 0, 3, 0.001) << std::endl;
}
