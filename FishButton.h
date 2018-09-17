#pragma once
class FishButton
{
private:
	Image * Fish[6];
	int x[6], y[6];
	SDL_Rect rtClip[6];
	int RightButton;

	bool bIsVisible;
	bool bIsOver;
	bool bIsMove;
	void(*func)(void);

public:
	FishButton(SDL_Renderer* screen, void(*f)(void));
	void DrawFish(SDL_Renderer * screen);
	bool IsOver(int px, int py, int type);
	void MouseOver(int px, int py);
	void SetVisible(bool VisibleSet);
	void Release();
	void MouseUp(int px, int py, State &currentState);
};

