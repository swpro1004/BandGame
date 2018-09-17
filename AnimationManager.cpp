#include "stdafx.h"

MovingAnimation::MovingAnimation(SDL_Renderer * screen, int _Pixels, int _range, int _x, int _y, const char *_dir)
{
	rtClip.x = _x; rtClip.y = _y;
	Pixels = _Pixels;
	Range = _range;
	char dir[MAX_STRING];
	sprintf(dir, _dir);
	Animation = new Image(screen, dir, rtClip.x, rtClip.y);
	rtClip.w = Animation->GetRect(1);
	rtClip.h = Animation->GetRect(0);
	bIsVisible = false;
}

void MovingAnimation::DrawMovingAnimation(SDL_Renderer * screen)
{
	if (!bIsVisible) return;
	Animation->ChangeRect(rtClip.x, rtClip.y);
	Animation->DrawImg(screen);
}

void MovingAnimation::MoveImg()
{
	if (pm > Range) {
		Pixels = -Pixels;
		pm = -Range;
	}
	rtClip.x += Pixels;
	pm++;
}

void MovingAnimation::SetVisible(bool VisibleSet) {
	bIsVisible = VisibleSet;
}

void MovingAnimation::Release() {
	Animation->Release();
}