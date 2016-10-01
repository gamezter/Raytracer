#pragma once
#include "Transform.h"

class Material
{

public:
	float Specular;
	float Diffuse;
	float Ambient;
	Vector3 Color;
	Material();
	Material(Vector3 color, float specular, float diffuse, float ambient);
};

