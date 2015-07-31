#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	// Init Game Components
	ship = new Ship();
	raceTrack = new RaceTrack();
	collisionGrid = new CollGrid();
	InitObstacles();
}

void ShipRace::InitObstacles()
{
	mObstacles[0] = new Obstacle(-5.0f, 5.0f, 1000.f, true);
	mObstacles[1] = new Obstacle(0.0f, 5.0f, 1000.f, true);
	mObstacles[2] = new Obstacle(5.0f, 5.0f, 1000.f, true);
	mObstacles[3] = new Obstacle(-5.0f, 0.0f, 1000.f, true);
	mObstacles[4] = new Obstacle(0.0f, 0.0f, 1000.f, false);
	mObstacles[5] = new Obstacle(5.0f, 0.0f, 1000.f, true);
	mObstacles[6] = new Obstacle(-5.0f, -5.0f, 1000.f, true);
	mObstacles[7] = new Obstacle(0.0f, -5.0f, 1000.f, true);
	mObstacles[8] = new Obstacle(5.0f, -5.0f, 1000.f, true);

	mCurrentInActiveTile = collisionGrid->collisionTiles[4];
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
		bool reached = mObstacles[i]->ReachedLimit();
		if (reached)
		{
			// Verify Collision
			// if no collision -> Reset Obstacles
			// If collision -> Game Over
			VerifyCollision();
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
		mObstacles[i]->Respawn();

		// Activates or Deactivates depending on the random number
		if (i == rnd)
		{
			mObstacles[i]->move = false;

			// Associate the unspawned obstacle to the collision grid
			mCurrentInActiveTile = collisionGrid->collisionTiles[i];

			// Deactivates that portion of the grid (--------------------TO MODIFY TO CHANGE THE BOOL)
			collisionGrid->collisionTiles[i]->SetActive(false);
		}
		else
		{
			mObstacles[i]->move = true;

			// Activates that portion of the grid (--------------------TO MODIFY TO CHANGE THE BOOL)
			collisionGrid->collisionTiles[i]->SetActive(true);
		}
	}
}

bool ShipRace::VerifyCollision()
{
	std::cout << ship->GetPosX() << std::endl;
	std::cout << ship->GetPosX() << std::endl;

	std::cout << mCurrentInActiveTile->posX << std::endl;
	std::cout << mCurrentInActiveTile->posY << std::endl;

}
