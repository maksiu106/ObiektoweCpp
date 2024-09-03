#include <iostream>

//szablon podstawowy
template<class T, int N = 100> class Stack {
	T data[100];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący szablon podstawowy" << std::endl;}
	T top() {return data[position];}
	void push(T x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

//specjalizacje częsciowe:
template<class T> class Stack<T,666> {
	T data[666];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący pierwszą specjalizację częściową" << std::endl;}
	T top() {return data[position];}
	void push(T x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

template<class T, int N> class Stack<T*, N> {
	T* data[N];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący drugą specjalizację częściową" << std::endl;}
	T* top() {return data[position];}
	void push(T* x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

template<int N> class Stack<double, N> {
	double data[N];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący trzecią specjalizację częściową" << std::endl;}
	double top() {return data[position];}
	void push(double x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

template <int N> class Stack<int*, N> {
	int* data[N];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący czwartą specjalizację częściową" << std::endl;}
	int* top() {return data[position];}
	void push(int* x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

template<> class Stack<double, 666> {
	double data[666];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący piątą specjalizację częściową" << std::endl;}
	double top() {return data[position];}
	void push(double x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

template<> class Stack<double *, 44> {
	double* data[4];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący szóstą specjalizację częściową" << std::endl;}
	double* top() {return data[position];}
	void push(double* x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

int main() {
	Stack<char> s1;
	Stack<char, 666> s2;
	Stack<char*, 100> s3;
	Stack<double, 200> s4;
	Stack<int *, 500> s5;
	Stack<double, 666> s6;
	Stack<double *, 44> s7;
}
