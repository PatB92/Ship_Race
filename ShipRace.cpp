#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	// Init Game Components
	Ship* ship = new Ship();
	RaceTrack* raceTrack = new RaceTrack();
	InitObstacles();
}

void ShipRace::InitObstacles()
{
	obstacles[0] = new Obstacle(-5.0f, 5.0f, 1000.f, true);
	obstacles[1] = new Obstacle(0.0f, 5.0f, 1000.f, true);
	obstacles[2] = new Obstacle(5.0f, 5.0f, 1000.f, true);
	obstacles[3] = new Obstacle(-5.0f, 0.0f, 1000.f, true);
	obstacles[4] = new Obstacle(0.0f, 0.0f, 1000.f, false);
	obstacles[5] = new Obstacle(5.0f, 0.0f, 1000.f, true);
	obstacles[6] = new Obstacle(-5.0f, -5.0f, 1000.f, true);
	obstacles[7] = new Obstacle(0.0f, -5.0f, 1000.f, true);
	obstacles[8] = new Obstacle(5.0f, -5.0f, 1000.f, true);
}


ShipRace::~ShipRace()
{

}

void ShipRace::Start()
{
	
}

void ShipRace::Update()
{
	ObstacleSpawnManager();
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}

void ShipRace::ObstacleSpawnManager()
{
	for (int i = 0; i < 9; ++i)
	{
		bool test = obstacles[i]->ReachedLimit();
		if (test)
		{
			obstacles[i]->Respawn();
		}
	}
}