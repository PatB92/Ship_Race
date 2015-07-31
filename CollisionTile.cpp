#include "CollisionTile.h"


CollisionTile::CollisionTile()
{
}

CollisionTile::CollisionTile(float p_posX, float p_posY, float p_posZ, float p_isActive)
	: posX(p_posX)
	, posY(p_posY)
	, posZ(p_posZ)
	, height(5.0f)
	, width(5.0f)
	, isActive(p_isActive)
{
}

CollisionTile::~CollisionTile()
{
}
