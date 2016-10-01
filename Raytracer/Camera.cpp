#include "Camera.h"



Camera::Camera()
{
	transform[10] = -1.0f;
}

Vector3 Camera::GetOrigin() const
{
	return transform.GetPosition();
}

Matrix3 Camera::GetOrientation() const
{
	return transform.GetRotation();
}

void Camera::SetPosition(Vector3 position) const
{
	transform.SetPosition(position);
}

void Camera::LookAt(Vector3 point) const
{
	transform.LookAt(point);
}
