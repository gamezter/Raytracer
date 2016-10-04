#pragma once


#include <vector>
#include "Camera.h"
#include "Light.h"

class Ray;
class Model;
class Scene
{
private:
	std::vector<Model*> models;
	std::vector<Light*> lights;

	float HFOV = 60 * 3.14159265f / 180.0f;

public:
	Scene();
	Vector3 ambientLight;
	Camera* camera;
	void AddModel(Model* model);
	void AddLight(Light* light);
	Vector3 Shoot(Ray* ray);
	std::vector<Model*>* GetModels() { return &models; }
	std::vector<Light*>* GetLights() { return &lights; }
};