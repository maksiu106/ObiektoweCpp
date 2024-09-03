#include <iostream>
#include <concepts>

//Koncept three_way_comparable odnosi się do operatora trójstanowego <=>
//I ma mówić, czy dany typ może być porównywany za jego pomocą
//trzeba kompilować z flagą std=c++20

template <std::three_way_comparable T>
auto compare(T a, T b) {
	return a<=>b;
}

int main() {
	int a, b;
	std::cout << "a = " << std::flush;
	std::cin >> a;
	std::cout << "b = " << std::flush;
	std::cin >> b;


	auto result = compare(a, b);
	if (result < 0) std::cout << "a jest mniejsze od b" << std::endl;
	else if (result > 0) std::cout << "a jest większe od b" << std::endl;
	else std::cout << "a oraz b są równe" << std::endl;
}
