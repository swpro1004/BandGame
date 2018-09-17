#pragma once
#include "stdafx.h"

class Button
{
private:
	enum eButtonState { BUTTONDOWN, BUTTONUP, BUTTONOVER };

	Image* imgUp;
	Image* imgDown;
	Image* imgOver;
	Image* imgCurrent;	//Current : 현재

	SDL_Rect rtClip;

	int nX, nY;
	bool bIsVisible;
	bool bIsOver;

	void	(*func)(void);
public:

Button(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y, void(*f)(void));
void SetButtonState(int State);
//버튼 초기화
void Release(); //메모리 해제
void Draw(SDL_Renderer* screen); //버튼 그리는 장소

Button::eButtonState GetState();
void ClickDown();
void ClickUp();
void OnMouse();

bool IsOver(int px, int py); // 마우스 위에있는지 확인
void Toggle(); // 반대
void ResetOnUp(); // 전부 뗌 상태로
//void SetCoord(SDL_Surface* img, int x, int y); // 좌표 변환
void SetVisible(bool visible); // 활성화 변환
void SetOver(bool over);
bool IsVisible(); // 활성화 확인

void MouseDown(int px, int py); //
void MouseUp(int px, int py);
//
void MouseOver(int px, int py);

void ChangeRect(int px, int py);
void ChangeButton(SDL_Renderer * screen, const char * szUp, const char * szDown, const char * szOver, int x, int y);
Image* GetDownImg() { return imgDown; }
};
