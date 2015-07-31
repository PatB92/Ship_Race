#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
{
	SetPosition(0.f, 0.f, 2.f);
}

Ship::~Ship()
{
}

void Ship::Update()
{
	if (GetPosition().x > -10)
	{
		if (gDInput->keyDown(DIK_LEFT))
		{
			SetPosition(GetPosition().x - 10.f * gTimer->GetDeltaTime(), GetPosition().y, 2.f);
		}
	}

	if (GetPosition().x < 10)
	{
		if (gDInput->keyDown(DIK_RIGHT))
		{
			SetPosition(GetPosition().x + 10.f * gTimer->GetDeltaTime(), GetPosition().y, 2.f);
		}
	}

	if (GetPosition().y < 7)
	{
		if (gDInput->keyDown(DIK_UP))
		{
			SetPosition(GetPosition().x, GetPosition().y + 10.f * gTimer->GetDeltaTime(), 2.f);
		}

	}

	if (GetPosition().y > -7)
	{
		if (gDInput->keyDown(DIK_DOWN))
		{
			SetPosition(GetPosition().x, GetPosition().y - 10.f * gTimer->GetDeltaTime(), 2.f);
		}
	}
}
