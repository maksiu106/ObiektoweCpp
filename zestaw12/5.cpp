#include <iostream>

//Celem wzorca visitor jest przede wszystkim
//oddzielenie algorytmu od struktur danych
//Nie zmienia klasy obiektów, ale dodaje nowe operacje

class Circle;
class Square;

class Visitor {
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Square& square) = 0;
};

class Shape {
public:
	virtual void accept(Visitor& v) = 0;
};

class Square : public Shape {
	int a;
public:
	Square(int a) : a(a) {}
	void accept(Visitor& v) override {
		v.visit(*this);
	}
	int getVal() {return a;}
};

class Circle : public Shape {
	int r;
public:
	Circle(int r) : r(r) {}
	void accept(Visitor& v) override {
		v.visit(*this);
	}
	int getVal() {return r;}
};

class Area : public Visitor {
public:
	void visit(Circle& c) override {
		std::cout << "Area of this circle is " << c.getVal()*c.getVal()*3.1415 << std::endl;
	}
	void visit(Square& s) override {
		std::cout << "Area of this square is " << s.getVal()*s.getVal() << std::endl;
	}
};

int main() {
	Circle c(3);
	Square s(2);

	Area a;

	c.accept(a);
	s.accept(a);
}
