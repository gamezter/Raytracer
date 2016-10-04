#pragma once
#include <cmath>

struct Vector3 {
	float x, y, z;

	Vector3() { x = 0.0f; y = 0.0f; z = 0.0f; }
	Vector3(float x, float y, float z) { Vector3::x = x; Vector3::y = y; Vector3::z = z; }
	void Normalize();
	float Magnitude() const;
	float Dot(Vector3 vec) const;
	Vector3 Cross(Vector3 vec) const;
	Vector3 operator-(Vector3 vec) const;
	Vector3 operator-() const;
	Vector3 operator+(Vector3 vec) const;
	Vector3 operator*(float val) const;
	Vector3 operator*(Vector3 vec) const;
};

struct Matrix3 {
	float mat[9];

	Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
	Vector3 operator*(Vector3 vec);
};

class Transform
{
private:
	float* mat;

public:
	Transform();
	float operator[](int i) const { return mat[i]; }
	float& operator[](int i) { return mat[i]; }
	Vector3 GetPosition() const;
	Matrix3 GetRotation() const;
	void SetPosition(Vector3 position) const;
	void LookAt(Vector3 point) const;
};



