#include "EndScreen.h"


EndScreen::EndScreen()
	:Sprite(Texture::END_SCREEN)
{
	// Sets the ending Screen Properly
	this->SetID(Components::END_SCREEN);
	SetPosition(-520.0f, 500.0f);
	SetVisible(false);
	SetRotationDeg(0.0f, 180.0f, 0.0f);
	Scale(-1.0f);
}

EndScreen::~EndScreen()
{

}
