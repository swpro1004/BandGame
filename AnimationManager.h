#pragma once
class MovingAnimation
{
private:
	Image * Animation;
	int x, y;
	int Pixels, Range, pm = 0;
	bool bIsVisible, bIsBack;
	SDL_Rect rtClip;

public:
	MovingAnimation(SDL_Renderer* screen, int _Pixels, int _range, int _x, int _y, const char *_dir);
	void DrawMovingAnimation(SDL_Renderer * screen);
	void MoveImg();
	void SetVisible(bool VisibleSet);
	void Release();
	bool GetVisible() { return bIsVisible;  };
};

