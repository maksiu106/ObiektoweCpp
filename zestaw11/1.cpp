#include <iostream>
#include <concepts>

//integral - koncept sprawdza, czy typ jest całkowitoliczbowy
//trzeba kompilować z flagą std=c++20

template <std::integral T>
T gcd(T a, T b) {
	while (b != 0) {
		T t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	long a = 363;
	long b = 171;
	std::cout << "Największy wspólny dzielnik liczb 363 oraz 171 to: " << gcd(a,b) << std::endl;
}
