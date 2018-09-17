#include "stdafx.h"

Button* StartBtn, *CreditBtn, *MainBtn, *PauseBtn, *SongBtn[5], * HowtoBtn, *ExitBtn, *PlayBtn, *HowToButton[3];
State currentState;
SoundManager Sound;
MovingAnimation* MovingSea, *MovingStar, *MovingMermaid;
FishButton* Fish;
CAnimation* BGAnim, *Char1, *Char2_1, *Char2_2, *Char3, *Tail_, *mainStar, *subStar;
//CAnim* AnimationMamager;
Background* BG;
Image* Star, *Song[5], *Cloud, *Char3_Base;
bool isStart = true, gameQuit = false, isPause = true, isMainFirst = true, isSecretFirst = false, Anim[4] = { false, };
float count = 0;
void AnimationType(int Type = 6);
void MusicStop();

void Climax() {
	if (Sound.GetCurrentState() == 1) {
		switch (Sound.GetCurrentSongID()) {
		case 0:
		{
			if (((int)count >= 1 && (int)count < 18) ||
				((int)count >= 27 && (int)count < 34) ||
				((int)count >= 44.5 && (int)count < 49) ||
				((int)count >= 84 && (int)count < 100) ||
				(int)count == 103 ||
				(int)count == 107 ||
				(int)count == 110 ||
				((int)count >= 115 && (int)count < 131) ||
				((int)count >= 168 && (int)count < 170) ||
				((int)count >= 172 && (int)count < 174) ||
				((int)count >= 176 && (int)count < 178) ||
				((int)count >= 200 && (int)count < 235))
				Char1->SetActive(true);
			else Char1->SetActive(false);

			if (((int)count >= 49 && (int)count < 84) ||
				(int)count == 114 ||
				((int)count >= 118 && (int)count < 120) ||
				((int)count >= 122 && (int)count < 124) ||
				((int)count >= 126 && (int)count < 128) ||
				((int)count >= 131 && (int)count < 165) ||
				((int)count >= 200 && (int)count < 235))
				Char2_1->SetActive(true);
			else Char2_1->SetActive(false);

			if (((int)count >= 49 && (int)count < 84) ||
				(int)count == 114 ||
				((int)count >= 118 && (int)count < 120) ||
				((int)count >= 122 && (int)count < 124) ||
				((int)count >= 126 && (int)count < 128) ||
				((int)count >= 131 && (int)count < 165) ||
				((int)count >= 200 && (int)count < 235))
				Char2_2->SetActive(true);
			else Char2_2->SetActive(false);

			if (((int)count >= 1 && (int)count < 18) ||
				((int)count >= 84 && (int)count < 100))
				Tail_->SetActive(true);
			else Tail_->SetActive(false);

			if ((count >= 18.5 && (int)count < 33) ||
				((int)count >= 34 && (int)count < 49) ||
				((int)count >= 100 && (int)count < 115) ||
				((int)count >= 165 && (int)count < 196) ||
				((int)count >= 215 && (int)count < 235))
				Char3->SetActive(true);
			else Char3->SetActive(false);

			break;
		}

		case 1:
		{

			if (((int)count >= 12 && (int)count < 18) ||
				((int)count >= 25 && (int)count < 37) ||
				((int)count >= 49 && (int)count < 51) ||
				((int)count >= 56 && (int)count < 61) ||
				((int)count >= 68 && (int)count < 74) ||
				((int)count >= 86 && (int)count < 93) ||
				((int)count >= 99 && (int)count < 108) ||
				((int)count >= 111 && (int)count < 125) ||
				((int)count >= 129 && (int)count < 135) ||
				((int)count >= 141 && (int)count < 148) ||
				((int)count >= 166 && (int)count < 174) ||
				((int)count >= 179 && (int)count < 186) ||
				((int)count >= 191 && (int)count < 197))
				Char1->SetActive(true);
			else Char1->SetActive(false);

			if (((int)count >= 37 && (int)count < 51) ||
				(int)count == 56 ||
				(int)count == 68 ||
				((int)count >= 74 && (int)count < 85) ||
				((int)count >= 91 && (int)count < 93) ||
				((int)count >= 122 && (int)count < 125) ||
				((int)count >= 129 && (int)count < 131) ||
				((int)count >= 141 && (int)count < 143) ||
				((int)count >= 160 && (int)count < 166) ||
				(int)count == 173 ||
				((int)count >= 179 && (int)count < 181) ||
				((int)count >= 191 && (int)count < 193))
				Char2_1->SetActive(true);
			else Char2_1->SetActive(false);

			if (((int)count >= 37 && (int)count < 51) ||
				(int)count == 56 ||
				(int)count == 68 ||
				((int)count >= 74 && (int)count < 85) ||
				((int)count >= 91 && (int)count < 93) ||
				((int)count >= 122 && (int)count < 125) ||
				((int)count >= 129 && (int)count < 131) ||
				((int)count >= 141 && (int)count < 143) ||
				((int)count >= 160 && (int)count < 166) ||
				(int)count == 173 ||
				((int)count >= 179 && (int)count < 181) ||
				((int)count >= 191 && (int)count < 193))
				Char2_2->SetActive(true);
			else Char2_2->SetActive(false);

			if (((int)count >= 0 && (int)count < 13) ||
				((int)count >= 74 && (int)count < 86) ||
				((int)count >= 197 && (int)count < 210))
				Tail_->SetActive(true);
			else Tail_->SetActive(false);

			if (((int)count >= 18 && (int)count < 31) ||
				((int)count >= 49 && (int)count < 57) ||
				((int)count >= 61 && (int)count < 69) ||
				(int)count == 85 ||
				((int)count >= 91 && (int)count < 103) ||
				((int)count >= 108 && (int)count < 111) ||
				((int)count >= 122 && (int)count < 131) ||
				((int)count >= 135 && (int)count < 143) ||
				((int)count >= 149 && (int)count < 160) ||
				((int)count >= 173 && (int)count < 181) ||
				((int)count >= 186 && (int)count < 193))
				Char3->SetActive(true);
			else Char3->SetActive(false);

			break;
		}

		case 2:
		{
			if (((int)count >= 36 && (int)count < 45) ||
				((int)count >= 48 && (int)count < 52) ||
				((int)count >= 62 && (int)count < 65) ||
				((int)count >= 76 && (int)count < 90) ||
				((int)count >= 104 && (int)count < 108) ||
				((int)count >= 111 && (int)count < 118) ||
				((int)count >= 125 && (int)count < 129) ||
				((int)count >= 160 && (int)count < 177) ||
				((int)count >= 180 && (int)count < 184) ||
				((int)count >= 195 && (int)count < 198) ||
				((int)count >= 202 && (int)count < 214))
				Char1->SetActive(true);
			else Char1->SetActive(false);

			if (((int)count >= 28 && (int)count < 36) ||
				((int)count >= 41 && (int)count < 70) ||
				((int)count >= 91 && (int)count < 101) ||
				((int)count >= 104 && (int)count < 132) ||
				(int)count == 146 ||
				(int)count == 149 ||
				(int)count == 153 ||
				(int)count == 155 ||
				((int)count >= 174 && (int)count < 202) ||
				((int)count >= 214 && (int)count < 217))
				Char2_1->SetActive(true);
			else Char2_1->SetActive(false);

			if (((int)count >= 28 && (int)count < 36) ||
				((int)count >= 41 && (int)count < 70) ||
				((int)count >= 91 && (int)count < 101) ||
				((int)count >= 104 && (int)count < 132) ||
				(int)count == 146 ||
				(int)count == 149 ||
				(int)count == 153 ||
				(int)count == 155 ||
				((int)count >= 174 && (int)count < 202) ||
				((int)count >= 214 && (int)count < 217))
				Char2_2->SetActive(true);
			else Char2_2->SetActive(false);

			if (((int)count >= 0 && (int)count < 13) ||
				((int)count >= 70 && (int)count < 86) ||
				((int)count >= 217 && (int)count < 220))
				Tail_->SetActive(true);
			else Tail_->SetActive(false);

			if (((int)count >= 14 && (int)count < 28) ||
				((int)count >= 41 && (int)count < 45) ||
				((int)count >= 48 && (int)count < 52) ||
				((int)count >= 62 && (int)count < 65) ||
				((int)count >= 101 && (int)count < 108) ||
				((int)count >= 111 && (int)count < 118) ||
				((int)count >= 125 && (int)count < 129) ||
				((int)count >= 132 && (int)count < 160) ||
				((int)count >= 174 && (int)count < 177) ||
				((int)count >= 180 && (int)count < 184) ||
				((int)count >= 195 && (int)count < 198))
				Char3->SetActive(true);
			else Char3->SetActive(false);

			break;
		}

		case 3:
		{
			if (((int)count >= 0 && (int)count < 7) ||
				((int)count >= 30 && (int)count < 34) ||
				((int)count >= 37 && (int)count < 47) ||
				((int)count >= 52 && (int)count < 54) ||
				((int)count >= 57 && (int)count < 59) ||
				((int)count >= 62 && (int)count < 65) ||
				((int)count >= 72 && (int)count < 75) ||
				((int)count >= 76 && (int)count < 82) ||
				((int)count >= 91 && (int)count < 95) ||
				((int)count >= 108 && (int)count < 110) ||
				((int)count >= 122 && (int)count < 127) ||
				((int)count >= 129 && (int)count < 132) ||
				(int)count == 133 ||
				((int)count >= 135 && (int)count < 139) ||
				((int)count >= 147 && (int)count < 149) ||
				(int)count == 163 ||
				(int)count == 168 ||
				((int)count >= 175 && (int)count < 177))
				Char1->SetActive(true);
			else Char1->SetActive(false);

			if (((int)count >= 34 && (int)count < 37) ||
				((int)count >= 45 && (int)count < 47) ||
				((int)count >= 49 && (int)count < 52) ||
				((int)count >= 55 && (int)count < 57) ||
				((int)count >= 59 && (int)count < 61) ||
				((int)count >= 67 && (int)count < 69) ||
				((int)count >= 95 && (int)count < 104) ||
				((int)count >= 105 && (int)count < 107) ||
				((int)count >= 110 && (int)count < 113) ||
				((int)count >= 116 && (int)count < 118) ||
				((int)count >= 120 && (int)count < 122) ||
				((int)count >= 125 && (int)count < 129) ||
				(int)count == 151 ||
				((int)count >= 155 && (int)count < 157) ||
				((int)count >= 159 && (int)count < 162) ||
				((int)count >= 164 && (int)count < 166) ||
				((int)count >= 169 && (int)count < 171) ||
				((int)count >= 174 && (int)count < 176) ||
				((int)count >= 179 && (int)count < 181) ||
				((int)count >= 184 && (int)count < 188))
				Char2_1->SetActive(true);
			else Char2_1->SetActive(false);

			if (((int)count >= 34 && (int)count < 37) ||
				((int)count >= 45 && (int)count < 47) ||
				((int)count >= 49 && (int)count < 52) ||
				((int)count >= 55 && (int)count < 57) ||
				((int)count >= 59 && (int)count < 61) ||
				((int)count >= 67 && (int)count < 69) ||
				((int)count >= 95 && (int)count < 104) ||
				((int)count >= 105 && (int)count < 107) ||
				((int)count >= 110 && (int)count < 113) ||
				((int)count >= 116 && (int)count < 118) ||
				((int)count >= 120 && (int)count < 122) ||
				((int)count >= 125 && (int)count < 129) ||
				(int)count == 151 ||
				((int)count >= 155 && (int)count < 157) ||
				((int)count >= 159 && (int)count < 162) ||
				((int)count >= 164 && (int)count < 166) ||
				((int)count >= 169 && (int)count < 171) ||
				((int)count >= 174 && (int)count < 176) ||
				((int)count >= 179 && (int)count < 181) ||
				((int)count >= 184 && (int)count < 188))
				Char2_2->SetActive(true);
			else Char2_2->SetActive(false);

			if (((int)count >= 0 && (int)count < 49) ||
				((int)count >= 71 && (int)count < 110))
				Tail_->SetActive(true);
			else Tail_->SetActive(false);

			if (((int)count >= 10 && (int)count < 13) ||
				((int)count >= 15 && (int)count < 19) ||
				((int)count >= 20 && (int)count < 24) ||
				((int)count >= 25 && (int)count < 29) ||
				((int)count >= 47 && (int)count < 49) ||
				((int)count >= 59 && (int)count < 61) ||
				((int)count >= 64 && (int)count < 66) ||
				((int)count >= 82 && (int)count < 90) ||
				((int)count >= 95 && (int)count < 105) ||
				((int)count >= 114 && (int)count < 116) ||
				(int)count == 119 ||
				(int)count == 132 ||
				(int)count == 134 ||
				((int)count >= 139 && (int)count < 150) ||
				(int)count == 153 ||
				((int)count >= 157 && (int)count < 159) ||
				((int)count >= 172 && (int)count < 174) ||
				(int)count == 178 ||
				(int)count == 182)
				Char3->SetActive(true);
			else Char3->SetActive(false);

			break;
		}

		case 4:
		{
			if (((int)count >= 2 && (int)count < 14) ||
				((int)count >= 21 && (int)count < 29) ||
				((int)count >= 53 && (int)count < 58) ||
				((int)count >= 60 && (int)count < 71) ||
				((int)count >= 89 && (int)count < 92) ||
				((int)count >= 130 && (int)count < 149) ||
				((int)count >= 157 && (int)count < 169) ||
				((int)count >= 178 && (int)count < 194))
				Char1->SetActive(true);
			else Char1->SetActive(false);

			if (((int)count >= 29 && (int)count < 34) ||
				((int)count >= 40 && (int)count < 47) ||
				((int)count >= 71 && (int)count < 80) ||
				((int)count >= 104 && (int)count < 111) ||
				((int)count >= 117 && (int)count < 123) ||
				((int)count >= 149 && (int)count < 157) ||
				((int)count >= 200 && (int)count < 207) ||
				((int)count >= 209 && (int)count < 211) ||
				((int)count >= 213 && (int)count < 219))
				Char2_1->SetActive(true);
			else Char2_1->SetActive(false);

			if (((int)count >= 29 && (int)count < 34) ||
				((int)count >= 40 && (int)count < 47) ||
				((int)count >= 71 && (int)count < 80) ||
				((int)count >= 104 && (int)count < 111) ||
				((int)count >= 117 && (int)count < 123) ||
				((int)count >= 149 && (int)count < 157) ||
				((int)count >= 200 && (int)count < 207) ||
				((int)count >= 209 && (int)count < 211) ||
				((int)count >= 213 && (int)count < 219))
				Char2_2->SetActive(true);
			else Char2_2->SetActive(false);

			if (((int)count >= 28 && (int)count < 53) ||
				((int)count >= 104 && (int)count < 130) ||
				((int)count >= 181 && (int)count < 207))
				Tail_->SetActive(true);
			else Tail_->SetActive(false);

			if (((int)count >= 15 && (int)count < 21) ||
				((int)count >= 34 && (int)count < 40) ||
				((int)count >= 47 && (int)count < 53) ||
				((int)count >= 80 && (int)count < 89) ||
				((int)count >= 92 && (int)count < 104) ||
				((int)count >= 111 && (int)count < 117) ||
				((int)count >= 123 && (int)count < 130) ||
				((int)count >= 169 && (int)count < 181) ||
				((int)count >= 194 && (int)count < 200))
				Char3->SetActive(true);
			else Char3->SetActive(false);

			break;
		}
		}
		AnimationType(Sound.GetCurrentSongID());
	}
}

