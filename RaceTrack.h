#pragma once
#include "PrimitiveModel.h"

class RaceTrack 
	:PrimitiveModel
{
public:
	RaceTrack();
	~RaceTrack();

	void Update();

private:

	// Helper function
	void ManageRaceTrack();
	void MovementOfTrack();
	void RepeatTrack();
};

