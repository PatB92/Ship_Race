#pragma once

#include "PrimitiveModel.h"

class Obstacle :
	public PrimitiveModel
{
public:
	Obstacle();
	Obstacle(float x, float y, float z,bool m);
	~Obstacle();

	void Update();

	// Helper Functions
	void Movement();
	void Respawn();
	bool ReachedLimit();

	// Values
	bool mIsMoving;

private:

	D3DXVECTOR3 mSpawnPos;

	bool respawning;
};

