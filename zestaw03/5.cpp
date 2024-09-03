#include <iostream>
#include <set>

int main() {
	std::set<int, std::greater<int> > pojemnik;
	//nadpisany domyślny funktor sortujący
	pojemnik.insert(2);
	pojemnik.insert(100);
	pojemnik.insert(50);
	for (int i : pojemnik) {
		std::cout << i << std::endl;
	}
}
