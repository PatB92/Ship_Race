#pragma once

#include "Component.h"
#include "Ship.h"
#include "RaceTrack.h"
#include "Obstacle.h"
#include "CollGrid.h"
#include "EndScreen.h"
#include "FontApp.h"


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
	void Init();
	void InitObstacles();
	bool ObstacleSpawnManager();
	void ResetObstacles();
	bool VerifyCollision();
	void ResetGame();
	void EndingScreen();
	void DisableGame();
	void ReplayGame();
	void QuitGame();

	int mRnd;

private:
	RaceTrack* raceTrack;
	Ship* ship;
	Obstacle* mObstacles[9];
	CollGrid* collisionGrid;
	CollisionTile* mCurrentInActiveTile;
	EndScreen* endScreen;
	FontApp* score;

	D3DXVECTOR3 mOriginCamPos;
	bool mIsGameOver;
};

