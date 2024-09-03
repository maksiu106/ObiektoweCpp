#include <iostream>
#include <memory>

//weak_ptr nie zwiększa licznika referencji
//nie przyczynia się do utrzymania obiektu w pamięci
//unika się cykliczności (tj. np. dwa shared_ptr wskazujące na siebie
//można za jego pomocą sprawdzać, czy obiekt wciąż jest w pamięci

void doit(std::weak_ptr<int> weak) {
	std::cout << "Próbujemy się odwołać do wartości, na którą wskazuje shared_ptr za pomocą weak_ptr" << std::endl;
	if (auto pointer = weak.lock()) std::cout << "Weak_ptr wskazuje na shared_ptr przechowujący wartość " << *pointer << std::endl;
	else std::cout << "Shared_ptr, na który wskazywał weak_ptr, wygasł już" << std::endl;
}

int main() {
	std::weak_ptr<int> weak;
	do {
		std::shared_ptr<int> p = std::make_shared<int>(5);
		weak = p;
		doit(weak);
	} while (0);
	std::cout << "Wychodzimy z pętli, shared_ptr wygasa i znika" << std::endl;
	doit(weak);
}
