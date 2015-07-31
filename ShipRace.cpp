#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	Ship* ship = new Ship();
	RaceTrack* raceTrack = new RaceTrack();
	
	obstacles[1] = new Obstacle(3.5f,5.0f,500.f);
	obstacles[2] = new Obstacle(-3.5f, 5.0f, 500.f);
	obstacles[3] = new Obstacle(3.5f, 0.0f, 500.f);
	obstacles[4] = new Obstacle(-3.5f, 0.0f, 500.f);
	obstacles[5] = new Obstacle(3.5f, -5.0f, 500.f);
	obstacles[6] = new Obstacle(-3.5f, -5.0f, 500.f);
	obstacles[7] = new Obstacle(3.5f, -10.0f, 500.f);
	obstacles[8] = new Obstacle(-3.5f, -10.0f, 500.f);
	obstacles[9] = new Obstacle(3.5f, -15.0f, 500.f);

	
}

ShipRace::~ShipRace()
{

}

void ShipRace::Start()
{

}

void ShipRace::Update()
{
	//static float rotation = 0;
	//rotation += 0.00001;
	//triGrid->SetRotation(rotation);
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}