#include <iostream>
#include <vector>

//szablon klas cech
template <class T>
struct sum_traits {
	typedef T sum_type;
};

//przepisanie value_type jako typu stowarzyszonego iteratora
template <class Iterator>
struct it_traits {
	typedef typename Iterator::value_type value_type;
};

//dla wskaźników jako argumentów wywołania funkcji sumującej
template <class T>
struct it_traits<T*> {
	typedef T value_type;
};

template <class T>
typename sum_traits<typename it_traits<T>::value_type>::sum_type sum(T beg, T end) {
	typedef typename it_traits<T>::value_type value_type;
	typedef typename sum_traits<value_type>::sum_type sum_type;
	sum_type result = sum_type();
	while (beg != end) {
		result += *beg;
		++beg;
	}
	return result;
}

int main() {
	std::vector<int> v;
	for (int i=0; i<10; ++i) v.push_back(i);
	std::cout << "Wyliczona za pomocą iteratora wektora suma wynosi: " << sum(v.begin(), v.end()) << std::endl;

	int array[10];
	for (int i=0; i<10; ++i) array[i] = i;
	int* begin = &array[0];
	int* end = &array[10];
	std::cout << "Wyliczona za pomocą wskaźników suma wynosi: " << sum(begin, end) << std::endl;
}
