#include "stdafx.h"
#include "Vector4.h"
Vector4::Vector4()
{
}
Vector4::Vector4(float a, float b, float c, float d)
{
	data[0] = a;
	data[1] = b;
	data[2] = c;
	data[3] = d;


}
Vector4::~Vector4()
{
}

Vector4 Vector4::operator+(Vector4 rhs)
{
	return Vector4(rhs.data[0] + data[0], rhs.data[1] + data[1], rhs.data[2] + data[2], rhs.data[3] + data[3]);
}
Vector4 Vector4::operator-(Vector4 rhs)
{
	return Vector4(data[0] - rhs.data[0], data[1] - rhs.data[1], data[2] - rhs.data[2], data[3] - rhs.data[3]);
}

float& Vector4::operator[](int i)
{
	switch (i) {
	case 0:
		return data[0];
		break;
	case 1:
		return data[1];
		break;
	case 2:
		return data[2];
		break;
	case 3:
		return data[3];
		break;
	}
}

Vector4 Vector4::operator*(float f)
{
	return Vector4(data[0]*f, data[1]*f, data[2]*f, data[3]*f);
}

void Vector4::normalise()
{
	float mag = magnitude();
	data[0] = data[0] / mag;
	data[1] = data[1] / mag;
	data[2] = data[2] / mag;
	data[3] = data[3] / mag;
}

float Vector4::magnitude()
{
	float magsqr = (data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]) + (data[3] * data[3]);
	float mag = sqrt(magsqr);
	return mag;
}

float Vector4::dot(Vector4 other)
{
	float result = (data[0] * other.data[0]) + (data[1] * other.data[1]) + (data[2] * other.data[2]) + (data[3] * other.data[3]);
	return result;
}

Vector4 Vector4::cross(Vector4 other)
{
	Vector4 result
	(
		(data[1] * other[2]) - (data[2] * other[1]),
		(data[2] * other[0]) - (data[0] * other[2]),
		(data[0] * other[1]) - (data[1] * other[0]),
		0
	);
	return result;
}

Vector4::operator float*()
{
	return static_cast<float*>(data);
}

Vector4::operator const float*()
{
	return static_cast<float*>(data);
}


Vector4 operator*(float f, Vector4 v)
{
	return Vector4(v[0] * f, v[1] * f, v[2] * f, v[3] * f);
}
