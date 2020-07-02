#include <initializer_list>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>
#include <cassert>
#include <iostream>

class CPPMatrix {
private:
	std::vector<std::vector<double> > content;
	friend const CPPMatrix operator+(const CPPMatrix &m1, const CPPMatrix &m2);
public:
	CPPMatrix() {}

	template <typename T=const std::initializer_list<const std::initializer_list<double> > >
	CPPMatrix(T ls) {
		for (auto row: ls) {
			std::vector<double> content_row;
			content.reserve(ls.size());
			for (auto cell: row) {
				content_row.reserve(row.size());
				content_row.push_back(cell);
			}
			content.push_back(content_row);
		}
	}

	friend std::ostream& operator<<(std::ostream &out, const CPPMatrix &m);
};

std::ostream& operator<<(std::ostream &out, const CPPMatrix &m) {
	for (auto row: m.content) {
		for (auto cell: row) {
			out << cell << " ";
		}
		out << std::endl;
	}
	return out;
}

const std::vector<double> vsum(const std::vector<double> &v1, const std::vector<double> &v2) {
	assert(v1.size() == v2.size());
	std::vector<double> result;
	result.reserve(v1.size());
	std::transform(v1.begin(), v1.end(), v2.begin(), 
		std::back_inserter(result), std::plus<double>());
	return result;
}

const CPPMatrix operator+(const CPPMatrix &m1, const CPPMatrix &m2) {
	assert(m1.content.size() == m2.content.size());
	CPPMatrix result({});
	result.content.reserve(m1.content.size());
	std::transform(m1.content.begin(), m1.content.end(), m2.content.begin(), 
		std::back_inserter(result.content), vsum);
	return result;
}
