#include "stdafx.h"

Button::Button(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y, void (*f)(void))
{
	if (szUp != NULL) imgUp = new Image(screen, szUp, x, y);
	if (szDown != NULL) imgDown = new Image(screen, szDown, x, y);
	if (szOver != NULL) imgOver = new Image(screen, szOver, x, y);
	else imgOver = imgUp;
	imgCurrent = imgUp;

	rtClip = imgCurrent->GetImgRect();
	SetVisible(true);
	SetOver(false);

	func = f;
}

void Button::SetButtonState(int State) {
	switch (State) {
	case 0:
		imgCurrent = imgUp;
		break;
	case 1:
		imgCurrent = imgDown;
		break;
	case 2:
		imgCurrent = imgOver;
		break;
	}
}

void Button::Release()
{
	if (this == NULL) return;

	if (imgUp != 0)	imgUp->Release();
	if (imgDown != 0)	imgDown->Release();

	free(this);
}

void Button::Draw(SDL_Renderer* screen)
{
	if (!bIsVisible) return;
	imgCurrent->DrawImg(screen);
}

Button::eButtonState Button::GetState()
{
	if (imgCurrent == imgDown)
		return BUTTONDOWN;
	else if (imgCurrent == imgUp)
		return BUTTONUP;
	else
		return BUTTONOVER;
}

void Button::ClickDown()
{
	imgCurrent = imgDown;
	
	printf("D");
}

void Button::ClickUp()
{
	imgCurrent = imgUp;
	if (func != 0)
	{
		func();
	}
	printf("U");
}

void Button::OnMouse()
{
	imgCurrent = imgOver;
	SetOver(true);
	printf("O");
}

bool Button::IsOver(int px, int py)
{
	if ((px >= rtClip.x) && (px < (rtClip.x +rtClip.w)))
	{
		if ((py >= rtClip.y) && (py < (rtClip.y + rtClip.h)))
		{
			return true;
		}
	}
	return false;
}

void Button::Toggle()
{
	if (imgCurrent ==imgUp)
		imgCurrent = imgDown;
	else
		imgCurrent = imgUp;
}

void Button::ResetOnUp()
{
	imgCurrent = imgUp;
}

//void Button::SetCoord(SDL_Surface* img, int x, int y)
//{
//	rtClip.x = x;
//	rtClip.y = y;
//	rtClip.w = img->w;
//	rtClip.h = img->h;
//}

void Button::SetVisible(bool visible)
{
	bIsVisible = visible;
}

void Button::SetOver(bool over)
{
	bIsOver = over;
}

bool Button::IsVisible()
{
	return bIsVisible;
}

void Button::MouseDown(int px, int py)
{
	if (IsOver(px, py) && IsVisible() && imgCurrent != imgDown)
	{
		ClickDown();
	}
}

void Button::MouseUp(int px, int py)
{
	if (IsOver(px, py) && IsVisible() && imgCurrent != imgUp)
	{
		ClickUp();
		ResetOnUp();
	}
	else if (IsVisible()) {
		ResetOnUp();
	}
}

void Button::ChangeRect(int px, int py)
{
	imgUp->SetImgRect(px, py);
	imgDown->SetImgRect(px, py);
	imgCurrent->SetImgRect(px, py);

	rtClip = imgCurrent->GetImgRect();
}

void Button::ChangeButton(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y) {
	if (szUp != NULL) imgUp->ChangeImg(screen, szUp, x, y);
	if (szDown != NULL) imgDown->ChangeImg(screen, szDown, x, y);
	if (szOver != NULL) imgOver->ChangeImg(screen, szOver, x, y);
	else imgOver = imgUp;
	imgCurrent = imgUp;

	rtClip = imgCurrent->GetImgRect();
	SetVisible(true);
	SetOver(false);
}

void Button::MouseOver(int px, int py)

{
	
	if (IsOver(px, py) && IsVisible())
	{
		if (!bIsOver) OnMouse();
	}
	else if (IsVisible()) {
		ResetOnUp();
		SetOver(false);
	}
}