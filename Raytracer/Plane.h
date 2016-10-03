#pragma once
#include "Model.h"
class Plane : public Model
{
private:
	Vector3 normal;
	float distance;

public:
	Plane();
	Plane(Vector3 normal, Vector3 color, float distance);
	virtual Hit Intersect(Ray* ray) override;
};

