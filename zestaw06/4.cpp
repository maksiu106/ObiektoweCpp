#include <iostream>

//klasa wytycznych implementująca brak obsługi błędów
struct No_checking_policy {
	static void check_push(size_t, size_t) {};
	static void check_pop(size_t) {};
	static void check_top(size_t) {};
};

template<typename T, size_t N = 0> struct Static_table_allocator {
	typedef T rep_type[N];
	void init(rep_type &,size_t) {};
	void expand_if_needed(rep_type &,size_t) {};
	void shrink_if_needed(rep_type &size_t) {};
	void dealocate(rep_type &){};
	static size_t size() {return N;};
};

//klasa wytycznych implementująca statyczną tablicę
template<typename T, size_t N> struct Dynamic_table_allocator {
	typedef T* rep_type;
	size_t _size;
	void init(rep_type & rep, size_t n) {
		_size=n;
		rep = new T [_size];;
	}
	void expand_if_needed(rep_type & rep, size_t top) {
		if (top == _size) {
			T* temp = new T[2*_size];
			for (int i=0; i<_size; ++i) {
				temp[i] = rep[i];
			}
			_size = 2*_size;
			delete[] rep;
			rep = temp;
		}
	};
	void shrink_if_needed(rep_type &size_t) {};
	void dealocate(rep_type &rep) {
		delete [] rep;
	};
	size_t size() {return _size;};
};

template<typename T = int , size_t N = 100, typename Checking_policy = No_checking_policy, template<typename U,size_t M>  class Allocator_policy = Static_table_allocator>
class Stack: private Checking_policy, private Allocator_policy<T,N> {
	typedef typename Allocator_policy<T,N>::rep_type rep_type;
	rep_type _rep;
	size_t _top;
public:
	Stack(size_t n = N):_top(0) {
		this->init(_rep,n);
	};
	void push(const T &val) {
		this->expand_if_needed(_rep,_top);
		Checking_policy::check_push(_top,this->size());
		_rep[_top++]=val;
	}
	void pop() {
		Checking_policy::check_pop(_top);
		--_top;
		this->shrink_if_needed(_rep,_top);
	}
	const T& top() const {
		Checking_policy::check_top(_top);
		return _rep[_top-1];
	}
	bool is_empty() {
		return !_top;
	}
	size_t size() {return this->_size;};
	~Stack() {this->dealocate(_rep);}
};

int main() {
	std::cout << "Testowanie stosu o ustawionym rozmiarze 1 i dynamicznie alokowanej pamięci - dodanie dwóch elementów 10 i 20." << std::endl;
	std::cout << "Ten stos różni się stosem z poprzedniego zadania tym, że zamiast tworzyć osobnego obiektu Allocator_policy, stosuje się dziedziczenie - stos dziedziczy po allocator." << std::endl;
	Stack<int, 1, No_checking_policy, Dynamic_table_allocator> stos;
	stos.push(10);
	stos.push(20);
	std::cout << "Teraz ma rozmiar: " << stos.size() << ", a na wierzchu ma element: " << stos.top() << std::endl;
}
