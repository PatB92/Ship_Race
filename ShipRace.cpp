#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	Init();
}

void ShipRace::Init()
{
	ship = new Ship();
	raceTrack = new RaceTrack();
	collisionGrid = new CollGrid();
	InitObstacles();
	mCurrentInActiveTile = collisionGrid->collisionTiles[4];
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
}


ShipRace::~ShipRace()
{

}

void ShipRace::Start()
{
	
}

void ShipRace::Update()
{
	if (!ObstacleSpawnManager())
	{
		EndingScreen();
	}
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}

// Handles the respawn of obsacles and returns if it was possible or not (depending on collision)
bool ShipRace::ObstacleSpawnManager()
{
	for (int i = 0; i < 9; ++i)
	{
		// If Obstacles have reached the collision point
		bool reached = mObstacles[i]->ReachedLimit();
		if (reached)
		{
			bool collision = VerifyCollision();

			// If there was no collision, Reset all Obstacle values and respawns them
			if (!collision)
			{
				ResetObstacles();
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

// Reset all the obstacles at their spawn point and stops a random one
void ShipRace::ResetObstacles()
{
	// Get Random Number
	mRnd = rand() % 9;

	for (int i = 0; i < 9; ++i)
	{
		// Respawn all obstacles
		mObstacles[i]->Respawn();

		// Activates or Deactivates depending on the random number
		if (i == mRnd)
		{
			mObstacles[i]->mIsMoving = false;

			// Associate the unspawned obstacle to the collision grid
			mCurrentInActiveTile = collisionGrid->collisionTiles[i];
		}
		else
		{
			mObstacles[i]->mIsMoving = true;
		}
	}
}

// Verifies if there was a collision between player and obstacles
bool ShipRace::VerifyCollision()
{
	// Get Dimensions of the path the player must take
	float leftBorder = mCurrentInActiveTile->posX - mCurrentInActiveTile->width/2;
	float rightBorder = mCurrentInActiveTile->posX + mCurrentInActiveTile->width/2;
	float topBorder = mCurrentInActiveTile->posY + mCurrentInActiveTile->width/2;
	float bottomBorder = mCurrentInActiveTile->posY - mCurrentInActiveTile->width/2;

	// Verifies if the player is within that window
	if (ship->GetPosX() >= leftBorder && ship->GetPosX() <= rightBorder
		&& ship->GetPosY() <= topBorder && ship->GetPosY() >= bottomBorder)
	{
		std::cout << "YOU'RE OK" << std::endl;
		return false;
	}
	return true;
}

// Reset the Obstacles and the Player
void ShipRace::ResetGame()
{
	ResetObstacles();
	ship->SetShipStatus(true);
	ship->SetShipPos(0.0f, 0.0f, 0.0f);
}

void ShipRace::EndingScreen()
{
	endScreen = new EndScreen();

	ship->SetShipStatus(false);

	// Enter to Replay
	if (gDInput->keyDown(DIK_RETURN))
	{
		ResetGame();
	}

	// Backspace to Quit
	if (gDInput->keyDown(DIK_BACKSPACE))
	{
		exit(0);
	}
}
