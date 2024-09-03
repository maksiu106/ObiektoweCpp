#include <iostream>
#include <memory>

struct A {
	A(int a, int b, int c) {}
};

int main() {
	//użycie szablonu template< class T, class... Args > unique_ptr<T> make_unique( Args&&... args )
	//wykorzystywane kiedy konstruktor obiektu ma specyficzne argumenty
	//któ©e muszą zostać wywołane
	auto ptr = std::make_unique<A>(2, 4, 7);

	//użycie szablonu template< class T > unique_ptr<T> make_unique( std::size_t size );
	//służy do tworzenia dynamicznych tablic o określonym rozmiarze
	//unique_ptr zajmuje się zarządzaniem pamięcią i jej zwalnianiem
	auto array_ptr = std::make_unique<int[]>(10);
}
