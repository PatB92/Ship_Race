#pragma once

#include "PrimitiveModel.h"

class Ship
	: PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();

private:

	// Helper Functions
	void Movement();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};

