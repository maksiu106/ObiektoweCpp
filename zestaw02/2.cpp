#include <iostream>

class Human {
public:
	virtual void greet() = 0; //klasa czysto wirtualna
};

class NiceHuman : public Human {
public:
	void greet() override {
		std::cout << "Hello! It's very nice to meet you." << std::endl;
	}
};

class RudeHuman : public Human {
public:
	void greet() override {
		std::cout << "Leave me alone, I hate you." << std::endl;
	}
};

void meet_dynamic(Human *h) {
	h->greet();
}

template <class T>
void meet_static(T h) {
	h.greet();
}

int main() {
	//polimorfizm dynamiczny
	Human *h1 = new NiceHuman;
	Human *h2 = new RudeHuman;
	std::cout << "Zobrazowanie polimorfizmu dynamicznego: \n\tSpotkanie obiektu jednego typu: " << std::flush;
	meet_dynamic(h1);
	std::cout << "\tSpotkanie obiektu drugiego typu: " << std::flush;
	meet_dynamic(h2);
	delete h1, h2;

	//polimorfizm statyczny
	NiceHuman h3;
	RudeHuman h4;
	std::cout << "Zobrazowanie polimorfizmu statycznego: \n\tSpotkanie obiektu jednego typu: " << std::flush;
	meet_static(h3);
	std::cout << "\tSpotkanie obiektu drugiego typu: " << std::flush;
	meet_static(h4);
}
