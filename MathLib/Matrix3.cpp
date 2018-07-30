#include "stdafx.h"
#include "Matrix3.h"
#include <iostream>

Matrix3::Matrix3()
{
	for (int i = 0; i < 3; i++) {
		for (int q = 0; q < 3; q++) {
			data[i][q] = 0;
		}
	}
}
/*
Matrix3::Matrix3(float a, float b, float c,
				 float d, float e, float f,
				 float g, float h, float i)
{
	r1[0] = a;
	r1[1] = b;
	r1[2] = c;
	r2[0] = d;
	r2[1] = e;
	r2[2] = f;
	r3[0] = g;
	r3[1] = h;
	r3[2] = i;
}*/
Matrix3::~Matrix3()
{
}

Matrix3::Matrix3(const Matrix3 &m)
{
	data[0][0] = m.data[0][0];
	data[0][1] = m.data[0][1];
	data[0][2] = m.data[0][2];

	data[1][0] = m.data[1][0];
	data[1][1] = m.data[1][1];
	data[1][2] = m.data[1][2];

	data[2][0] = m.data[2][0];
	data[2][1] = m.data[2][1];
	data[2][2] = m.data[2][2];

}

Vector3& Matrix3::operator[](int i)
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
}
Vector3 Matrix3::operator*(Vector3 v)
{
	Vector3 result;

	/*
	for (int i = 0; i < 3; i++) {
		result[0] += (r1[i] * v[i]);
		result[1] += (r2[i] * v[i]);
		result[2] += (r3[i] * v[i]);
	}*/
	result[0] = (data[0][0] * v[0]) + (data[1][0] * v[1]) + (data[2][0] * v[2]);
	result[1] = (data[0][1] * v[0]) + (data[1][1] * v[1]) + (data[2][1] * v[2]);
	result[2] = (data[0][2] * v[0]) + (data[1][2] * v[1]) + (data[2][2] * v[2]);

	return result;
}
Matrix3 Matrix3::operator*(Matrix3 m)
{
	Matrix3 result;
	/*
	Vector3 m1(m[0][0], m[0][1], m[0][2]);
	Vector3 m2(m[1][0], m[1][1], m[1][2]);
	Vector3 m3(m[2][0], m[2][1], m[2][2]);
	*/
	/*
	Matrix3 result
	(
		(data[0][0] * m.data[0][0]) + (data[1][0] * m.data[0][1]) + (data[2][0] * m.data[0][2]),
		(data[0][0] * m.data[0][1]) + (data[0][1] * m.data[1][1]) + (data[0][2] * m.data[1][2]),
		(data[0][0] * m.data[0][2]) + (data[0][1] * m.data[1][2]) + (data[0][2] * m.data[2][2]),

		(data[1][0] * m.data[0][0]) + (data[1][1] * m.data[0][1]) + (data[1][2] * m.data[0][2]),
		(data[1][0] * m.data[0][1]) + (data[1][1] * m.data[1][1]) + (data[1][2] * m.data[1][2]),
		(data[1][0] * m.data[0][2]) + (data[1][1] * m.data[1][2]) + (data[1][2] * m.data[2][2]),

		(data[2][0] * m.data[0][0]) + (data[2][1] * m.data[0][1]) + (data[2][2] * m.data[0][2]),
		(data[0][1] * m.data[2][0]) + (data[1][1] * m.data[2][1]) + (data[2][1] * m.data[2][2]),
		(data[2][0] * m.data[0][2]) + (data[2][1] * m.data[1][2]) + (data[2][2] * m.data[2][2])
	);
	*/

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			for (int inner = 0; inner < 3; inner++) {
				result[row][col] += m.data[row][inner] * data[inner][col];
			}
		}
	}
	/*
	result[2][0] = (data[2][0] * m.data[0][0]) + (data[2][1] * m.data[1][0]) + (data[2][1] * m.data[0][2]);
	result[2][1] = (data[][1] * m.data[2][0]) + (data[1][1] * m.data[2][1]) + (data[2][1] * m.data[2][2]);
	result[2][2] = (data[2][0] * m.data[0][2]) + (data[2][1] * m.data[1][2]) + (data[2][2] * m.data[2][2]);
	\*/
	/*
	result[0][0] = r1.dot(m1);
	result[0][1] = r1.dot(m2);
	result[0][2] = r1.dot(m3);

	result[1][0] = r2.dot(m1);
	result[1][1] = r2.dot(m2);
	result[1][2] = r2.dot(m3);

	result[2][0] = r3.dot(m1);
	result[2][1] = r3.dot(m2);
	result[2][2] = r3.dot(m3);
	*/
	return result;
}
Matrix3::operator float*()
{

	return &data[0][0];
}

Matrix3::operator const float*()
{
	return &data[0][0];
}

void Matrix3::setRotateX(float f)
{
	r1[0] = 1;
	r1[1] = 0;
	r1[2] = 0;

	r2[0] = 0;
	r2[1] = cos(f);
	r2[2] = sin(f);//-


	r3[0] = 0;
	r3[1] = sin(-f);
	r3[2] = cos(f);
}

void Matrix3::setRotateY(float f)
{
	r1[0] = cos(f);
	r1[1] = 0;
	r1[2] = sin(-f);

	r2[0] = 0;
	r2[1] = 1;
	r2[2] = 0;

	r3[0] = sin(f);//-
	r3[1] = 0;
	r3[2] = cos(f);
}

void Matrix3::setRotateZ(float f)
{

	r1[0] = cos(f);
	r1[1] = sin(f);//-
	r1[2] = 0;

	r2[0] = -sin(f);
	r2[1] = cos(f);
	r2[2] = 0;

	r3[0] = 0;
	r3[1] = 0;
	r3[2] = 1;
}
Matrix3 Matrix3::operator=(const Matrix3 &m)
{
	Matrix3 temp;
	temp[0][0] = m.data[0][0];
	temp[0][1] = m.data[0][1];
	temp[0][2] = m.data[0][2];

	temp[1][0] = m.data[1][0];
	temp[1][1] = m.data[1][1];
	temp[1][2] = m.data[1][2];

	temp[2][0] = m.data[2][0];
	temp[2][1] = m.data[2][1];
	temp[2][2] = m.data[2][2];
	//a
	data[0][0] = m.data[0][0];
	data[0][1] = m.data[0][1];
	data[0][2] = m.data[0][2];

	data[1][0] = m.data[1][0];
	data[1][1] = m.data[1][1];
	data[1][2] = m.data[1][2];

	data[2][0] = m.data[2][0];
	data[2][1] = m.data[2][1];
	data[2][2] = m.data[2][2];


	return temp;
}