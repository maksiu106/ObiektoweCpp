#include <iostream>
#include <vector>

template <class T>
struct sum_traits {
	typedef T type;
};

//szablon ogólny dla sytuacji, w której chce się rzutować wartości na iny typ
template <class Traits, class T>
typename Traits::type sum(T* beg, T* end) {
	typedef typename Traits::type typ_zwracany;
	typ_zwracany result = typ_zwracany(); //inicjalizacja zera odpowiednią metodą
	while (beg != end) {
		result += *beg;
		++beg;
	}
	return result;
}

//przeciążenie szablonu
template <class T>
typename sum_traits<T>::type sum(T* beg, T* end) {
	return sum<sum_traits<T>, T>(beg, end);
}

int main() {
	char array[3] = {'a', 'b', 'c'};
	char* begin = &array[0];
	char* end = &array[3];
	std::cout << "Wyliczona suma wynosi: " << (int)sum(begin, end) << std::endl;
	std::cout << "Wyliczona suma wynosi: " << (int)sum<char>(begin, end) << std::endl;
}
