#include "Light.h"

Light::Light()
{
	Color = Vector3(1.0f, 1.0f, 1.0f);
	Specular = Vector3(1, 1, 1);
	transform.SetPosition(Vector3(0,0,0));
}

Light::Light(Vector3 color, Vector3 specular, Vector3 position)
{
	Color = color;
	Specular = specular;
	transform.SetPosition(position);
}

Vector3 Light::GetPosition() const
{
	return transform.GetPosition();
}
