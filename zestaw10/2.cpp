#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>
#include <iostream>

auto par_time(){
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<int> vec(10'000'000);
	std::iota(vec.begin(), vec.end(), 0);
	std::vector<int> output;

	std::mutex m;

	std::for_each(std::execution::par, vec.begin(), vec.end(), [&output, &m](int& elem) {
		std::lock_guard<std::mutex> lock(m);
		if (elem % 2 == 0) {
			output.push_back(elem);
		}
	});
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	return time.count();
}

auto seq_time() {
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<int> vec(10'000'000);
	std::iota(vec.begin(), vec.end(), 0);
	std::vector<int> output;

	std::mutex m;

	std::for_each(std::execution::seq, vec.begin(), vec.end(), [&output, &m](int& elem) {
		std::lock_guard<std::mutex> lock(m);
		if (elem % 2 == 0) {
			output.push_back(elem);
		}
	});
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	return time.count();
}

int main() {
	std::cout << "Czas sekwencyjnie: " << seq_time() << std::endl;
	std::cout << "Czas równolegle: " << par_time() << std::endl;
}
