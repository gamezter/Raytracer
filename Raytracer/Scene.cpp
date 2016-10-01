#include "Scene.h"
#include "Light.h"


Scene::Scene(FIBITMAP* bitmap) 
{
	Scene::bitmap = bitmap;
	camera = new Camera();
}

void Scene::AddModel(Model* model) {
	models.push_back(model);
}

void Scene::AddLight(Light* light)
{
	lights.push_back(light);
	int size = lights.size();
	Vector3 total;
	for(int i = 0; i < size; i++)
	{
		total = total + lights.at(i)->Color * (1.0f / size);
	}
	ambientLight = total;
}