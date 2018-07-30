#pragma once
#include <math.h>
class Vector4



{
public:

	Vector4();
	Vector4(float a, float b, float c, float d);
	~Vector4();


	union
	{
		float data[4];
		
	};

	Vector4 operator+(Vector4 rhs);
	Vector4 operator-(Vector4 rhs);
	float& operator[](int i);
	Vector4 operator* (float f);
	void normalise();
	float magnitude();
	float dot(Vector4 other);
	Vector4 cross(Vector4 other);
	operator float*();
	operator const float*();
private:


};

Vector4 operator*(float f, Vector4 v);
