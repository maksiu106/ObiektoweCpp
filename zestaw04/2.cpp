#include <iostream>
#include <vector>

//Szablon klas cech
template<class T> struct sum_traits;
//Jego specjalizacje definiujące czym jest wartość domyślna (zero)
template<> struct sum_traits<char> {
	typedef int type;
	static type zero() {return 0;}
};
template<> struct sum_traits<int> {
	typedef double type;
	static type zero() {return 0;}
};
template<> struct sum_traits<float> {
	typedef double type;
	static type zero() {return 0.0f;}
};
template<> struct sum_traits<double> {
	typedef double type;
	static type zero() {return 0.0;}
};

template <class T>
typename sum_traits<T>::type sum(T* beg, T* end) {
	typedef typename sum_traits<T>::type typ_zwracany;
	typ_zwracany result = sum_traits<T>::zero(); //inicjalizacja zera odpowiednią metodą
	while (beg != end) {
		result += *beg;
		++beg;
	}
	return result;
}

int main() {
	int array[10];
	for (int i=0; i<10; ++i) array[i] = i;
	int* begin = &array[0];
	int* end = &array[10];
	std::cout << "Wyliczona suma wynosi: " << sum(begin, end) << std::endl;
}
