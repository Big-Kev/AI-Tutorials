#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(const Matrix2 &m);
	Matrix2(float a, float b, float c, float d);// : r1(a, b), r2(c, d) {}
	~Matrix2();
	
	union {
		struct {
		Vector2  r1;
		Vector2 r2;
		};

		float data[2][2];
	};
	operator float*();
	operator const float*();
	void setRotate(float f);
	Vector2& operator[](int i);
	Vector2 operator* (Vector2 v);
	Matrix2 operator* (Matrix2 m);
	Matrix2 operator=(const Matrix2 &m);
	
};

