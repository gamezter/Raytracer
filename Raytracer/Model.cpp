#include "Model.h"

Hit Model::Intersect(Ray* ray)
{
	Hit hit;
	hit.valid = false;
	return hit;
}

Model::Model(Vector3 color, Vector3 position)
{
	transform.SetPosition(position);
	material.Color = color;
}
