#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	Ship* ship = new Ship();
	RaceTrack* raceTrack = new RaceTrack();
	
	obstacles[1] = new Obstacle(-5.0f,5.0f,1000.f,true);
	obstacles[2] = new Obstacle(0.0f, 5.0f, 1000.f, true);
	obstacles[3] = new Obstacle(5.0f, 5.0f, 1000.f, true);
	obstacles[4] = new Obstacle(-5.0f, 0.0f, 1000.f, true);
	obstacles[5] = new Obstacle(0.0f, 0.0f, 1000.f, true);
	obstacles[6] = new Obstacle(5.0f, 0.0f, 1000.f, true);
	obstacles[7] = new Obstacle(-5.0f, -5.0f, 1000.f, true);
	obstacles[8] = new Obstacle(0.0f, -5.0f, 1000.f, false);
	obstacles[9] = new Obstacle(5.0f, -5.0f, 1000.f, true);

	
}

ShipRace::~ShipRace()
{

}

void ShipRace::Start()
{

}

void ShipRace::Update()
{
	for (int i = 0; i < 9; ++i)
	{
		if (obstacles[i]->GetPosition().z < -15.0f)
		{
			obstacles[i]->Respawn();
		}
	}
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}