#include <iostream>
#include <vector>
#include <algorithm>

//wzorzec obserwator pozwala wielu obiektom różnych klas
//śledzić zmiany w danym obserwowanym obiekcie
//publisher ma listę swoich subskrybentów
//i może w odpowiednim momencie wywołać we wszystkich z nich konkretną metodę

template<class T>
class Publisher {
	std::vector<T> subscribers;
public:
void addSubscriber(T obiekt) {
	subscribers.push_back(obiekt);
}

void notify() {
	std::cout << "I'm the Publisher and I'm sending messages to my subscribers!" << std::endl;
	for (T element : subscribers) {
		element.update("Update! Now everything's fine!");
	}
}
};

class A {
public:
	std::string name;
	A(std::string n) : name(n) {}

	void update(std::string message) {
		std::cout << "I am the subscriber named " << name << " and I've got some update: " << message << std::endl;
	}
};

int main() {
	Publisher<A> v;
	A maciej("Maciej");
	A waldek("Waldek");

	v.addSubscriber(maciej);
	v.addSubscriber(waldek);

	v.notify();
}
