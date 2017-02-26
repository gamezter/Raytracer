#pragma once
#include "Model.h"

class Sphere : public Model
{
private:
	float radius;
public:
	explicit Sphere(Vector3 color, float radius, Vector3 position);
	virtual bool Intersect(Ray* ray, Hit* hit) override;
};
