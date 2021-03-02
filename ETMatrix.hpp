#include <initializer_list>
#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>

class ETMatrix {
public:
	std::vector<std::vector<double> > content;
	std::tuple<std::size_t, std::size_t> shape;

	ETMatrix() = default;
	
	template <typename T=const std::initializer_list<const std::initializer_list<double> > >
	explicit ETMatrix(T ls) {
		std::size_t rows = ls.size();
		std::size_t cols;
		content.reserve(rows);
		for (auto row: ls) {
			cols = row.size(); // assume all rows of supplied matrix have the same size

			std::vector<double> content_row;
			content_row.reserve(cols);
			for (auto cell: row) {
				content_row.push_back(cell);
			}
			content.push_back(content_row);
		}
		shape = std::make_tuple(rows, cols);
	}

	template <typename EXPR>
	ETMatrix& operator=(EXPR const&expr) {
		shape = expr.shape;
		std::size_t rows;
		std::size_t cols;
		std::tie(rows, cols) = shape;
		content.reserve(rows);
		for (size_t i = 0; i < rows; i++) {
			std::vector<double> content_row;
			content_row.reserve(cols);
			for (size_t j = 0; j < cols; j++) {
				content_row.push_back(expr(i, j));
			}
			content.push_back(content_row);
		}
		return *this;
	}

	double operator()(size_t row, size_t col) const {
		return content.at(row).at(col);
	}

	friend std::ostream& operator<<(std::ostream &out, const ETMatrix &m);
};

std::ostream& operator<<(std::ostream &out, const ETMatrix &m) {
	for (const auto& row: m.content) {
		for (const auto& cell: row) {
			out << cell << " ";
		}
		out << std::endl;
	}
	return out;
}

template <typename LHS, typename RHS>
class ETMatrixAdd {
public:
	const LHS& lhs;
	const RHS& rhs;
	std::tuple<std::size_t, std::size_t> shape;

	ETMatrixAdd(LHS const&lhs, RHS const&rhs) : lhs(lhs), rhs(rhs), shape(lhs.shape) {};

	auto operator()(size_t row, size_t col) const {
		assert(lhs.shape == rhs.shape);
		return lhs(row, col) + rhs(row, col);
	}
};

template <typename LHS, typename RHS>
ETMatrixAdd<LHS, RHS> operator+(LHS const&lhs, RHS const&rhs) {
	return ETMatrixAdd<LHS, RHS>(lhs, rhs);
}
