#pragma once

#include <vector>
#include "Transform.h"
#include "Ray.h"
#include "Material.h"


class Ray;

class Model
{
protected:
	Transform transform;

	std::vector<float> vertices; // in pairs of 3, x y z
	std::vector<int> triangles;	//index of vertices

public:
	virtual ~Model()
	{
	}
	Material material;

	virtual Hit Intersect(Ray* ray);
	Model(Vector3 color, Vector3 position);
};

