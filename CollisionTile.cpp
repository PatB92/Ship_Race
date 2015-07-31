#include "CollisionTile.h"


CollisionTile::CollisionTile()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
{
}

CollisionTile::CollisionTile(float p_posX, float p_posY, float p_posZ, float p_isActive)
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, posX(p_posX)
	, posY(p_posY)
	, posZ(p_posZ)
	, height(5.0f)
	, width(5.0f)
	, isActive(p_isActive)
{


	SetPosition(posX, posY, posZ);
	SetScale(5.0f, 5.0f, 0.5f);
	SetActive(isActive);
}


CollisionTile::~CollisionTile()
{
}
