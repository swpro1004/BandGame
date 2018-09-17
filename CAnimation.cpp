#include "stdafx.h"


CAnimation::CAnimation(SDL_Renderer* screen, int _MaxIndex, int* _Delay, const char *animDir, int _x, int _y) {
	isPlaying = true;
	isVisible = false;
	MaxIndex = _MaxIndex - 1;
	currentIndex = 0;
	Delay = new int[_MaxIndex];
	ImgList = new Image*[_MaxIndex];
	for (int i = 0; i < _MaxIndex; i++) {
		char dir[MAX_STRING];
		char temp[MAX_STRING];
		sprintf(dir, animDir);
		sprintf(temp, "\\%d.png", i+1);
		strcat(dir, temp);
		Delay[i] = _Delay[i];
		ImgList[i] = new Image(screen, dir, _x, _y);
	}
	currentImg = ImgList[0];
	IdleImg = ImgList[0];
}

void CAnimation::Update(SDL_Renderer* screen){	 
	if (isVisible) {
		if (!isPlaying) currentImg = IdleImg;
		else Play();

		currentImg->DrawImg(screen);
	}
}

void CAnimation::SetActive(bool ActiveSet)
{
	isPlaying = ActiveSet;
}

void CAnimation::SetVisible(bool VisibleSet){

	isVisible = VisibleSet;
}

void CAnimation::Play() {
	/*if (currentIndex > MaxIndex){
		currentIndex = 0;
	}
	static float startTime = fAcculTime;

	if (fAcculTime >= startTime + Delay[currentIndex - 1]){
		printf("fAcculTime : %f // playAnimSpriteIndex : %d\n", fAcculTime, currentIndex);
		currentImg = ImgList[currentIndex];
		currentIndex++;
		startTime = fAcculTime;
	}*/
	if (!isVisible) return;
	if (round % Delay[currentIndex] == 0) {
		currentIndex++;
		if (currentIndex > MaxIndex)
			currentIndex = 0;
		currentImg = ImgList[currentIndex];
	}
	round++;
}

void CAnimation::Release() {
	currentImg->Release();
	IdleImg->Release();
	for (int i = 0; i < MaxIndex + 1; i++)
		ImgList[i]->Release();
	delete Delay;
}

CAnim::CAnim(CAnimation ** _AnimCharacter)
{
	for (int i = 0; i < 4; i++)
		AnimCharacter[i] = _AnimCharacter[i];
	FILE *pFile;

	for (int i = 0; i < 4; i++) {
		pFile = NULL;
		char temp[MAX_STRING];
		int j = 0;
		sprintf(temp, "%d.anim", i + 1);
		pFile = fopen(temp, "r");
		while (feof(pFile) == 0)
			fscanf(pFile, "%d", &Anim[i + 1][j++]);
		fclose(pFile);
	}
}

void CAnim::ChangeBoolean(int AnimType, int AnimTiming, bool data)
{
	Anim[AnimType][AnimTiming] = data;
}

CAnim::~CAnim()
{
	for (int i = 0; i < 4; i++)
		AnimCharacter[i]->Release();

	FILE *pFile = NULL;

	for (int i = 0; i < 4; i++) {
		char temp[MAX_STRING];
		int j = 0;
		sprintf(temp, "%d.anim", i + 1);
		remove(temp);
		pFile = fopen(temp, "w");
		while (feof(pFile) == 0)
			fprintf(pFile, "%d ", &Anim[i + 1][j++]);
		fclose(pFile);
	}
}