void MusicStop() {
	int the6ThButton;
	if (Sound.GetCurrentState() == 1) {
		switch (Sound.GetCurrentSongID()) {
		case 0:
			if ((int)count > 240) {
				count = 0;
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				Sound.ChangeCurrentSong(Sound.GetCurrentSongID() + 1);
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
			}
			break;
		case 1:
			if ((int)count > 215) {
				count = 0;
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				Sound.ChangeCurrentSong(Sound.GetCurrentSongID() + 1);
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
			}
			break;
		case 2:
			if ((int)count > 237) {
				count = 0;
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				Sound.ChangeCurrentSong(Sound.GetCurrentSongID() + 1);
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
			}
			break;
		case 3:
			if ((int)count > 195) {
				count = 0;
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				Sound.ChangeCurrentSong(Sound.GetCurrentSongID() + 1);
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
			}
			break;
		case 4:
			if ((int)count > 240) {
				count = 0;
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				Sound.ChangeCurrentSong(0);
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
			}
			break;
		case 5:
			if ((int)count > 45) {
				count = 0;
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
			}
			break;
		case 6:
			if ((int)count > 54) {
				count = 0;
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
			}
			break;
		}
		AnimationType(Sound.GetCurrentSongID());
	}
}
void AnimationType(int Type) {
	if (Type > 4) {
		Char1->SetActive(false);
		Char2_1->SetActive(false);
		Char3->SetActive(false);
		Tail_->SetActive(false);
		subStar->SetActive(false);
		isPause = true;
	}
	else
		isPause = false;
}
void BtnStart() {
	if (isStart) 
		currentState = INGAME;
	
	else 
		currentState = MAIN;
	Sound.ChangeCurrentState(0);
	Sound.SongStateSet();
	AnimationType();
	count = 0;
	isStart = !isStart;
	sndPlaySound("Sound\\Click.wav", SND_ASYNC);
	printf("S");
}

