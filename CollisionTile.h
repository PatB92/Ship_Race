#pragma once

#include "PrimitiveModel.h"

class CollisionTile:
	public PrimitiveModel
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

private:


};

