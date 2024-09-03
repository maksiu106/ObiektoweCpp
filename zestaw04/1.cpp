#include <iostream>
#include <vector>

//szablon ogólny informujący o zwracanym typie
//trzeba uważać na to, czy istnieje domyślna wartość dla każdej wywoływanej cechy
template <class T>
struct sum_traits {
	typedef T type;
};

template <class T>
typename sum_traits<T>::type sum(T* beg, T* end) { //zwracamy typ określony przez specjalizację klasy cech
	typedef typename sum_traits<T>::type typ_zwracany;
	typ_zwracany result = typ_zwracany(); //inicjalizacja konstruktorem domyślnym - tu zerem
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
