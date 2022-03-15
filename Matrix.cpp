#include "Matrix.h"
#include <fstream>
#include <iostream>


Matrix::Matrix(int r, int c, string fn) {
	rows = r;
	columns = c;
	ifstream file;
	file.open(fn);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			file >> table.at(i).at(j);
		}
	}
	file.close();
}
void Matrix::print() const {
	for (int i = 0; i < rows; i++) {
		cout << "|";
		for (int j = 0; j < columns; j++) {
			cout.width(6);
			cout << table.at(i).at(j) << " ";
		}
		cout << "|" << endl;
	}
}
Matrix Matrix::transpose() {
	int tRows = columns;
	int tColumns = rows;
	Matrix tMatrix(tRows, tColumns);
	return tMatrix;
}

Matrix Matrix::scaler(int r) {
	int sRows = rows;
	int sColumns = columns;
	Matrix sMatrix(sRows, sColumns);
	for (int i = 0; i < sRows; i++) {
		for (int j = 0; j < sColumns; j++) {
			table.at(i).at(j) = table.at(i).at(j) * r;
		}
	}
	return sMatrix; 
}

Matrix Matrix::operator+(const Matrix& rhs) {
	Matrix sum(rows, columns);
	if (rhs.getColumn() == this->getColumn() && rhs.getRow() == this->getRow()) {
		for (int i = 0; i < this->getRow(); i++) {
			for (int j = 0; j < this->getRow(); j++) {
				int added = this->table.at(i).at(j) + rhs.table.at(i).at(j);
				sum.setEntry(j, i, added);
			}
		}
	}
	return sum;
}

Matrix Matrix::operator-(const Matrix& rhs) {
	Matrix difference(rows, columns);
	if (rhs.getColumn() == this->getColumn() && rhs.getRow() == this->getRow()) {
		for (int i = 0; i < this->getRow(); i++) {
			for (int j = 0; j < this->getRow(); j++) {
				int subtracted = this->table.at(i).at(j) - rhs.table.at(i).at(j);
				difference.setEntry(j, i, subtracted);
			}
		}
	}
	return difference;
}

Matrix Matrix::operator*(const Matrix& rhs) {
	Matrix multiply(this->getRow(), rhs.getColumn());
	int multSum = 0;
	for (int i = 0; i < this->getRow(); i++) {
		for (int j = 0; j < rhs.getColumn(); j++) {
			for (int k = 0; k < this->getColumn(); k++) {
				multSum += this->getEntry(i, k) * rhs.getEntry(k, j);
			}
			multiply.setEntry(i, j, (multSum));
		}
	}
	return multiply;
}

bool Matrix::operator==(const Matrix& rhs) {
	if (rhs.getColumn() == this->getColumn() && rhs.getRow() == this->getRow()) {
		for (int i = 0; i < this->getRow(); i++) {
			for (int j = 0; j < this->getRow(); j++) {
				if (this->table.at(i).at(j) != rhs.table.at(i).at(j)) {
					return false;
				}
			}
		}
	}
	else {
		return false;
	}
	return true;
}