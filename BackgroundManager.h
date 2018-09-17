#pragma once
class Background
{
private:
	enum {BG1, BG2, BG3, BG4, BG5, END};
	Image* BGImage;
	int currentBG, prevBG;
	
public:
	Background(SDL_Renderer* screen);
	void ChangeBackground(int target);
	int GetBackgroundState();
	void Release();
	void DisplayBackground(SDL_Renderer* screen);
	~Background();
};

