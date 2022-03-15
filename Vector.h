#ifndef VECTOR_H
#define VECTOR_H
#include "Matrix.h"

class Vector : public Matrix {
protected:
	int size;

public:
	int getSize() const { return size; }
	Vector(int n);
	Vector(int n, string fn);
	int operator*(const Vector&);
};

#endif
