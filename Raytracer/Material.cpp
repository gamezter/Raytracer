#include "Material.h"


Material::Material()
{
	Color = Vector3();
	Specular = 1;
	Diffuse = 1;
	Ambient = 1;
}


Material::Material(Vector3 color, float specular, float diffuse, float ambient)
{
	Color = color;
	Specular = specular;
	Diffuse = diffuse;
	Ambient = ambient;
}
