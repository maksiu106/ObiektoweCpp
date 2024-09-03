#include <iostream>
#include <vector>

//tworzenie szablonu wyrażeń, który dziedziczy z wektora
class Vector : public std::vector<double> {
public:
	//przepisanie konstruktorów
	Vector():std::vector<double>(){};
	Vector(int n):std::vector<double>(n){};
	Vector(int n,double x):std::vector<double>(n,x){};
	Vector(const Vector& v):std::vector<double>(static_cast<std::vector<double> >(v)){};
	Vector(const std::vector<double>& v):std::vector<double>(v) {};

	//nadpisanie operatora przypisania
	Vector &operator=(const Vector& rhs) {
		std::vector<double>::operator=(static_cast<std::vector<double> >(rhs));
		return *this;
	}
	template<typename V>
	Vector &operator=(const V &rhs) {
		for(size_t i = 0; i < std::vector<double>::size(); ++i) (*this)[i]=rhs[i];
		return *this;
	}
};

//skalar - wektor o wszystkich takich samych polach
class Const_vector {
	double c;
public:
	Const_vector(double arg):c(arg) {};
	double operator[](int i) const {return c;}
};

template<typename T>
struct V_expr_traits {
	typedef T const & op_type;
};

template<>
struct V_expr_traits<Const_vector> {
	typedef Const_vector  op_type;
};

//dodawanie wektorów
template<typename LHS,typename RHS>
class AddVectors {
	typename V_expr_traits<LHS>::op_type _lhs;
	typename V_expr_traits<RHS>::op_type _rhs;
public:
	AddVectors(const LHS &lhs,const RHS &rhs): _lhs(lhs),_rhs(rhs){};
	double operator[](int i) const {return _lhs[i]+_rhs[i];}
};
template<typename LHS,typename RHS>
inline AddVectors<LHS,RHS> operator+(const LHS &lhs,const RHS &rhs) {
	return AddVectors<LHS,RHS>(lhs,rhs);
}
template<typename LHS>
inline AddVectors<LHS,Const_vector> operator+(const LHS &lhs,double rhs) {
	return AddVectors<LHS,Const_vector>(lhs,Const_vector(rhs) );
}
template<typename RHS>
inline AddVectors<Const_vector, RHS> operator+(double lhs, const RHS &rhs) {
	return AddVectors<Const_vector, RHS>(Const_vector(lhs), rhs);
}

//mnożenie
template<typename LHS,typename RHS>
class MultVectors {
	typename V_expr_traits<LHS>::op_type _lhs;
	typename V_expr_traits<RHS>::op_type _rhs;
public:
	MultVectors(const LHS &lhs,const RHS &rhs): _lhs(lhs),_rhs(rhs){};
	double operator[](int i) const {return _lhs[i]*_rhs[i];}
};
template<typename LHS,typename RHS>
inline MultVectors<LHS,RHS> operator*(const LHS &lhs,const RHS &rhs) {
	return MultVectors<LHS,RHS>(lhs,rhs);
}
template<typename LHS>
inline MultVectors<LHS,Const_vector> operator*(const LHS &lhs,double rhs) {
	return MultVectors<LHS,Const_vector>(lhs,Const_vector(rhs) );
}
template<typename RHS>
inline MultVectors<Const_vector, RHS> operator*(double lhs, const RHS &rhs) {
	return MultVectors<Const_vector, RHS>(Const_vector(lhs), rhs);
}

int main() {
	Vector v1(100,1);
	Vector v2(100,2);
	Vector res(100);
	res = 1.2*v1+v1*v2+v2*0.5;
}

