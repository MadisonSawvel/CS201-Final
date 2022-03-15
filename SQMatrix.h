#ifndef SQMATRIX_H
#define SQMATRIX_H
#include "Matrix.h"

class SQMatrix :public Matrix{
public:
	SQMatrix(int n);
	SQMatrix(int n, string fn);
	int trace();
	//optional: function computes the determinant of th square matrix
	//optional: function computes the inverse of a matrix, if invertible
};


#endif