void BtnSong1() {
	if (Sound.GetCurrentSongID() != 0) {
		if (Sound.GetCurrentState() == 1) {
			Sound.ChangeCurrentState(0);
			Sound.SongStateSet();
		}
		Sound.ChangeCurrentSong(0);
		Sound.ChangeCurrentState(1);
		Sound.SongStateSet();
		printf("1");
		count = 0;
		AnimationType(0);
	}
}
void BtnSong2() {
	if (Sound.GetCurrentSongID() != 1) {
		if (Sound.GetCurrentState() == 1) {
			Sound.ChangeCurrentState(0);
			Sound.SongStateSet();
		}

		Sound.ChangeCurrentSong(1);
		Sound.ChangeCurrentState(1);
		Sound.SongStateSet();
		printf("2");
		count = 0;
		AnimationType(1);
	}
}
void BtnSong3() {
	if (Sound.GetCurrentSongID() != 2) {
		if (Sound.GetCurrentState() == 1) {
			Sound.ChangeCurrentState(0);
			Sound.SongStateSet();
		}

		Sound.ChangeCurrentSong(2);
		Sound.ChangeCurrentState(1);
		Sound.SongStateSet();
		printf("3");
		count = 0;
		AnimationType(2);
	}
}
void BtnSong4() {
	if (Sound.GetCurrentSongID() != 3) {
		if (Sound.GetCurrentState() == 1) {
			Sound.ChangeCurrentState(0);
			Sound.SongStateSet();
		}

		Sound.ChangeCurrentSong(3);
		Sound.ChangeCurrentState(1);
		Sound.SongStateSet();
		printf("4");
		count = 0;
		AnimationType(3);
	}
}
void BtnSong5() {
	if (Sound.GetCurrentSongID() != 4) {
		if (Sound.GetCurrentState() == 1) {
			Sound.ChangeCurrentState(0);
			Sound.SongStateSet();
		}

		Sound.ChangeCurrentSong(4);
		Sound.ChangeCurrentState(1);
		Sound.SongStateSet();
		printf("5");
		count = 0;
		AnimationType(4);
	}
}

