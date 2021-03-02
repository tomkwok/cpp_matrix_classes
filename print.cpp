#include <iostream>
#include "CPPMatrix.hpp"
#include "ETMatrix.hpp"

template <typename T>
void print() {
	T m1({
		{1.23F, 2.23F, 3.23F, 4.23F},
		{2.23F, 3.23F, 4.23F, 5.23F},
		{7.23F, 1.23F, 2.23F, 3.23F},
	});
	T m2({
		{1.27F, 1.27F, 1.27F, 1.27F},
		{2.27F, 3.27F, 4.27F, 5.27F},
		{-.23F, -.23F, -.23F, -.23F},
	});
	T m3({
		{.1F, .2F, .1F, .2F},
		{.1F, .1F, .1F, .1F},
		{.1F, .1F, .1F, .1F},
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
