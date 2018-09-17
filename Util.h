#pragma once
#include <iostream>
#include <math.h>
#include <assert.h>

#define SCREEN_WIDTH			1280		//������ ũ�� �� �ʺ�
#define SCREEN_HEIGHT			720		//������ ũ�� �� ����

const float   PI = 3.14159f;

#define MIN8								0x00		//8Bit�� ������ //16���� 0x00 //10���� 0
#define MAX8							0xff		//8Bit�� �ְ� //16���� 0xff, 0xFF //10���� 255
#define MAX_STRING				256
enum State {
	MAIN = 0,
	INGAME,
	CREDIT,
	HOWTO,
	HOWTO_2,
	HOWTO_3,
	Secret
};