void BtnCredit() {
	currentState = CREDIT;
	sndPlaySound("Sound\\Click.wav", SND_ASYNC);
	AnimationType();
	printf("C");
}
void BtnHowto() {
	currentState = HOWTO;
	sndPlaySound("Sound\\Click.wav", SND_ASYNC);
	AnimationType();
	printf("H");
}
void BtnExit() {
	AnimationType();
	sndPlaySound("Sound\\Click.wav", SND_ASYNC);
	gameQuit = true;
}

void BtnMain() {
	if (currentState != CREDIT) {
		if (Sound.GetCurrentState() < 5)
			SongBtn[Sound.GetCurrentState()]->ResetOnUp();
		count = 0;
	}
	currentState = MAIN;
	AnimationType();
	sndPlaySound("Sound\\Click.wav", SND_ASYNC);
	printf("M");
}

void BtnPause() {
	if (!isPause) {
		Sound.ChangeCurrentState(2);
		Sound.SongStateSet();
		AnimationType();
		sndPlaySound("Sound\\Click.wav", SND_ASYNC);
		printf("II");
	}
}

void BtnPlay() {
	if (isPause && Sound.GetCurrentSongID() < 5) {
		Sound.ChangeCurrentState(1);
		Sound.SongStateSet();
		AnimationType(Sound.GetCurrentSongID());
		printf("II");
	}
}

