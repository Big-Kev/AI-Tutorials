#pragma once
#include "Vector4.h"
class Matrix4
{
public:

	union {
		struct
		{
			Vector4 r1;
			Vector4 r2;
			Vector4 r3;
			Vector4 r4;
		};
		float  data[4][4];

	};
	Matrix4();
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p) : r1(a, b, c, d), r2(e, f, g, h), r3(i, j, k, l), r4(m, n, o, p) {}
	Matrix4(const Matrix4 &m);
	~Matrix4();
	Vector4 & operator[](int i);
	Vector4 operator* (Vector4 v);

	operator float*();

	operator const float*();

	void setRotateX(float f);

	void setRotateY(float f);

	void setRotateZ(float f);

	Matrix4 operator*(Matrix4 m);
	Matrix4 operator=(const Matrix4 & m);
};

