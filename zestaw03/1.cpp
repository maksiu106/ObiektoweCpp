#include <iostream>
#include <cstddef>
#include <cstring>

template <class T>
T max(T a, T b) {
	std::cout << "Uzywam funkcji 1. " << std::flush;
	return (a>b) ? a : b;
}

template <class T>
T* max(T* a, T*b) {
	std::cout << "Uzywam funkcji 2. " << std::flush;
	return (a>b) ? a : b;
}

template <class T>
T max(T* data, size_t n) {
	std::cout << "Uzywam funkcji 3. " << std::flush;
	size_t maximum = 0;
	for (size_t i=0; i<n; ++i) {
		if (data[i] > data[maximum]) maximum = i;
	}
	return data[maximum];
}

template<>
char* max(char* a, char* b) {
	std::cout << "Uzywam funkcji 4. " << std::flush;
	return (strcmp(a,b) > 0) ? a : b;
}

template<>
const char* max(const char *a, const char *b) {
	std::cout << "Uzywam funkcji 5. " << std::flush;
	return (strcmp(a,b) > 0) ? a : b;
}

template<class T>
const T* max(T *a,const T*b) {
	std::cout << "Uzywam funkcji 6. " << std::flush;
	return (a>b) ? a : b;
}

int main() {
	int a = 5, b = 7;
	std::cout << max(a, b) << " - wynik wywołania funkcji pierwszej " << std::endl;
	int* c = &a;
	int* d = &b;
	std::cout << max(c, d) << " - wynik wywołania funkcji drugiej " << std::endl;
	int data[] = {5, 7, 2};
	std::cout << max(data, 3) << " - wynik wywołania funkcji trzeciej " << std::endl;
	char s1[] = "mamma mia";
	char* p1 = s1;
	char s2[] = "mame";
	char* p2 = s2;
	std::cout << max(p1, p2) << " - wynik wywołania funkcji czwartej " << std::endl;
	const char* s3 = "mamma mia";
	const char* s4 = "mame";
	std::cout << max(s3,s4) << " - wynik wywołania funkcji piątej " << std::endl;
	std::cout << max(p1,s4) << " - wynik wywołania funkcji szóstej " << std::endl;
}