void FishButton_() {
	if (Sound.GetCurrentSongID() != 5) {
		currentState = Secret;
		if (Sound.GetCurrentState() == 1) {
			Sound.ChangeCurrentState(0);
			Sound.SongStateSet();
		}

		Sound.ChangeCurrentSong(5);
		Sound.ChangeCurrentState(1);
		Sound.SongStateSet();
		printf("6");
		count = 0;
		sndPlaySound("Sound\\Click.wav", SND_ASYNC);
		Sound.GetCurrentSongID();
	}
}

void Back1() {
		currentState = HOWTO_2;
}
void Back2() {
	currentState = HOWTO_3;
}
void Back3() {
	currentState = INGAME;
}

bool CSystem::Initialize()
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	m_pInputManager = new CInputManager;
	m_pInputManager->SetInputHandler(this);
	//===============================
	//오브젝트 초기화 코드
	BG =								new Background(m_pRender);

	StartBtn =					new Button(m_pRender, "Image\\playButton_Normal.png",	"Image\\playButton_Down.png",	"Image\\playButton_Over.png",	170,		474,	BtnStart);
	HowtoBtn =				new Button(m_pRender, "Image\\HowTo.png",							"Image\\HowTo_Down.png",			"Image\\HowTo_Over.png",				84,		174,	BtnHowto);
	ExitBtn =					new Button(m_pRender, "Image\\exitButton_Normal.png",		"Image\\exitButton_Down.png",	"Image\\exitButton_Over.png",		1000,	512,	BtnExit);
	CreditBtn =				new Button(m_pRender, "Image\\credit.png",							"Image\\credit_down.png",				"Image\\credit_over.png",				1065,	171,	BtnCredit);
	MainBtn =					new Button(m_pRender, "Image\\mainButton_Normal.png",	"Image\\mainButton_Down.png",	"Image\\mainButton_Over.png",	0,			0,		BtnMain);
	PauseBtn =					new Button(m_pRender, "Image\\pause.png",							"Image\\pause_Down.png",				"Image\\pause_over.png",				961,		164,	BtnPause);
	PlayBtn =					new Button(m_pRender, "Image\\play.png",								"Image\\play_Down.png",				"Image\\play_over.png",					948,		148,	BtnPlay);
	SongBtn[0] =				new Button(m_pRender, "Image\\Song1.png",							"Image\\Song1_D.png",						NULL,														797,		236,	BtnSong1);
	SongBtn[1] =				new Button(m_pRender, "Image\\Song2.png",							"Image\\Song2_D.png"	,					NULL,														797,		272,	BtnSong2);
	SongBtn[2] =				new Button(m_pRender, "Image\\Song3.png",							"Image\\Song3_D.png"	,					NULL,														797,		309,	BtnSong3);
	SongBtn[3] =				new Button(m_pRender, "Image\\Song4.png",							"Image\\Song4_D.png"	,					NULL,														797,		347,	BtnSong4);
	SongBtn[4] =				new Button(m_pRender, "Image\\Song5.png",							"Image\\Song5_D.png"	,					NULL,														797,		383,	BtnSong5);
	HowToButton[0] =	new Button(m_pRender, "Image\\howto1.png",							"Image\\howto1.png",						NULL,														0,			0,		Back1);
	HowToButton[1] =		new Button(m_pRender, "Image\\howto2.png",							"Image\\howto2.png",						NULL,														0,			0,		Back2);
	HowToButton[2] =	new Button(m_pRender, "Image\\howto3.png",							"Image\\howto3.png",						NULL,														0,			0,		Back3);

	Fish =							new FishButton(m_pRender , FishButton_);
	
	//CAnimation* AnimationList[5] = { Char1, Char2, Char3, Tail_ };
	//AnimationMamager = new CAnim(AnimationList);

	Star =							new Image(m_pRender, "Image\\Star.png",						 823,221);
	Cloud =						new Image(m_pRender, "Image\\Cloud.png",					 0,	0);
	Song[0] =					new Image(m_pRender, "Image\\Song1_D.png",				 797,	236);
	Song[1] =						new Image(m_pRender, "Image\\Song2_D.png",				 797,	272);
	Song[2] =					new Image(m_pRender, "Image\\Song3_D.png",				 797,	309);
	Song[3] =					new Image(m_pRender, "Image\\Song4_D.png",				 797,	347);
	Song[4] =					new Image(m_pRender, "Image\\Song5_D.png",				 797,	383);
	Char3_Base =				new Image(m_pRender, "Image\\Char3_\\Base.png", 549, 216);

	MovingSea =				new MovingAnimation(m_pRender, 3,	5,	0,		0,		"Image\\MovingSea.png");
	MovingStar =				new MovingAnimation(m_pRender, 0,	0,	0,		0,		"Image\\MovingStar.png");
	MovingMermaid =		new MovingAnimation(m_pRender, -1,	2,	135,	445, "Image\\Mermaid.png");

	int mainStar_[2]	= {	25,		25																	};
	int BGAnim_[3]		= {	20,		50,		35													};
	int Tail1_[4]			= {	25,		25,		25,		25	 										};
	int Char_[7]			= {	10,		10,		10,		10,		10,		10,		10		};
	int subStar_[3]		= {	25,		25,		25														};

	BGAnim =					new CAnimation(m_pRender, 3, 	BGAnim_	,	"Image\\Sea",					0,			0			);
	mainStar =					new CAnimation(m_pRender, 2, 	mainStar_,	"Image\\mainLight",		612,		218		);
	Char1 =						new CAnimation(m_pRender, 7, 	Char_,			"Image\\Char1_",			18,		237		);
	Char2_1 =					new CAnimation(m_pRender, 6, 	Char_,			"Image\\Char2_1",			268,		223		);
	Char2_2 =					new CAnimation(m_pRender, 6,		Char_,			"Image\\Char2_2",			432,		228		);
	Char3 =						new CAnimation(m_pRender, 7, 	Char_,			"Image\\Char3_",			549,		216		);
	Tail_ =							new CAnimation(m_pRender, 4, 	Tail1_,			"Image\\Tail1_",				475,		500		);
	subStar =					new CAnimation(m_pRender, 3,		subStar_,	"Image\\subStar_",		856,		82		);

	Sound.AddSong("Sound\\1.mp3");
	Sound.AddSong("Sound\\2.mp3");
	Sound.AddSong("Sound\\3.mp3");
	Sound.AddSong("Sound\\4.mp3");
	Sound.AddSong("Sound\\5.mp3"); 
	Sound.AddSong("Sound\\6.mp3");
	Sound.AddSong("Sound\\7.mp3");	
	Sound.AddSong("Sound\\1.mp3");

	Char1		->SetActive(false);
	Char2_1	->SetActive(false);
	Char2_2	->SetActive(false);
	Char3		->SetActive(false);
	Tail_		->SetActive(false);

	//===============================
	return true;
}


