#include "Ray.h"
#include "Model.h"
#include "Light.h"
#include "Scene.h"

Ray::Ray() 
{
	origin = Vector3();
	direction = Vector3();
}

Vector3 Ray::Shoot(Scene* scene) {
	std::vector<Model*>* models = scene->GetModels();
	std::vector<Light*>* lights = scene->GetLights();
	int nModels = models->size();
	int nLights = lights->size();

	float z = 100000;
	Vector3 illumination;

	for (int i = 0; i < nModels; i++) {

		Model* model = models->at(i);
		Hit hit = model->Intersect(this);
		if (hit.valid) {

			if (hit.distance >= z)
			{
				continue;
			}

			z = hit.distance;

			illumination = model->material.Color * scene->ambientLight * model->material.Ambient;

			for(int j = 0; j < nLights; j++)
			{
				Light* light = lights->at(j);

				Vector3 shadow = light->GetPosition() - hit.Position;
				shadow.Normalize();

				Vector3 reflection = (hit.Normal * shadow.Dot(hit.Normal) * 2) - shadow;
				reflection.Normalize();

				float diffuse = shadow.Dot(hit.Normal);
				if (diffuse < 0) diffuse = 0;
				diffuse = diffuse * model->material.Diffuse;

				float specular = reflection.Dot(direction * -1);
				if (specular < 0) specular = 0;
				specular = pow(specular, 50) * model->material.Specular;

				illumination = illumination + light->Color * diffuse + light->Specular * specular;
			}
		}

		if (illumination.x > 1) illumination.x = 1;
		if (illumination.y > 1) illumination.y = 1;
		if (illumination.z > 1) illumination.z = 1;
		
	}
	return illumination;
}