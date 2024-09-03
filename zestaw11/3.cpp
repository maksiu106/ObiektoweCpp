#include <iostream>
#include <vector>
#include <concepts>

//prosta klasa MyVector zawiera typy MyInt
//kiedy konstruktor kopiujący MyInt stanie się prywatny
//wyskakuje błąd kompilacji ze względu na to
//że elementy w MyVector muszą być copyable
//trzeba kompilować z flagą std=c++20

template <std::copyable T>
class MyVector {
	int elem;
	int last;
	T* data;
public:
	MyVector() : elem(10), last(0) { //konstruktor domyślny
		data = new T[elem];
	}

	~MyVector() {
		delete[] data;
	}

	void push_back(T a) {
		data[last] = a;
		++last;
	}

	int size() {
		return last;
	}
};

class MyInt {
	int a;
public:
	MyInt() : a(0) {}
	MyInt(int val) : a(val) {}

//UWAGA - odkomentuj linię 'private', aby program przestał się kompilować
//wówczas klasa MyInt przestaje być kopiowalna

//private:
	MyInt(const MyInt& b) : a(b.a) {} //konstrukor kopiujący
};

int main() {
	MyVector<MyInt> v1;
	MyInt a(2);
	MyInt b(3);

	v1.push_back(a);
	v1.push_back(b);
}
