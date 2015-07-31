#include "CollGrid.h"


CollGrid::CollGrid()
{
	InitGrid();
}

void CollGrid::InitGrid()
{
	collisionTiles[0] = new CollisionTile(-5.0f, 5.0f, 2.0f, true);
	collisionTiles[1] = new CollisionTile(0.0f, 5.0f, 2.0f, true);
	collisionTiles[2] = new CollisionTile(5.0f, 5.0f, 2.0f, true);
	collisionTiles[3] = new CollisionTile(-5.0f, 0.0f, 2.0f, true);
	collisionTiles[4] = new CollisionTile(0.0f, 0.0f, 2.0f, false);
	collisionTiles[5] = new CollisionTile(5.0f, 0.0f, 2.0f, true);
	collisionTiles[6] = new CollisionTile(-5.0f, -5.0f, 2.0f, true);
	collisionTiles[7] = new CollisionTile(0.0f, -5.0f, 2.0f, true);
	collisionTiles[8] = new CollisionTile(5.0f, -5.0f, 2.0f, true);
}


CollGrid::~CollGrid()
{
}
