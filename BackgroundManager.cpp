#include "stdafx.h"
const char* root[] = {
"Image\\background1.png",
"Image\\background2.png",
"Image\\Credit_.png",
"Image\\Secret.png",
"Image\\Secret2.png",
NULL
};


Background::Background(SDL_Renderer* screen)
{
	currentBG = 0;
	prevBG = currentBG;
	BGImage = new Image(screen, root[currentBG], 0, 0);
}

void Background::ChangeBackground(int target)
{
	if (currentBG != target) {
		prevBG = currentBG;
		currentBG = target;
		printf("S%d", currentBG);
	}
}

int Background::GetBackgroundState()
{
	return currentBG;
}

void Background::Release()
{
	BGImage->Release();
}

void Background::DisplayBackground(SDL_Renderer* screen)
{

	if (currentBG != prevBG)
		BGImage->ChangeImg(screen, root[currentBG], 0, 0);
	BGImage->DrawImg(screen);
}

Background::~Background()
{
}