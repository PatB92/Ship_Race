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

// Handles the respawn of obsacles
void ShipRace::ObstacleSpawnManager()
{
	// Get Random Number
	mRnd = rand() % 9;
	
	// If one obstacles reaches the limit, they're all Reset
	for (int i = 0; i < 9; ++i)
	{
		bool reached = obstacles[i]->ReachedLimit();
		if (reached)
		{
			ResetObstacles(mRnd);
			break;
		}
	}
}

// Reset all the obstacles at their spawn point and stops a random one
void ShipRace::ResetObstacles(int rnd)
{
	for (int i = 0; i < 9; ++i)
	{
		obstacles[i]->Respawn();

		if (i == rnd)
		{
			obstacles[i]->move = false;
		}
		else
		{
			obstacles[i]->move = true;
		}
	}
}
