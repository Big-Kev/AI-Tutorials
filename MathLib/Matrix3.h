#pragma once
#include "Vector3.h"
class Matrix3
{
public:

	int size = 3;

	union {
		struct {
			Vector3 r1;
			Vector3 r2;
			Vector3 r3;
		};
		float data[3][3];
	};
	Matrix3();
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i) : r1(a, b, c), r2(d, e, f), r3(g, h, i) {}
	~Matrix3();
	Matrix3(const Matrix3 & m);
	Vector3& operator[](int i);


	Vector3 operator* (Vector3 v);
	Matrix3 operator* (Matrix3 m);

	operator float*();
	operator const float*();

	void setRotateX(float f);
	void setRotateY(float f);
	void setRotateZ(float f);

	Matrix3 operator=(const Matrix3 & m);

};

