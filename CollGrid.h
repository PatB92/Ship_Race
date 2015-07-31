#pragma once

#include "CollisionTile.h"

class CollGrid
{
public:
	CollGrid();
	~CollGrid();

	// Helper Functions
	void InitGrid();

	CollisionTile* collisionTiles[9];
};

