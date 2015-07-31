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
	, move(m)
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
	//SetRotationY(GetRotationY() + 10.f * gTimer->GetDeltaTime());

	Movement();
}

// Handles the Movement of the Obstacle
void Obstacle::Movement()
{
	respawning = false;

	if (move)
	{
		SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - 400.0f * gTimer->GetDeltaTime());
	}
}

// Respawn function
void Obstacle::Respawn()
{
	SetPosition(mSpawnPos.x, mSpawnPos.y, 500.0f);
	respawning = true;
}