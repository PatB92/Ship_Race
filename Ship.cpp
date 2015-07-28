#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CYLINDER)
{
	SetPosition(5.f, 5.f, 5.f);
}

Ship::~Ship()
{
}

void Ship::Update()
{
	SetRotationY(GetRotationY() + 10.f * gTimer->GetDeltaTime());	
}
