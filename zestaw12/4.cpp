#include <iostream>
#include <algorithm>

//Adapter jest wzorcem używanym wtedy, kiedy mają komunikować się ze sobą
//Dwa obiekty o całkowicie niekompatybilnych interfejsach
//A jednocześnie nie opłaca się zmieniać interfejsu jednego z nich
//Adapter wóœczas będzie konwertował wyjście jednego na kompatybilne
//Z wejściem drugiego i vice versa

struct JapaneseWriter {
public:
	std::string writeSth() {
		return "sdrawkcab etirw I ,retirw esenapaj ma I";
	}
};

class EuropeanReader {
protected:
	JapaneseWriter* writer;
public:
	EuropeanReader(JapaneseWriter* w) : writer(w) {}

	virtual void read() {
		std::cout << "I am the reader and I'm trying to read sth: " << writer->writeSth() << std::endl;
	}
};

class Adapter : public EuropeanReader {
public:
	Adapter(JapaneseWriter* w) : EuropeanReader(w) {}

	void read() override {
		std::string toAdapt = writer->writeSth();
		std::reverse(toAdapt.begin(), toAdapt.end());
		std::cout << "I am the adapter. Now it looks like that: " << toAdapt << std::endl;
	}
};

int main() {
	JapaneseWriter jw;
	EuropeanReader er(&jw);
	Adapter ad(&jw);

	er.read();
	ad.read();
}
