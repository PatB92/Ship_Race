#include "Obstacle.h"


Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, mSpawnPos(0.0f, 0.0f, 0.0f)
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, mSpawnPos.z);
	SetScale(1.5f, 1.5f, 1.0f);
}

Obstacle::Obstacle(float x, float y, float z, bool m)
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, mSpawnPos(x, y, z)
	, mIsMoving(m)
	, respawning(false)
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, mSpawnPos.z);
	SetScale(5.0f, 5.0f, 0.5f);
}


Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{
	Movement();
}

// Handles the Movement of the Obstacle
void Obstacle::Movement()
{
	respawning = false;

	if (mIsMoving)
	{
		//SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - 400.0f * gTimer->GetDeltaTime());

		// TEMP FOR DEBUGGING
		SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - 200.0f * gTimer->GetDeltaTime());
	}
}

// Respawn function
void Obstacle::Respawn()
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, 500.0f);
	respawning = true;
}

bool Obstacle::ReachedLimit()
{
	return GetPosition().z < -15.0f;
}