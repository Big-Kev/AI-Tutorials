#pragma once
#include "Vector.h"
#include <math.h>
typedef float flaot;

class Vector2
{

public:
	Vector2();
	Vector2(float a, float b);
	~Vector2();
	//int size = 2;

	union
	{
		float data[2];
		struct
		{
			float x, y;
		};
	};

	Vector2 operator+(Vector2 rhs);
	Vector2 operator-(Vector2 rhs);
	float& operator[](int i);
	Vector2 operator* (float f);
	void normalise();
	float magnitude();
	float dot(Vector2 other);
	operator float*();
	operator const float*();
	float quicksum(Vector2 other);
	void shortenLength(float reductionLength);
	float pythag(Vector2 rhs);
private:


};

Vector2 operator*(float f, Vector2 v);