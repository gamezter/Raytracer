#include "Model.h"

bool Model::Intersect(Ray* ray, Hit* hit)
{
	return false;
}

Model::Model()
{
	material.Color = Vector3(1, 1, 1);
}


Model::Model(Vector3 color, Vector3 position)
{
	transform.SetPosition(position);
	material.Color = color;
}
