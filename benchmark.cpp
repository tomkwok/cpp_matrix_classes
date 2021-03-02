#include <vector>
#include <iostream>
#include <chrono>
#include <ratio>
#include <random>
#include <algorithm>

#include "CPPMatrix.hpp"
#include "ETMatrix.hpp"

template <typename T>
void benchmark() {
	std::vector<std::size_t> sizes = {10, 20, 40, 80, 160, 320, 640, 1280, 2560, 5120};

	std::uniform_real_distribution<double> dist(-1000, 1000);

	for (auto size: sizes) {
		std::cout << size << " ";

		std::vector<std::vector<double> > vv(size);
		std::generate(vv.begin(), vv.end(), [&size, &dist]() mutable {
			std::vector<double> v(size);
			std::generate(v.begin(), v.end(), [&dist]() mutable {
				auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
				std::mt19937 engine(seed);
				return dist(engine);
			});
			return v;
		});

		auto start = std::chrono::steady_clock::now();

		T m(vv);
		T msum;
		msum = m + (m + m) + (m + m + m) + (m + m + m + m) + (m + m + m + m + m)
			+ (m + m + m + m + m + m) + (m + m + m + m + m + m + m);

		auto end = std::chrono::steady_clock::now();

		double elapsed = std::chrono::duration<double, std::milli>(end - start).count();
		std::cout << elapsed << "ms" << std::endl;
	}
}

int main() {
	std::cout << "CPPMatrix" << std::endl;
	benchmark<CPPMatrix>();
	std::cout << "ETMatrix" << std::endl;
	benchmark<ETMatrix>();
}
