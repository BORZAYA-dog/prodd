#include <iostream>
#include <iomanip>
#include <chrono>


int main() {
	const int n = 10000;
	static int massive[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			massive[i][j] = i+j;
		}
	}
	int sum = 0;
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum += massive[i][j];
		}
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << diff.count() << " s" << std::endl;

	int sum2 = 0;
	auto start2 = std::chrono::steady_clock::now();
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n; ++i) {
			sum += massive[i][j];
		}
	}
	auto end2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2;
	std::cout << diff2.count() << " s" << std::endl;
}