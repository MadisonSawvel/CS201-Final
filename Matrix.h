#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <vector>

using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(int r, int c) { rows = r, columns = c; }
	Matrix(int r, int c, string fn);
	int  getRow() const { return rows; }
	int getColumn() const { return columns; }
	int getEntry(int i, int j) const { return table.at(i).at(j); }
	void setEntry(int i, int j, int e) { table.at(i).at(j) = e; }
	void print() const;
	Matrix transpose();
	Matrix scaler(int r);
	Matrix operator+(const Matrix& rhs);
	Matrix operator-(const Matrix& rhs);
	Matrix operator*(const Matrix& rhs);
	bool operator==(const Matrix&);
protected:
	int rows;
	int columns;
	vector<vector<int>> table;
};
#endif