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

	void Movement();
	void Respawn();

private:

	D3DXVECTOR3 mSpawnPos;

	bool move, respawning;

	// Helper functions
	
};

