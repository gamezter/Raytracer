#pragma once
#include "Transform.h"

class Light
{
public:
	Transform transform;
	Vector3 Color;
	Vector3 Specular;

	Light();
	Light(Vector3 color, Vector3 specular, Vector3 position);

	Vector3 GetPosition() const;
};

