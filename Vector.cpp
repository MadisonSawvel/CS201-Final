#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <fstream>

Vector::Vector(int n){
	size = n;
	for (int i = 0; i < size; i++) {
			this->setEntry(1, i, 0);
		}
}
Vector::Vector(int n, string fn) {
	size = n;
	ifstream file;
	file.open(fn);
	for (int i = 0; i < size; i++) {
		file >> columns;
		this->setEntry(1, i, columns);
	}
	file.close();
}
int Vector::operator*(const Vector& rhs) {
	int total = 0;
	if (this->getSize() == rhs.size) {
		for (int i = 0; i < size; i++) {
			total += this->getEntry(0, i) * rhs.getEntry(0, i);
		}
		return total;
	}
	else {
		cout << "Error" << endl;
	}
	
}
