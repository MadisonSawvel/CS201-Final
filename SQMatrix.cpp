#include "Matrix.h"
#include "SQMatrix.h"
#include <fstream>

SQMatrix::SQMatrix(int n): Matrix(n,n) {

}
SQMatrix::SQMatrix(int n, string fn) : Matrix(n,n,fn){

}
int SQMatrix::trace() {
	int total = 0;
	for (int i = 0; i < this->getRow(); i++) {
		total = total + this->getEntry(i, i);
	}
	return total;
}