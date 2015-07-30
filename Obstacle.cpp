#include "Obstacle.h"


Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::TEAPOT)
	, mSpawnPos(-5.0f, 5.0f, 5.0f)
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, mSpawnPos.z);
}


Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{
	SetRotationY(GetRotationY() + 10.f * gTimer->GetDeltaTime());

	Movement();
}

// Handles the Movement of the Obstacle
void Obstacle::Movement()
{
	SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - 10.0f * gTimer->GetDeltaTime());

	RespawnManager();
}

// Handles when the Obstacle must Respawn
void Obstacle::RespawnManager()
{
	if (GetPosition().z > 5.0f)
	{
		Respawn();
	}
}

// Respawn function
void Obstacle::Respawn()
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, mSpawnPos.z);
}