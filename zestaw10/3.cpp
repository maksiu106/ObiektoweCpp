#include <execution>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <unistd.h>

void parallel_sort(std::vector<int> &v) {
	std::min_element(std::execution::par, v.begin(), v.end());
}

void seq_sort(std::vector<int> &v) {
	std::min_element(std::execution::seq, v.begin(), v.end());
}

int main() {
	srand(0);
	std::vector<int> v1(1000);
	for (int &x : v1) {
		x = random();
	}

	auto start = std::chrono::high_resolution_clock::now();
	std::for_each(std::execution::seq, v1.begin(), v1.end(), [](int& x) {usleep(500);});
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> seq_time = end - start;

	start = std::chrono::high_resolution_clock::now();
	std::for_each(std::execution::par, v1.begin(), v1.end(), [](int& x) {usleep(500);});
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> par_time = end - start;

	std::cout << "Równolegle: " << par_time.count() << "\nSekwencyjnie: " << seq_time.count() << std::endl;
}
