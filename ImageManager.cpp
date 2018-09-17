#include "stdafx.h"

Image::Image(SDL_Renderer* screen, const char* imgDir, int _x, int _y)
{
	imgTexture = IMG_LoadTexture(screen, imgDir);
	if (imgTexture == nullptr) printf("%s", IMG_GetError());
	SetImgRect(_x, _y);
	SDL_QueryTexture(imgTexture, NULL, NULL, &imgRect.w, &imgRect.h);
}

Image::~Image()
{
}

void Image::SetImgRect(int _x, int _y)
{
	imgRect.x = _x;
	imgRect.y = _y;
}

void Image::DrawImg(SDL_Renderer* screen)
{
	SDL_RenderCopy(screen, imgTexture, NULL, &imgRect);
}

void Image::ChangeImg(SDL_Renderer* screen, const char* imgDir, int _x, int _y)
{
	SDL_DestroyTexture(imgTexture);
	imgTexture = IMG_LoadTexture(screen, imgDir);
	if (imgTexture == nullptr) printf("%s", IMG_GetError());
	SetImgRect(_x, _y);
	SDL_QueryTexture(imgTexture, NULL, NULL, &imgRect.w, &imgRect.h);
}

void Image::ChangeRect(int _x, int _y)
{
	imgRect.x = _x;
	imgRect.y = _y;
}

int Image::GetRect(bool isW)
{
	if (isW) return imgRect.w;
	else return imgRect.h;
}

void Image::Release()
{
	SDL_DestroyTexture(imgTexture);
}

SDL_Rect Image::GetImgRect()
{
	return imgRect;
}
