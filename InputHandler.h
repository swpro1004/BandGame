#pragma once
enum MouseButton { LEFT, RIGHT, MIDDLE };
typedef struct _MOUSESTATE {
	int x;//마우스 좌표
	int y;//마우스 좌표
	BYTE btn[4];//버튼 눌렸을때
				//MouseButon btn[4]; 이것도 가능

}MOUSESTATE;

class IInputHandler
{
public:
	IInputHandler()
	{
	}

	virtual ~IInputHandler()
	{
	}

public:
	virtual void KeyboardHandler(void) = 0;
	virtual void MouseHandler(SDL_Event evnt, MOUSESTATE mouseState) = 0;
};


