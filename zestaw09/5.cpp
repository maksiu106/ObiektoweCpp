#include<iostream>
#include<memory>

struct A {
	A() {std::cout << "\tWYWOŁANO KONSTRUKTOR!" << std::endl;}
	~A() {std::cout << "\tWYWOŁANO DESTRUKTOR :c" << std::endl;}
};

int main() {
	std::cout << "Tworzymy obiekt typu A i wskazujący na niego shared pointer" << std::endl;
	std::shared_ptr<A> p1 = std::make_shared<A>();

	std::cout << "Tworzymy dwa kolejne shared pointer wskazujące na ten obiekt" << std::endl;
	std::shared_ptr<A> p2 = p1;
	std::shared_ptr<A> p3 = p1;

	std::cout << "Zerujemy pierwszy stworzony wskaźnik" << std::endl;
	p1.reset();
	std::cout << "Wyzerowane. Teraz zerujemy drugi stworzony wskaźnik" << std::endl;
	p2.reset();
	std::cout << "Też wyzerowane. Teraz zerujemy ostatni stworzony wskaźnik" << std::endl;
	p3.reset();
	std::cout << "OK, wyzerowano już wszystkie shared_ptr." << std::endl;
}
