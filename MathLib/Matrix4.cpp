#include "stdafx.h"
#include "Matrix4.h"


Matrix4::Matrix4()
{
	for (int i = 0; i < 4; i++) {
		for (int q = 0; q < 4; q++) {
			data[i][q] = 0;
		}
	}
}


Matrix4::~Matrix4()
{
}
Matrix4::Matrix4(const Matrix4 &m)
{
	data[0][0] = m.data[0][0];
	data[0][1] = m.data[0][1];
	data[0][2] = m.data[0][2];
	data[0][3] = m.data[0][3];

	data[1][0] = m.data[1][0];
	data[1][1] = m.data[1][1];
	data[1][2] = m.data[1][2];
	data[1][3] = m.data[1][3];

	data[2][0] = m.data[2][0];
	data[2][1] = m.data[2][1];
	data[2][2] = m.data[2][2];
	data[2][3] = m.data[2][3];


	data[3][0] = m.data[3][0];
	data[3][1] = m.data[3][1];
	data[3][2] = m.data[3][2];
	data[3][3] = m.data[3][3];

}
Vector4& Matrix4::operator[](int i)
{
	if (i == 0) {
		return r1;
	}
	else if (i == 1) {
		return r2;
	}
	else if (i == 2) {
		return r3;
	}
	else if (i == 3) {
		return r4;
	}
}

Vector4 Matrix4::operator*(Vector4 v)
{
	Vector4 result(0, 0, 0, 0);
	result[0] = (data[0][0] * v[0]) + (data[1][0] * v[1]) + (data[2][0] * v[2]) + (data[3][0] * v[3]);
	result[1] = (data[0][1] * v[0]) + (data[1][1] * v[1]) + (data[2][1] * v[2]) + (data[3][1] * v[3]);
	result[2] = (data[0][2] * v[0]) + (data[1][2] * v[1]) + (data[2][2] * v[2]) + (data[3][2] * v[3]);
	result[3] = (data[0][3] * v[0]) + (data[1][3] * v[1]) + (data[2][3] * v[2]) + (data[3][3] * v[3]);
	return result;
}

Matrix4::operator float*()
{

	return &data[0][0];
}

Matrix4::operator const float*()
{
	return &data[0][0];
}

void Matrix4::setRotateX(float f)
{
	r1[0] = 1;
	r1[1] = 0;
	r1[2] = 0;
	r1[3] = 0;

	r2[0] = 0;
	r2[1] = cos(f);
	r2[2] = sin(f);
	r2[3] = 0;

	r3[0] = 0;
	r3[1] = -sin(f);
	r3[2] = cos(f);
	r3[3] = 0;

	r4[0] = 0;
	r4[1] = 0;
	r4[2] = 0;
	r4[3] = 1;

}

void Matrix4::setRotateY(float f)
{
	r1[0] = cos(f);
	r1[1] = 0;
	r1[2] = -sin(f);
	r1[3] = 0;

	r2[0] = 0;
	r2[1] = 1;
	r2[2] = 0;
	r2[3] = 0;

	r3[0] = sin(f);
	r3[1] = 0;
	r3[2] = cos(f);
	r3[3] = 0;


	r4[0] = 0;
	r4[1] = 0;
	r4[2] = 0;
	r4[3] = 1;


}

void Matrix4::setRotateZ(float f)
{

	r1[0] = cos(f);
	r1[1] = sin(f);
	r1[2] = 0;
	r1[3] = 0;

	r2[0] = -sin(f);
	r2[1] = cos(f);
	r2[2] = 0;
	r2[3] = 0;

	r3[0] = 0;
	r3[1] = 0;
	r3[2] = 1;
	r3[3] = 0;

	r4[0] = 0;
	r4[1] = 0;
	r4[2] = 0;
	r4[3] = 1;

}
Matrix4 Matrix4::operator*(Matrix4 m)
{
	Matrix4 result;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			for (int inner = 0; inner < 4; inner++) {
				result[row][col] += m.data[row][inner] * data[inner][col];
			}
		}
	}
	
	
	return result;
}

Matrix4 Matrix4::operator=(const Matrix4 & m)
{
	data[0][0] = m.data[0][0];
	data[0][1] = m.data[0][1];
	data[0][2] = m.data[0][2];
	data[0][3] = m.data[0][3];

	data[1][0] = m.data[1][0];
	data[1][1] = m.data[1][1];
	data[1][2] = m.data[1][2];
	data[1][3] = m.data[1][3];

	data[2][0] = m.data[2][0];
	data[2][1] = m.data[2][1];
	data[2][2] = m.data[2][2];
	data[2][3] = m.data[2][3];

	data[3][0] = m.data[3][0];
	data[3][1] = m.data[3][1];
	data[3][2] = m.data[3][2];
	data[3][3] = m.data[3][3];

	return *this;
}

