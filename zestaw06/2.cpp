#include <iostream>

//klasa wytycznych implementująca brak obsługi błędów
struct No_checking_policy {
	static void check_push(size_t, size_t) {};
	static void check_pop(size_t) {
		std::cout << "Hej tu funkcja sprawdzajaca. Nic nie sprawdzam i nic nie robie, wolnoc tomku w swoim domku" << std::endl;
	};
	static void check_top(size_t) {};
};

//klasa wytycznych implementująca przerywanie przy wystąpieni ubłędu
class Abort_on_error_policy {
public:
	static void check_push(size_t top,size_t size) {
		if(top >= size) {
			std::cerr << "The stack is full - unable to push an element. Aborting process." << std::endl;
			abort();
		}
	};
	static void check_pop(size_t top) {
		if(top == 0) {
			std::cerr << "The stack is empty - unable to pop an element. Aborting process." << std::endl;
			abort();
		}
	};
	static void check_top(size_t top) {
		if(top == 0) {
			std::cerr << "The stack is empty - there are no elements on top. Aborting process." << std::endl;
			abort();
		}
	};
};


template<class T = int, size_t N = 100, class Checking_policy = No_checking_policy>
class Stack {
private:
	T _rep[N];
	size_t _top;
public:
	Stack():_top(0) {};
	void push(const T &val) {
		Checking_policy::check_push(_top, N);
		_rep[_top++]=val;
	}
	void pop() {
		Checking_policy::check_pop(_top);
		--_top;
  }
	const T& top()  const   {
		Checking_policy::check_top(_top);
		return _rep[top-1];
	}
	bool is_empty()         {
		return !_top;
	}
};

int main() {
	std::cout << "\tTestowanie stosu implementującego no checking policy - próba usunięcia elementu z pustego stosu." << std::endl;
	Stack<int, 100, No_checking_policy> stos;
	stos.pop();

	std::cout << "\tTestowanie stosu implementującego no checking policy - próba usunięcia elementu z pustego stosu." << std::endl;
	Stack<int, 100, Abort_on_error_policy> stos2;
	stos2.pop();
}
