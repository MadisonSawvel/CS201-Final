#include "Matrix.h"
#include "SQMatrix.h"
#include "Vector.h"
#include <iostream>
#include <assert.h>

int main()
{
	SQMatrix s1 = SQMatrix(4, "Matrix1.txt");
	SQMatrix s2 = SQMatrix(4, "Matrix2.txt");
	Matrix m1 = Matrix(3, 2, "Matrix6.txt");
	Matrix m2 = Matrix(2, 3, "Matrix7.txt");
	m2.print();
	s1.print();
}

////example of how to
//int main() {
//	vector<int> row(4, 0);
//	vector<vector<int>> table(3);
//	for (int i = 0; i < 3; i++) {
//		table[i] = row;
//	}
//}