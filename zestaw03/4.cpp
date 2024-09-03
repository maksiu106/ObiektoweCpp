#include <iostream>
#include <vector>

//szablon podstawowy
template<class T, int N = 100, class R = T*> class Stack {
	T data[100];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący szablon podstawowy" << std::endl;}
	T top() {return data[position];}
	void push(T x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

//specjalizacja oparta na tablicy - s_default
template<class T, int N> class Stack<T, N> {
	T data[N];
	int position = -1;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący pierwszą specjalizację" << std::endl;}
	T top() {return data[position];}
	void push(T x) {data[++position] = x;}
	void pop() {--position;}
	bool empty() {return (position == -1);}
};

//specjalizacja oparta na wektorze - s_container
template<class T, int N, template<class U> class Sequence> class Stack<T, N, Sequence<T> > {
	Sequence<T> data;
public:
	Stack() {std::cout << "Stworzono obiekt realizujący drugą specjalizację" << std::endl;}
	int top() {return data.back();}
	void push(int x) {data.push_back(x);}
	void pop() {data.pop_back();}
	bool empty() {return data.empty();}
};


int main() {
	Stack<int, 100> s_default;
	Stack<int, 0, std::vector<int> > s_container;
}
