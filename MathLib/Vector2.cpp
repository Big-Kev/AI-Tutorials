#include "stdafx.h"
#include "Vector2.h"
Vector2::Vector2()
{
	data[0] = 0;
	data[1] = 0;
}
Vector2::Vector2(float a, float b)
{
	data[0] = a;
	data[1] = b;
}
Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(Vector2 rhs)
{
	return Vector2(rhs.data[0] + data[0], rhs.data[1] + data[1]);
}
Vector2 Vector2::operator-(Vector2 rhs)
{
	return Vector2(data[0] - rhs.data[0], data[1] - rhs.data[1]);
}

float& Vector2::operator[](int i)
{
	switch (i) {
	case 0:
		return data[0];
		break;
	case 1:
		return data[1];
		break;
	}

}

Vector2 Vector2::operator*(float f)
{
	return Vector2(data[0] * f, data[1] * f);
}

void Vector2::normalise()
{
	float mag = magnitude();
	data[0] = data[0] / mag;
	data[1] = data[1] / mag;
}

float Vector2::magnitude()
{
	//if (data[0] == 0 && data[1] == 0) {
	//	return 1;
	//}
	float magsqr = (data[0] * data[0]) + (data[1] * data[1]);
	float mag = sqrt(magsqr);
	return mag;
}

float Vector2::dot(Vector2 other)
{
	float result = (data[0] * other.data[0]) + (data[1] * other.data[1]);
	return result;
}

Vector2::operator float*()
{
	//return static_cast<float*>(data);
	return &data[0];
}

Vector2::operator const float*()
{
	return &data[0];
}

Vector2 operator*(float f, Vector2 v)
{
	return Vector2(v[0] * f, v[1] * f);
}

float Vector2::quicksum(Vector2 other)
{
	float result = 0;

	return result;
}

void Vector2::shortenLength(float reductionLength)
{
	float t = magnitude();
	if (reductionLength > t) {
		data[0] = 0;
		data[1] = 0;
	}
	else {
		data[0] *= (1 - reductionLength / t);
		data[1] *= (1 - reductionLength / t);
	}
}