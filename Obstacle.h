#pragma once

#include "PrimitiveModel.h"

class Obstacle :
	public PrimitiveModel
{
public:
	Obstacle();
	Obstacle(float x, float y, float z);
	~Obstacle();

	void Update();

private:

	D3DXVECTOR3 mSpawnPos;

	// Helper functions
	void Movement();
	void RespawnManager();
	void Respawn();
};

