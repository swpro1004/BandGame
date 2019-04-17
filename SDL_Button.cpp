#include "stdafx.h"

Button::Button(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y, void (*f)(void))
{
	if (szUp != NULL) imgUp = new Image(screen, szUp, x, y);
	if (szDown != NULL) imgDown = new Image(screen, szDown, x, y);

	if (szOver != NULL) imgOver = new Image(screen, szOver, x, y);
	else imgOver = imgUp;

	imgCurrent = imgUp;

	rtClip = imgCurrent->GetImgRect(); // 버튼 크기 자동 지정
	SetVisible(true);
	SetOver(false);

	func = f; // 함수 연결
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
	if (IsOver(px, py) && IsVisible() && imgCurrent != imgDown) // 커서 위치 확인 및 중복 인식 방지
	{
		ClickDown();
	}
}

void Button::MouseUp(int px, int py)
{
	if (IsOver(px, py) && IsVisible() && imgCurrent != imgUp)  // 커서 위치 확인 및 중복 인식 방지
	{
		ClickUp();
		ResetOnUp();
	}
	else if (IsVisible()) {
		ResetOnUp();
	}
}

void Button::ChangeRect(int px, int py) // 버튼 크기 재정의
{
	imgUp->SetImgRect(px, py);
	imgDown->SetImgRect(px, py);
	imgCurrent->SetImgRect(px, py);

	rtClip = imgCurrent->GetImgRect();
}

void Button::ChangeButton(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y) { // 버튼 리소스 재정의
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
	
	if (IsOver(px, py) && IsVisible())   // 커서 위치 확인
	{
		if (!bIsOver) OnMouse();
	}
	else if (IsVisible()) {   // 아닐시 버튼 상태 초기화
		ResetOnUp();
		SetOver(false);
	}
}