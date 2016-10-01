#pragma once

#include "Transform.h"

class Scene;
struct Hit
{
	bool valid;
	Vector3 Color;
	Vector3 Position;
	Vector3 Normal;
};

class Ray
{
public:
	Ray();
	Vector3 Shoot(Scene* scene);

	Vector3 origin;
	Vector3 direction;
};

