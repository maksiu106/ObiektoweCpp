#include <iostream>

//prosta implementacja szablonu stosu
template<class T>
class Stack {
private:
	T data[10];
	int position = -1;
public:
	typedef T value; //deklaracja typu elementów na stosie
	T top() {
		return data[position];
	}

	void push(T x) {
		++position;
		data[position] = x;
	}

	void pop() {
		--position;
	}

	bool empty() {
		if (position == -1) return true;
		else return false;
	}
};

template <class S>
typename S::value sum(S stos) { //typ stowarzyszony
	typename S::value sum = 0; //suma i wartość zwracana są tego typu, jakiego są elementy na stosie
	while (!stos.empty()) {
		sum += stos.top();
		stos.pop();
	}
	return sum;
}

int main() {
	Stack<int> stos;
	for (int i=0; i<10; ++i) {
		stos.push(i);
	}
	std::cout << "Utworzono stos zawierajacy kolejne liczby naturalne od 0 do 9" << std::endl;
	std::cout << "Suma elementow na tym stosie wynosi: " << sum(stos) << std::endl;
}
