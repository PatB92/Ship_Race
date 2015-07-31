#include "Obstacle.h"


Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, mSpawnPos(0.0f, 0.0f, 0.0f)
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, mSpawnPos.z);
	//SetScale(1.5f, 1.5f, 1.0f);
}

Obstacle::Obstacle(float x, float y, float z)
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, mSpawnPos(x, y, z)
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, mSpawnPos.z);
}


Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{
	//SetRotationY(GetRotationY() + 10.f * gTimer->GetDeltaTime());

	Movement();
}

// Handles the Movement of the Obstacle
void Obstacle::Movement()
{
	SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - 200.0f * gTimer->GetDeltaTime());

	RespawnManager();
}

// Handles when the Obstacle must Respawn
void Obstacle::RespawnManager()
{
	if (GetPosition().z < -15.0f)
	{
		Respawn();
	}
}

// Respawn function
void Obstacle::Respawn()
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, 250.0f);
}