#include "Model.h"

Hit Model::Intersect(Ray* ray)
{
	Hit hit;
	hit.valid = false;
	return hit;
}

/*bool Model::Check(Ray* ray)
{
	float t0x = (min.x - ray->origin.x) / ray->direction.x;
	float t1x = (max.x - ray->origin.x) / ray->direction.x;
	float t0y = (min.y - ray->origin.y) / ray->direction.y; 
	float t1y = (max.y - ray->origin.y) / ray->direction.y;
	float t0z = (min.z - ray->origin.z) / ray->direction.z;
	float t1z = (max.z - ray->origin.z) / ray->direction.z;
}*/


Model::Model()
{
	material.Color = Vector3(1, 1, 1);
}


Model::Model(Vector3 color, Vector3 position)
{
	transform.SetPosition(position);
	material.Color = color;
}
