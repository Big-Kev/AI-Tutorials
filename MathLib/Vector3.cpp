#include "stdafx.h"
#include "Vector3.h"


Vector3::Vector3()
{
}
Vector3::Vector3(float a, float b, float c)
{
	data[0] = a;
	data[1] = b;
	data[2] = c;
}
Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(Vector3 rhs)
{
	return Vector3(rhs.data[0] + data[0], rhs.data[1] + data[1], rhs.data[2] + data[2]);
}
Vector3 Vector3::operator-(Vector3 rhs)
{
	return Vector3(data[0] - rhs.data[0], data[1]- rhs.data[1], data[2]- rhs.data[2]);
}

float& Vector3::operator[](int i)
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
	}
}

Vector3 Vector3::operator*(float f)
{
	return Vector3(data[0]*f, data[1]*f, data[2]*f);
}

void Vector3::normalise()
{
	float mag = magnitude();
	data[0] = data[0] / mag;
	data[1] = data[1] / mag;
	data[2] = data[2] / mag;
}

float Vector3::magnitude()
{
	float magsqr = (data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]);
	float mag = sqrt(magsqr);
	return mag;
}

float Vector3::dot(Vector3 other)
{
	float result = (data[0] * other.data[0]) + (data[1] * other.data[1]) + (data[2] * other.data[2]);
	return result;
}

Vector3::operator float*()
{
	
	return static_cast<float*>(data);
}

Vector3::operator const float*()
{
	return static_cast<float*>(data);
}

Vector3 Vector3::cross(Vector3 other)
{
	Vector3 result
	(
		(data[1] * other[2]) - (data[2] * other[1]),
		(data[2] * other[0]) - (data[0] * other[2]),
		(data[0] * other[1]) - (data[1] * other[0])
	);
	return result;
}

Vector3 operator*(float f, Vector3 v)
{
	return Vector3(v[0] * f, v[1] * f, v[2] * f);
}
