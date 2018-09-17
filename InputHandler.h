#pragma once
enum MouseButton { LEFT, RIGHT, MIDDLE };
typedef struct _MOUSESTATE {
	int x;//���콺 ��ǥ
	int y;//���콺 ��ǥ
	BYTE btn[4];//��ư ��������
				//MouseButon btn[4]; �̰͵� ����

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


