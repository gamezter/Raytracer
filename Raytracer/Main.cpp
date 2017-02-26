#include <FreeImage.h>
#include "Scene.h"
#include "Sphere.h"
#include "Plane.h"
#include <Windows.h>

const float WIDTH = 1200;
const float HEIGHT = 800;
const float HFOV = 60 * 3.14159265f / 180.0f;
const float VFOV = HFOV * HEIGHT / WIDTH;

Scene* scene;
FIBITMAP* bitmap;


void init()
{
	FreeImage_Initialise();
	bitmap = FreeImage_Allocate(WIDTH, HEIGHT, 24);
	
	scene = new Scene();

	scene->camera->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
	scene->camera->LookAt(Vector3(0.0f, 0.0f, 0.0f));

	scene->AddModel(new Sphere(Vector3(1.0f, 0.0f, 0.0f), 1.0f, Vector3(2, 0, 0)));
	scene->AddModel(new Sphere(Vector3(0.0f, 1.0f, 0.0f), 1.0f, Vector3()));
	scene->AddModel(new Sphere(Vector3(0.0f, 0.0f, 1.0f), 1.0f, Vector3(-2, 0, 0)));
	scene->AddModel(new Plane(Vector3(0, 1, 0), Vector3(1.0, 0, 1.0), -1));

	//scene->AddLight(new Light(Vector3(239.0f / 255.0f, 219.0f / 255.0f, 139.0f / 255.0f), Vector3(1, 1, 1), Vector3(0, 10, -10)));
	scene->AddLight(new Light(Vector3(1,1,1), Vector3(1, 1, 1), Vector3(0, 10, -10)));
}

/*int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
}*/

int main()
{
	init();

	Ray* ray = new Ray();
	ray->origin = scene->camera->GetOrigin();

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {

			float relativeX = x * 2.0f / WIDTH - 1;
			float relativeY = y * 2.0f / HEIGHT - 1;

			//if ray origin is at (0 0 0) and facing +z direction, left is +x, right is -x, up is +y, down is -y
			//relative x / y assume left to right is -1 to 1 and up to down is -1 to 1

			ray->direction = Vector3(-relativeX * tanf(HFOV / 2.0f), -relativeY * tanf(VFOV / 2.0f), 1.0f).Normalized();
			ray->direction = scene->camera->GetOrientation() * ray->direction;

			//SHOOT RAY
			auto color = scene->Shoot(ray);

			RGBQUAD FIColor;
			FIColor.rgbRed = (BYTE)round(color.x * 255);
			FIColor.rgbGreen = (BYTE)round(color.y * 255);
			FIColor.rgbBlue = (BYTE)round(color.z * 255);

			FreeImage_SetPixelColor(bitmap, x, HEIGHT - y, &FIColor); //freeimage has 0,0 at bottom left
		}
	}
	delete ray;

	FreeImage_Save(FIF_PNG, bitmap, "test.png", 0);
	FreeImage_DeInitialise();
}