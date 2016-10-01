#include "Transform.h"

Transform::Transform()
{
	mat = new float[16];

	for (int i = 0; i < 16; i++) {
		mat[i] = 0.0f;
	}
	mat[0] = mat[5] = mat[10] = mat[15] = 1.0f;
}

Vector3 Transform::GetPosition() const
{
	return Vector3(mat[3], mat[7], mat[11]);
}

void Transform::SetPosition(Vector3 position) const
{
	mat[3] = position.x;
	mat[7] = position.y;
	mat[11] = position.z;
}

void Transform::LookAt(Vector3 point) const
{
	Vector3 forward = point - GetPosition(); // Z
	forward.Normalize();
	Vector3 up = Vector3(0.0f, 1.0f, 0.0f); // Y
	Vector3 left = up.Cross(forward); // X
	left.Normalize();
	up = forward.Cross(left);
	up.Normalize();

	mat[0] = left.x; mat[1] = up.x; mat[2] = forward.x;
	mat[4] = left.y; mat[5] = up.y; mat[6] = forward.y;
	mat[8] = left.z; mat[9] = up.z; mat[10] = forward.z;
}

Matrix3 Transform::GetRotation() const
{
	return Matrix3(mat[0], mat[1], mat[2], mat[4], mat[5], mat[6], mat[8], mat[9], mat[10]);
}

void Vector3::Normalize() {
	float mag = sqrt(x * x + y * y + z * z);
	x /= mag;
	y /= mag;
	z /= mag;
}

Matrix3::Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8) {
	mat[0] = m0; mat[1] = m1; mat[2] = m2; mat[3] = m3; mat[4] = m4; mat[5] = m5; mat[6] = m6; mat[7] = m7; mat[8] = m8;
}

Vector3 Matrix3::operator*(Vector3 vec) {
	return Vector3( vec.x * mat[0] + vec.y * mat[1] + vec.z * mat[2],
					vec.x * mat[3] + vec.y * mat[4] + vec.z * mat[5],
					vec.x * mat[6] + vec.y * mat[7] + vec.z * mat[8] );
}
Vector3 Vector3::operator-(Vector3 vec) const
{
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator+(Vector3 vec) const
{
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

Vector3 Vector3::operator*(float val) const 
{
	return Vector3(x * val, y * val, z * val);
}

Vector3 Vector3::operator*(Vector3 vec) const
{
	return Vector3(x * vec.x, y * vec.y, z * vec.z);
}


float Vector3::Dot(Vector3 vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

Vector3 Vector3::Cross(Vector3 vec) const
{
	return Vector3(y*vec.z - z*vec.y, z*vec.x - x*vec.z, x*vec.y - y*vec.x);
}