void CSystem::Pulse()
{
	CTimeManager::Pulse();

	m_pInputManager->Pulse();
	float fTimeStep = CTimeManager::GetTimeStep();
	static int tick = 0;
	static float fAccTime = 0.0f;
	count += fTimeStep;

	if (m_pGameFrame->Update(fTimeStep))
	{
		SDL_SetRenderDrawColor(m_pRender, MIN8, MIN8, MAX8, MAX8);
		SDL_RenderClear(m_pRender);
		tick++;
		if (Sound.GetCurrentState() == 1) {
			Climax();
			MusicStop();
		}
		//===============================
		//오브젝트 프로세스 코드 
		switch (currentState) {
		case MAIN:
			if (isMainFirst) {
				if (Sound.GetCurrentState() == 1) {
					Sound.ChangeCurrentState(0);
					Sound.SongStateSet();
				}
				Sound.ChangeCurrentSong(6);
				Sound.ChangeCurrentState(1);
				Sound.SongStateSet();
				count = 0;
				isMainFirst = !isMainFirst;
				isSecretFirst = !isSecretFirst;
			}
			BG->ChangeBackground(0);
			StartBtn->SetVisible(true);
			CreditBtn->SetVisible(true);
			MainBtn->SetVisible(false);
			PauseBtn->SetVisible(false);
			PlayBtn->SetVisible(false);
			ExitBtn->SetVisible(true);
			HowtoBtn->SetVisible(true);
			BGAnim->SetVisible(false);
			mainStar->SetVisible(true);
			Char1->SetVisible(false);
			Char2_1->SetVisible(false);
			Char2_2->SetVisible(false);
			Char3->SetVisible(false);
			Tail_->SetVisible(false);
			subStar->SetVisible(false);
			MovingSea->SetVisible(false);
			MovingStar->SetVisible(false);
			MovingMermaid->SetVisible(false);
			Fish->SetVisible(false);
			for (int i = 0; i < 5; i++)
				SongBtn[i]->SetVisible(false);
			for (int i = 0; i < 3; i++)
				HowToButton[i]->SetVisible(false);
			break;
		case INGAME:
			if (!isMainFirst) {
				Sound.ChangeCurrentState(0);
				Sound.SongStateSet();
				isMainFirst = !isMainFirst;
			}
			BG->ChangeBackground(1);
			StartBtn->SetVisible(false);
			CreditBtn->SetVisible(false);
			MainBtn->SetVisible(true);
			if (!isPause) {
				PauseBtn->SetVisible(true);
				PlayBtn->SetVisible(false);
				subStar->SetActive(true);
			}
			else {
				PauseBtn->SetVisible(false);
				PlayBtn->SetVisible(true);
				subStar->SetActive(false);
			}
			ExitBtn->SetVisible(false);
			HowtoBtn->SetVisible(false);
			BGAnim->SetVisible(true);
			mainStar->SetVisible(false);
			Char2_1->SetVisible(true);
			Char1->SetVisible(true);
			Char2_2->SetVisible(true);
			Char3->SetVisible(true);
			Tail_->SetVisible(true);
			Fish->SetVisible(true);
			MovingSea->SetVisible(false);
			MovingStar->SetVisible(false);
			MovingMermaid->SetVisible(false);
			subStar->SetVisible(true);
			for (int i = 0; i < 5; i++) {
				if (Sound.GetCurrentSongID() == i)
					SongBtn[i]->SetVisible(false);
				else
					SongBtn[i]->SetVisible(true);
			}
			for (int i = 0; i < 3; i++)
				HowToButton[i]->SetVisible(false);
			
			
			break;
		case CREDIT:
			BG->ChangeBackground(2);
			StartBtn->SetVisible(false);
			CreditBtn->SetVisible(false);
			MainBtn->SetVisible(true);
			PauseBtn->SetVisible(false);
			PlayBtn->SetVisible(false);
			ExitBtn->SetVisible(false);
			HowtoBtn->SetVisible(false);
			BGAnim->SetVisible(false);
			mainStar->SetVisible(false);
			Char1->SetVisible(false);
			Char2_1->SetVisible(false);
			Char2_2->SetVisible(false);
			Char3->SetVisible(false);
			Tail_->SetVisible(false);
			subStar->SetVisible(false);
			Fish->SetVisible(false);
			MovingSea->SetVisible(true);
			MovingMermaid->SetVisible(true);
			if (tick % 75 == 0)
				MovingStar->SetVisible(!(MovingStar->GetVisible()));
			for (int i = 0; i < 5; i++)
				SongBtn[i]->SetVisible(false);
			for (int i = 0; i < 3; i++)
				HowToButton[i]->SetVisible(false);
			break;
		case HOWTO:

			StartBtn->SetVisible(false);
			CreditBtn->SetVisible(false);
			MainBtn->SetVisible(false);
			PlayBtn->SetVisible(false);
			PauseBtn->SetVisible(false);
			ExitBtn->SetVisible(false);
			HowtoBtn->SetVisible(false);
			BGAnim->SetVisible(false);
			mainStar->SetVisible(false);
			Char1->SetVisible(false);
			Char2_1->SetVisible(false);
			Char2_2->SetVisible(false);
			Char3->SetVisible(false);
			Tail_->SetVisible(false);
			Fish->SetVisible(false);
			subStar->SetVisible(false);
			MovingSea->SetVisible(false);
			MovingStar->SetVisible(false);
			MovingMermaid->SetVisible(false);
			for (int i = 0; i < 5; i++)
				SongBtn[i]->SetVisible(false);
			HowToButton[0]->SetVisible(true);
			HowToButton[1]->SetVisible(false);
			HowToButton[2]->SetVisible(false);
			break;
		case HOWTO_2:
			HowToButton[0]->SetVisible(false);
			HowToButton[1]->SetVisible(true);
			HowToButton[2]->SetVisible(false);
			break;
		case HOWTO_3:
			HowToButton[0]->SetVisible(false);
			HowToButton[1]->SetVisible(false);
			HowToButton[2]->SetVisible(true);
			break;
		case Secret:
			if (isSecretFirst) {
				isSecretFirst = !isSecretFirst;
				BG->ChangeBackground(3);
			}
			if (tick++ % (35 + rand() % 10) == 0) {
				static bool isChanged = false;
				BG->ChangeBackground(3 + isChanged);
				isChanged = !isChanged;
			}
			StartBtn->SetVisible(false);
			CreditBtn->SetVisible(false);
			MainBtn->SetVisible(false);
			PauseBtn->SetVisible(false);
			ExitBtn->SetVisible(false);
			HowtoBtn->SetVisible(false);
			BGAnim->SetVisible(false);
			PlayBtn->SetVisible(false);
			mainStar->SetVisible(false);
			Char1->SetVisible(false);
			Char2_1->SetVisible(false);
			Char2_2->SetVisible(false);
			Char3->SetVisible(false);
			Tail_->SetVisible(false);
			Fish->SetVisible(false);
			MovingSea->SetVisible(false);
			MovingStar->SetVisible(false);
			MovingMermaid->SetVisible(false);
			subStar->SetVisible(false);
			for (int i = 0; i < 5; i++)
				SongBtn[i]->SetVisible(false);
			for (int i = 0; i < 3; i++)
				HowToButton[i]->SetVisible(false);
			break;
		}

		BG->DisplayBackground(m_pRender);
		for (int i = 0; i < 3; i++)
			HowToButton[i]->Draw(m_pRender);
		StartBtn->Draw(m_pRender);
		CreditBtn->Draw(m_pRender);
		PlayBtn->Draw(m_pRender);
		PauseBtn->Draw(m_pRender);
		HowtoBtn->Draw(m_pRender);
		ExitBtn->Draw(m_pRender);
		Fish->DrawFish(m_pRender);
		BGAnim->Update(m_pRender);
		mainStar->Update(m_pRender);
		if (currentState == INGAME)
			Char3_Base->DrawImg(m_pRender);
		Char2_2->Update(m_pRender);
		Char2_1->Update(m_pRender);
		Char3->Update(m_pRender);
		Char1->Update(m_pRender);
		Tail_->Update(m_pRender);
		MovingStar->DrawMovingAnimation(m_pRender);
		MovingMermaid->DrawMovingAnimation(m_pRender);
		MovingSea->DrawMovingAnimation(m_pRender);
		subStar->Update(m_pRender);
		for (int i = 0; i < 5; i++)
			SongBtn[i]->Draw(m_pRender);
		if (tick % 10 == 0 && currentState == CREDIT) {
			MovingStar->MoveImg();
			MovingMermaid->MoveImg();
			MovingSea->MoveImg();
			printf("!\n");
		}
		if (currentState == INGAME) {
			switch (Sound.GetCurrentSongID()) {
			case 0:
				Star->ChangeRect(823, 221);
				break;
			case 1:
				Star->ChangeRect(832, 256);
				break;
			case 2:
				Star->ChangeRect(782, 291);
				break;
			case 3:
				Star->ChangeRect(833, 329);
				break;
			case 4:
				Star->ChangeRect(826, 366);
				break;
			}
		}
		if (Sound.GetCurrentSongID() < 5) {
			Song[Sound.GetCurrentSongID()]->DrawImg(m_pRender);
			Star->DrawImg(m_pRender);
		}
		if (currentState == CREDIT)
			Cloud->DrawImg(m_pRender);
		MainBtn->Draw(m_pRender);
		//===============================
		SDL_RenderPresent(m_pRender);
	}
}

