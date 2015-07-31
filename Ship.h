#pragma once

#include "PrimitiveModel.h"


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
	
	// Setter
	void SetShipStatus(bool status) { SetActive(status); };
	void SetShipPos(float x, float y, float z) { SetPosition(x, y, z); };

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

};

