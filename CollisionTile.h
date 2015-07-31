#pragma once

#include "PrimitiveModel.h"

class CollisionTile
{
public:
	CollisionTile();
	CollisionTile(float posX, float posY, float posZ, float isActive);
	~CollisionTile();

	// Values
	float posX;
	float posY;
	float posZ;
	float height;
	float width;
	bool isActive;

};

