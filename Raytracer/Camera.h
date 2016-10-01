#pragma once

#include "Transform.h"

class Camera
{
private:
	Transform transform;
public:
	Camera();
	Vector3 GetOrigin() const;
	Matrix3 GetOrientation() const;
	void SetPosition(Vector3 position) const;
	void LookAt(Vector3 point) const;
};

