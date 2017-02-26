#include "Scene.h"
#include "Light.h"
#include "Ray.h"
#include "Model.h"


Scene::Scene() 
{
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
		total += lights.at(i)->Color * (1.0f / size);
	}
	ambientLight = total;
}

Vector3 Scene::Shoot(Ray* ray) {
	int nModels = models.size();
	int nLights = lights.size();

	float z = INFINITY;
	Vector3 illumination;

	for (int i = 0; i < nModels; i++) {

		Model* model = models.at(i);
		Hit hit;
		if (model->Intersect(ray, &hit)) {

			if (hit.distance >= z) continue;
			z = hit.distance;

			illumination = model->material.Color * ambientLight * model->material.Ambient;

			for (int j = 0; j < nLights; j++)
			{
				Light* light = lights.at(j);

				Vector3 shadow = (light->GetPosition() - hit.Position).Normalized();

				Vector3 reflection = (hit.Normal * shadow.Dot(hit.Normal) * 2 - shadow).Normalized();

				float diffuse = shadow.Dot(hit.Normal);
				if (diffuse < 0) diffuse = 0;
				diffuse = diffuse * model->material.Diffuse;

				float specular = reflection.Dot(ray->direction * -1);
				if (specular < 0) specular = 0;
				specular = pow(specular, 50) * model->material.Specular;

				illumination += light->Color * diffuse + light->Specular * specular;
			}
		}

		if (illumination.x > 1) illumination.x = 1;
		if (illumination.y > 1) illumination.y = 1;
		if (illumination.z > 1) illumination.z = 1;

	}
	return illumination;
}