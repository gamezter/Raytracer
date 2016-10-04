#include "Ray.h"
#include "Model.h"
#include "Light.h"
#include "Scene.h"

Ray::Ray() 
{
	origin = Vector3();
	direction = Vector3();
}