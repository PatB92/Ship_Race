#pragma once

#include "PrimitiveModel.h"

#define SHIP_MOVE_OFFSET 7.49f

class Ship
	: PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();

	// Getter
	float GetPosX() { return GetPosition().x; };
	float GetPosY() { return GetPosition().y; };
	float GetPoints() { return mPoints; };
	
	// Setter
	void SetShipStatus(bool status) { SetActive(status); };
	void SetShipPos(float x, float y, float z) { SetPosition(x, y, z); };
	void SetPoints(float pointsGiven) { mPoints += pointsGiven; };

private:

	// Helper Functions
	void Movement();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	// const
	const float SPEED = 20.0f;

	// Values
	D3DXVECTOR3 initPos;
	float mPoints;

};