void CSystem::Terminate()
{
	//===============================
	//오브젝트 종료/해제코드
	StartBtn						->Release();
	CreditBtn					->Release();
	MainBtn						->Release();
	PauseBtn					->Release();
	HowtoBtn					->Release();
	ExitBtn						->Release();
	PlayBtn						->Release();
	MovingSea					->Release();
	MovingStar				->Release();
	MovingMermaid		->Release();
	Fish								->Release();
	BGAnim						->Release();
	Char1							->Release();
	Char2_1						->Release();
	Char2_2						->Release();
	Char3							->Release();
	Tail_							->Release();
	mainStar						->Release();
	subStar						->Release();
	BG								->Release();
	Star								->Release();
	Cloud							->Release();
	for (int i = 0; i < 3; i++)
		HowToButton[i]	->Release();
	for (int i = 0; i < 5; i++)
		SongBtn[i]				->Release();
	for (int i = 0; i < 5; i++)
		Song[i]					->Release();
	//===============================
	m_pInputManager->Terminate();

	CBaseWindow::Terminate();
	CTimeManager::Terminate();
}

void CSystem::Run()
{	
	while (m_bIsGameRun)
	{
		Pulse(); //Update()
		if (gameQuit) break;
	}
}

#define g_pKeyCodeScan(vk) (m_pInputManager->GetOldKeyState(vk)&&m_pInputManager->GetCurKeyState(vk))

