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
	Movement();
}

void Ship::Movement()
{
	MoveUp();
	MoveDown();
	MoveLeft();
	MoveRight();
}

void Ship::MoveUp()
{
	if (GetPosition().y < 7)
	{
		if (gDInput->keyDown(DIK_UP) || gDInput->keyDown(DIK_W))
		{
			SetPosition(GetPosition().x, GetPosition().y + SPEED * gTimer->GetDeltaTime(), 2.f);
		}
	}
}

void Ship::MoveDown()
{
	if (GetPosition().y > -7)
	{
		if (gDInput->keyDown(DIK_DOWN) || gDInput->keyDown(DIK_S))
		{
			SetPosition(GetPosition().x, GetPosition().y - SPEED * gTimer->GetDeltaTime(), 2.f);
		}
	}
}
void Ship::MoveLeft()
{
	if (GetPosition().x > -10)
	{
		if (gDInput->keyDown(DIK_LEFT) || gDInput->keyDown(DIK_A))
		{
			SetPosition(GetPosition().x - SPEED * gTimer->GetDeltaTime(), GetPosition().y, 2.f);
		}
	}
}

void Ship::MoveRight()
{
	if (GetPosition().x < 10)
	{
		if (gDInput->keyDown(DIK_RIGHT) || gDInput->keyDown(DIK_D))
		{
			SetPosition(GetPosition().x + SPEED * gTimer->GetDeltaTime(), GetPosition().y, 2.f);
		}
	}
}
