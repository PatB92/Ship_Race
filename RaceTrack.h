#pragma once
#include "PrimitiveModel.h"

class RaceTrack 
	:PrimitiveModel
{
public:
	RaceTrack();
	~RaceTrack();

	void Update();

	// Setter
	void SetTrackStatus(bool status) { SetActive(status); };

private:

	// Helper function
	void ManageRaceTrack();
	void MovementOfTrack();
	void RepeatTrack();
};

