#include <iostream>
#include "CPPMatrix.hpp"
#include "ETMatrix.hpp"

template <typename T>
void print() {
	T m1({
		{1.23f, 2.23f, 3.23f, 4.23f},
		{2.23f, 3.23f, 4.23f, 5.23f},
		{7.23f, 1.23f, 2.23f, 3.23f},
	});
	T m2({
		{1.27f, 1.27f, 1.27f, 1.27f},
		{2.27f, 3.27f, 4.27f, 5.27f},
		{-.23f, -.23f, -.23f, -.23f},
	});
	T m3({
		{.1f, .2f, .1f, .2f},
		{.1f, .1f, .1f, .1f},
		{.1f, .1f, .1f, .1f},
	});
	std::cout << m1 << std::endl;
	std::cout << m2 << std::endl;
	std::cout << m3 << std::endl;
	T m4;
	m4 = m1 + m2 + m3;
	std::cout << m4 << std::endl;
}

int main() {
	std::cout << "CPPMatrix" << std::endl;
	print<CPPMatrix>();
	std::cout << "ETMatrix" << std::endl;
	print<ETMatrix>();
}
