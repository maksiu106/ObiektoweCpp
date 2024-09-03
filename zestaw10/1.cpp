#include <iostream>
#include <execution>
#include <vector>

//sequenced policy wymusza na algorytmie działanie sekwencyjne, jednowątkowe

//parallel policy - algorytm jest przetwarzany w wielu równoległych wątkach
//wewnątrz wątku wszystko jest jednak robione sekwencyjnie

//parallel unsequenced policy - algorytm jest dzielony na wiele wątków
//i w każdym z tych wątków wszystko jest również

int main() {
	std::vector<int> v1(100000, 0);

	//operacje sekwencyjne:
	std::for_each(std::execution::seq, v1.begin(), v1.end(), [](int& x) {
		//kod do wykonania na elementach
	});

	//operacje równoległe:
	std::for_each(std::execution::par, v1.begin(), v1.end(), [](int& x) {
		//kod do wykonania na elementach
	});

	//operacje równoległe niesekwencyjne:
	std::for_each(std::execution::par_unseq, v1.begin(), v1.end(), [](int& x) {
		//kod do wykonania na elementach
	});
}
