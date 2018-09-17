#pragma once
class CAnimation {
private:
	bool isPlaying, isVisible;
	int MaxIndex, currentIndex, round;
	int* Delay;
	Image *currentImg, *IdleImg, **ImgList;
public:
	CAnimation(SDL_Renderer* screen, int _MaxIndex, int* _Delay, const char *animDir, int _x, int _y);
	void Update(SDL_Renderer * screen);
	void SetActive(bool ActiveSet);
	void SetVisible(bool VisibleSet);
	void Play();
	void Release();
};


class CAnim {
private:
	CAnimation* AnimCharacter[4];
	bool Anim[4][180] = { false,  };
public:
	CAnim(CAnimation** _AnimCharacter);
	void ChangeBoolean(int AnimType, int AnimTiming, bool data = false);
	~CAnim();
};


