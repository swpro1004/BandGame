#include "stdafx.h"


FishButton::FishButton(SDL_Renderer* screen, void(*f)(void))
{
	RightButton = rand() % 6;
	bIsVisible = true;
	bIsOver = false;
	bIsMove = true;

	rtClip[0].x = 183; rtClip[0].y = 60;
	rtClip[1].x = 569; rtClip[1].y = 162;
	rtClip[2].x = 653; rtClip[2].y = 141;
	rtClip[3].x = 1072; rtClip[3].y = 78;
	rtClip[4].x = 1234; rtClip[4].y = 242;
	rtClip[5].x = 17; rtClip[5].y = 347;

	for (int i = 0; i < 6; i++) {
		char dir[MAX_STRING];
		sprintf(dir, "Image\\Fish\\%d.png", i + 1);
		Fish[i] = new Image(screen, dir, rtClip[i].x, rtClip[i].y);
		rtClip[i].w = Fish[i]->GetRect(1); rtClip[i].h = Fish[i]->GetRect(0);
	}

	func = f;
}

void FishButton::DrawFish(SDL_Renderer* screen)
{
	if (!bIsVisible) return;
	static int round = 0, pm = 0, reverse = 3;
	if (round % 10 == 0) {
		if (pm > 5) {
				reverse *= -1;
				pm = -5;
		}
		for (int i = 0; i < 6; i++) {
			if (i != RightButton) {
				rtClip[i].x += reverse;
				Fish[i]->ChangeRect(rtClip[i].x, rtClip[i].y);
			}
			else if (bIsMove){
				rtClip[i].x += reverse;
				Fish[i]->ChangeRect(rtClip[i].x, rtClip[i].y);
			}
		}
		pm++;
	}
	for (int i = 0; i < 6; i++)
		Fish[i]->DrawImg(screen);
	round++;
}

bool FishButton::IsOver(int px, int py, int type)
{
	if ((px >= rtClip[type].x) && (px < (rtClip[type].x + rtClip[type].w)))
	{
		if ((py >= rtClip[type].y) && (py < (rtClip[type].y + rtClip[type].h)))
		{
			return true;
		}
	}
	return false;
}

void FishButton::MouseUp(int px, int py, State &currentState)
{
	for (int i = 0; i < 6; i++) {
		if (IsOver(px, py, i) && bIsVisible && i == RightButton)
			func();
	}
}

void FishButton::MouseOver(int px, int py)
{
	for (int i = 0; i < 6; i++) {

		if (IsOver(px, py, i) && bIsVisible) {

			if (i == RightButton) {
				printf("??");
				bIsMove = false;
			}
		}
		else if (i == RightButton) {
			bIsMove = true;
		}
	}
}

void FishButton::SetVisible(bool VisibleSet)
{
	bIsVisible = VisibleSet;
}

void FishButton::Release()
{
	for (int i = 0; i < 6; i++)
		Fish[i]->Release();
}