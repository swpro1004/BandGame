#pragma once
#include "stdafx.h"

class Button
{
private:
	enum eButtonState { BUTTONDOWN, BUTTONUP, BUTTONOVER };

	Image* imgUp;
	Image* imgDown;
	Image* imgOver;
	Image* imgCurrent;	//Current : ����

	SDL_Rect rtClip;

	int nX, nY;
	bool bIsVisible;
	bool bIsOver;

	void	(*func)(void);
public:

Button(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y, void(*f)(void));
void SetButtonState(int State);
//��ư �ʱ�ȭ
void Release(); //�޸� ����
void Draw(SDL_Renderer* screen); //��ư �׸��� ���

Button::eButtonState GetState();
void ClickDown();
void ClickUp();
void OnMouse();

bool IsOver(int px, int py); // ���콺 �����ִ��� Ȯ��
void Toggle(); // �ݴ�
void ResetOnUp(); // ���� �� ���·�
//void SetCoord(SDL_Surface* img, int x, int y); // ��ǥ ��ȯ
void SetVisible(bool visible); // Ȱ��ȭ ��ȯ
void SetOver(bool over);
bool IsVisible(); // Ȱ��ȭ Ȯ��

void MouseDown(int px, int py); //
void MouseUp(int px, int py);
//
void MouseOver(int px, int py);

void ChangeRect(int px, int py);
void ChangeButton(SDL_Renderer * screen, const char * szUp, const char * szDown, const char * szOver, int x, int y);
Image* GetDownImg() { return imgDown; }
};
