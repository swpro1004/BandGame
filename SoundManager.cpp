#include "stdafx.h"

SoundManager::SoundManager()
{
	cmdType = 0;
	currentSong = 6;
	songMaxIndex = 0;
	songList = new const char*;
}

void SoundManager::AddSong(const char * songDir)
{
	songList[songMaxIndex++] = songDir;
}

void SoundManager::SongStateSet()
{
	char result[128] = "";
	strcat(result, (char*)state[cmdType]); // 재생, 일시정지, 정지
	strcat(result, (char*)songList[currentSong]); // 재생할 곡 (경로 및 파일 명)
	printf("%d\n", mciSendString(result, NULL, 0, NULL));
}

void SoundManager::ChangeCurrentSong(int SongID)
{
	ChangeCurrentState(0);
	SongStateSet();
	currentSong = SongID;
}

void SoundManager::ChangeCurrentState(int StateID)
{
	cmdType = StateID;
}

int SoundManager::GetCurrentSongID() {
	return currentSong;
}

int SoundManager::GetCurrentState()
{
	return cmdType;
}

int SoundManager::GetCurrentMaxIndex() {
	return songMaxIndex - 1;
}

void SoundManager::Release()
{
	delete songList;
}

SoundManager::~SoundManager()
{
}
