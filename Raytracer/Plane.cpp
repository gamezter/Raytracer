#include "Plane.h"



Plane::Plane() : Model()
{
	normal = Vector3(0, 1, 0);
	distance = 0;
}

Plane::Plane(Vector3 normal, Vector3 color, float distance)
{
	normal.Normalize();
	Plane::normal = normal;
	Plane::distance = distance;
	material = Material(color, 4, 0.4f, 0.2f);
}

bool Plane::Intersect(Ray* ray, Hit* hit)
{
	float t;
	Vector3 p = normal * distance;

	float denominator = ray->direction.Dot(normal);
	
	Vector3 lineToPlane = p - ray->origin;
	t = normal.Dot(lineToPlane) / denominator;

	if(t < 0) return false;

	hit->Color = material.Color;
	hit->Normal = normal;
	hit->distance = t;
	hit->Position = ray->origin + ray->direction * t;
	return true;
}

