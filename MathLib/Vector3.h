#pragma once
#include <math.h>
class Vector3




{
public:
	Vector3();
	Vector3(float a, float b, float c);
	~Vector3();

	

	union
	{
		float data[3];
		float x, y, z;
	};

	Vector3 operator+(Vector3 rhs);
	Vector3 operator-(Vector3 rhs);
	float& operator[](int i);
	Vector3 operator* (float f);
	void normalise();
	float magnitude();
	
	float dot(Vector3 other);

	operator float*();

	operator const float*();

	Vector3 cross(Vector3 other);

private:


};

Vector3 operator*(float f, Vector3 v);
