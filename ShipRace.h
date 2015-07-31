#pragma once

#include "Component.h"
#include "Triangle.h"
#include "Cube.h"
#include "TriGrid.h"
#include "Ship.h"
#include "RaceTrack.h"
#include "Obstacle.h"

class ShipRace :
	public Component
{
public:
	ShipRace();
	~ShipRace();

	void Start();
	void Update();
	void Draw();
	void Stop();

	// Helper Functions
	void InitObstacles();
	void ObstacleSpawnManager();

private:
	RaceTrack* raceTrack;
	Ship* ship;
	Obstacle* obstacles[9];
};

