#pragma once

#include "Transform.h"

class Scene;
struct Hit
{
	float distance;
	Vector3 Color;
	Vector3 Position;
	Vector3 Normal;
};

class Ray
{
public:
	Ray();

	Vector3 origin;
	Vector3 direction;
};

