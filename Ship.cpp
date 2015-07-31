#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
	, initPos(0.0f, 0.0f, 2.0f)
	, mPoints(0.0)
{
	SetPosition(initPos.x, initPos.y, initPos.z);
}

Ship::~Ship()
{
}

void Ship::Update()
{
	Movement();
}

// Handles Movement of the Player
void Ship::Movement()
{
	MoveUp();
	MoveDown();
	MoveLeft();
	MoveRight();
}

// Ship Moves Up
void Ship::MoveUp()
{
	if (GetPosition().y < SHIP_MOVE_OFFSET)
	{
		if (gDInput->keyDown(DIK_UP) || gDInput->keyDown(DIK_W))
		{
			SetPosition(GetPosition().x, GetPosition().y + SPEED * gTimer->GetDeltaTime(), 2.f);
		}
	}
}

// Ship Moves Down
void Ship::MoveDown()
{
	if (GetPosition().y > -SHIP_MOVE_OFFSET)
	{
		if (gDInput->keyDown(DIK_DOWN) || gDInput->keyDown(DIK_S))
		{
			SetPosition(GetPosition().x, GetPosition().y - SPEED * gTimer->GetDeltaTime(), 2.f);
		}
	}
}

// Ship Moves Left
void Ship::MoveLeft()
{
	if (GetPosition().x > -SHIP_MOVE_OFFSET)
	{
		if (gDInput->keyDown(DIK_LEFT) || gDInput->keyDown(DIK_A))
		{
			SetPosition(GetPosition().x - SPEED * gTimer->GetDeltaTime(), GetPosition().y, 2.f);
		}
	}
}

// Ship Moves Right
void Ship::MoveRight()
{
	if (GetPosition().x < SHIP_MOVE_OFFSET)
	{
		if (gDInput->keyDown(DIK_RIGHT) || gDInput->keyDown(DIK_D))
		{
			SetPosition(GetPosition().x + SPEED * gTimer->GetDeltaTime(), GetPosition().y, 2.f);
		}
	}
}
