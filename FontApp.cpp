#include "FontApp.h"


FontApp::FontApp()
{
	D3DXFONT_DESC fontDesc;
	fontDesc.Height = 40;
	fontDesc.Width = 20;
	fontDesc.MipLevels = 0;
	fontDesc.Italic = false;
	fontDesc.CharSet = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.Quality = DEFAULT_QUALITY;
	fontDesc.PitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	strcpy_s(fontDesc.FaceName, _T("Times New Roman"));

	D3DXCreateFontIndirect(gD3DDevice, &fontDesc, &mFont);

	std::string* s = new std::string();

}

FontApp::~FontApp()
{
	ReleaseCOM(mFont);
}

void FontApp::OnLostDevice()
{
	HR(mFont->OnLostDevice());
}

void FontApp::OnResetDevice()
{
	HR(mFont->OnLostDevice());
}

void FontApp::Update()
{
	
}

void FontApp::Draw()
{
	RECT fontRect;
	::GetClientRect(gApp->GetMainWindow(), &fontRect);

	mFont->DrawTextA(0, _T("LIFE: " Score()), -1, &fontRect,
		DT_BOTTOM | DT_BOTTOM | DT_SINGLELINE,
		D3DCOLOR_XRGB(0,0,0));
}

std::string Score()
{
	std::string st = std::to_string(100);

	return st;
}


