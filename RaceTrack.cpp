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
	SetRotationZ(GetRotationZ() + 5.0f * gTimer->GetDeltaTime());
	SetPosition(GetPosition().x, GetPosition().y, GetPosition().z - 1.0f * gTimer->GetDeltaTime());

}