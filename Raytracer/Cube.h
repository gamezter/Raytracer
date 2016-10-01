#pragma once
#include "Model.h"

class Cube : public Model
{
public:
	explicit Cube(Vector3 color, Vector3 position);
	~Cube();
};

