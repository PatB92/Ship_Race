#include "RaceTrack.h"

RaceTrack::RaceTrack()
	: PrimitiveModel(PrimitiveModel_Type::CYLINDER)
{
	SetPosition(0.0f, 0.0f, 0.0f);
	SetScale(30.0f, 30.0f, -3000.0f);
}


RaceTrack::~RaceTrack()
{
}

void RaceTrack::Update()
{
	ManageRaceTrack();
}

void RaceTrack::ManageRaceTrack()
{
	MovementOfTrack();
	RepeatTrack();
}

// Makes the track go backward to give the impression of movement
void RaceTrack::MovementOfTrack()
{
	SetRotationZ(GetRotationZ() + 5.0f * gTimer->GetDeltaTime());
	SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - 2000.0f * gTimer->GetDeltaTime());
}

// When track reaches a certain point it repeats itself
void RaceTrack::RepeatTrack()
{
	if (GetPosition().z < -1000.0f)
	{
		SetPosition(GetPosition().x, GetPosition().y, 0.0f);
	}
}