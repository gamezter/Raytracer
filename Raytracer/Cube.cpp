#include "Cube.h"

Cube::Cube(Vector3 color, Vector3 position): Model(color, position)
{
	vertices = std::vector<float>(24);
	vertices = { -1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f };

	triangles = std::vector<int>(36);
	triangles = { 0, 2, 1,
		6, 1, 2,
		4, 2, 3,
		0, 3, 2,
		2, 4, 6,
		7, 6, 4,
		7, 4, 5,
		3, 5, 4,
		5, 1, 7,
		6, 7, 1,
		5, 3, 1,
		0, 1, 3 };
}


Cube::~Cube()
{
}
