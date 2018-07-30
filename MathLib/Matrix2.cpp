#include "stdafx.h"
#include "Matrix2.h"
#include "Vector.h"
#include <iostream>
Matrix2::Matrix2()
{
	//data[0][0] = 0;
	//data[0][1] = 0;
	//data[1][0] = 0;
	//data[1][1] = 0;
}

Matrix2::Matrix2(const Matrix2 &m)
{
	data[0][0] = m.data[0][0];
	data[0][1] = m.data[0][1];
	data[1][0] = m.data[1][0];
	data[1][1] = m.data[1][1];
}

Matrix2::Matrix2(float a, float b, float c, float d)
{
	data[0][0] = a;
	data[0][1] = b;
	data[1][0] = c;
	data[1][1] = d;
}


Matrix2::~Matrix2()
{
}

Vector2& Matrix2::operator[](int i)
{
	if (i == 0) {
		return r1;
	}
	else if (i == 1) {
		return r2;
	}
}

Vector2 Matrix2::operator*(Vector2 v)
{
	Vector2 result;
	result[0] = 0;
	result[1] = 0;
	result[0] = (data[0][0] * v[0]) + (data[1][0] * v[1]);
	result[1] = (data[0][1] * v[0]) + (data[1][1] * v[1]);

	return result;
}

Matrix2 Matrix2::operator*(Matrix2 m)
{
	//Matrix2 result(0, 0, 0, 0);
	
	Matrix2 result
	(
		(data[0][0] * m.data[0][0]) + (data[1][0] * m.data[0][1]),
		(data[0][0] * m.data[0][1]) + (data[0][1] * m.data[1][1]),
		(data[1][0] * m.data[0][0]) + (data[1][1] * m.data[1][0]),
		(data[1][0] * m.data[0][1]) + (data[1][1] * m.data[1][1])
	);
	
	//result[0][0] = (data[0][0] * m.data[0][0]) + (r1[1] * m.data[1][0]);
	//result[0][1] = (data[0][0] * m.data[0][1]) + (r1[1] * m.data[1][1]);
	//result[1][0] = (data[1][0] * m.data[0][0]) + (r2[1] * m.data[1][0]);
	//result[1][1] = (data[1][0] * m.data[0][0]) + (r2[1] * m.data[1][1]);
	//result[0][0] = 0;
	//result[0][1] = 0;
	//result[1][0] = 0;
	//result[1][1] = 0;

	/*
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			for (int inner = 0; inner < 2; inner++) {
				result[row][col] += data[row][inner] * m.data[inner][col];
			}


		}
	}
	*/
	//std::cout << "( " << (r1[0] * m.data[0][0]) + (r1[1] * m.data[1][0]) << ", " << result[0][1] << ", " << result[1][0] << ", " << result[1][1] << ")" << std::endl;
	return result;
}

Matrix2 Matrix2::operator=(const Matrix2 &m)
{
	Matrix2 temp;
	temp[0][0] = m.data[0][0];
	temp[0][1] = m.data[0][1];
	temp[1][0] = m.data[1][0];
	temp[1][1] = m.data[1][1];

	data[0][0] = m.data[0][0];
	data[0][1] = m.data[0][1];
	data[1][0] = m.data[1][0];
	data[1][1] = m.data[1][1];


	return temp;
}
Matrix2::operator float*()
{
	return &data[0][0];
}

Matrix2::operator const float*()
{
	return &data[0][0];
}

void Matrix2::setRotate(float f)
{
	/*
	r1[0] = cos(r1[0]);
	r1[1] = asin(r1[1]);
	r2[0] = cos(r2[0]);
	r2[1] = sin(r2[1]);
	*/
	//Matrix2 rotation(cos(f), sin(-f), cos(f), sin(f));

	//Matrix2 result = operator*(rotation);
	data[0][0] = 0;
	data[0][1] = 0;
	data[1][0] = 0;
	data[1][1] = 0;

	data[0][0] = cos(f);
	data[0][1] = sin(f);
	data[1][0] = sin(-f);
	data[1][1] = cos(-f);

	//r1[0] = cos(f);
	//r1[1] = sin(f);
	//r2[0] = cos(f);
	//r2[1] = -sin(f);
}

