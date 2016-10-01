#pragma once


#include <vector>
#include <FreeImage.h>
#include "Camera.h"
#include "Light.h"

class Model;
class Scene
{
private:
	std::vector<Model*> models;
	std::vector<Light*> lights;
	FIBITMAP* bitmap;

	float HFOV = 60 * 3.14159265f / 180.0f;

public:
	Scene(FIBITMAP* bitmap);
	Vector3 ambientLight;
	Camera* camera;
	void AddModel(Model* model);
	void AddLight(Light* light);
	std::vector<Model*>* GetModels() { return &models; }
	std::vector<Light*>* GetLights() { return &lights; }
};