#include "Sphere.h"

Sphere::Sphere(Vector3 color, float radius, Vector3 position) : Model(color, position)
{
	Sphere::radius = radius;
	material = Material(color, 4, 0.4f, 0.2f);
}

Hit Sphere::Intersect(Ray* ray) {
	Hit hit;
	hit.valid = false;
	float t0, t1;

	Vector3 OtoC = transform.GetPosition() - ray->origin;
	float tca = OtoC.Dot(ray->direction);
	if (tca < 0) return hit;

	float d2 = OtoC.Dot(OtoC) - tca * tca;
	if (d2 > radius * radius) return hit;
	float thc = sqrtf(radius * radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;

	if (t0 > t1) std::swap(t0, t1);
	if(t0 < 0)
	{
		t0 = t1;
		if (t0 < 0) return hit;
	}
	Vector3 position = ray->origin + ray->direction * t0;
	Vector3 normal = position - transform.GetPosition();

	hit.valid = true;
	hit.Color = material.Color;
	hit.Position = position;
	normal.Normalize();
	hit.Normal = normal;
	return hit;
}