void CSystem::KeyboardHandler()
{

}

void CSystem::MouseHandler(SDL_Event evnt, MOUSESTATE mouseState)
{
	if (evnt.type == SDL_QUIT)	m_bIsGameRun = SDL_FALSE;
	if (evnt.key.keysym.sym == SDLK_ESCAPE)	 m_bIsGameRun = SDL_FALSE;
	if (evnt.type == SDL_MOUSEBUTTONDOWN) {
		if (currentState == Secret) currentState = MAIN;
		if (mouseState.btn[MouseButton::LEFT]) {
			StartBtn->						MouseDown(mouseState.x, mouseState.y);
			CreditBtn->					MouseDown(mouseState.x, mouseState.y);
			MainBtn->						MouseDown(mouseState.x, mouseState.y);
			PauseBtn->					MouseDown(mouseState.x, mouseState.y);
			PlayBtn->						MouseDown(mouseState.x, mouseState.y);
			ExitBtn->						MouseDown(mouseState.x, mouseState.y);
			HowtoBtn->					MouseDown(mouseState.x, mouseState.y);
			for (int i = 0; i < 5; i++)
				SongBtn[i]->				MouseDown(mouseState.x, mouseState.y);
			for (int i = 0; i < 3; i++)
				HowToButton[i]->	MouseDown(mouseState.x, mouseState.y);
		}
	}
	
	if (evnt.type == SDL_MOUSEBUTTONUP) {
		if (mouseState.btn[MouseButton::LEFT]) {
			StartBtn->						MouseUp(mouseState.x, mouseState.y);
			CreditBtn->					MouseUp(mouseState.x, mouseState.y);
			MainBtn->						MouseUp(mouseState.x, mouseState.y);
			PauseBtn->					MouseUp(mouseState.x, mouseState.y);
			PlayBtn->						MouseUp(mouseState.x, mouseState.y);
			ExitBtn->						MouseUp(mouseState.x, mouseState.y);
			HowtoBtn->					MouseUp(mouseState.x, mouseState.y);
			Fish->								MouseUp(mouseState.x, mouseState.y, currentState);
			for (int i = 0; i < 5; i++)
				SongBtn[i]->				MouseUp(mouseState.x, mouseState.y);
			for (int i = 0; i < 3; i++)
				HowToButton[i]->	MouseUp(mouseState.x, mouseState.y);
		}
	}

	if (evnt.type == SDL_MOUSEMOTION) {
		StartBtn->							MouseOver(mouseState.x, mouseState.y);
		CreditBtn->						MouseOver(mouseState.x, mouseState.y);
		MainBtn->							MouseOver(mouseState.x, mouseState.y);
		PauseBtn->						MouseOver(mouseState.x, mouseState.y);
		PlayBtn->							MouseOver(mouseState.x, mouseState.y);
		ExitBtn->							MouseOver(mouseState.x, mouseState.y);
		HowtoBtn->						MouseOver(mouseState.x, mouseState.y);
		Fish->									MouseOver(mouseState.x, mouseState.y);
		for (int i = 0; i < 5; i++)
			SongBtn[i]->					MouseOver(mouseState.x, mouseState.y);
		for (int i = 0; i < 3; i++)
			HowToButton[i]->		MouseOver(mouseState.x, mouseState.y);
	}
}