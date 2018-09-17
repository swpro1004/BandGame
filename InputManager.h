#pragma once
class IInputHandler;

class CInputManager
{
private:
	IInputHandler* m_pCurInputHandler;
	SDL_bool m_OldKeyState[256];
	SDL_bool m_CurKeyState[256];
	MOUSESTATE m_MouseState;

public:
	CInputManager(void);
	~CInputManager(void);

private:
	void Keyboard();
	void Mouse();

public:
	bool Initialize();
	void Terminate();
	void Pulse();

public:
	inline void SetInputHandler(IInputHandler* pInputHandler);
	inline IInputHandler* GetInputHandler() const;
	inline SDL_bool GetOldKeyState(int nKey);
	inline SDL_bool GetCurKeyState(int nKey);
};


inline void CInputManager::SetInputHandler(IInputHandler* pInputHandler)
{
	m_pCurInputHandler = pInputHandler;
}

inline IInputHandler* CInputManager::GetInputHandler() const
{
	return m_pCurInputHandler;
}

inline SDL_bool CInputManager::GetOldKeyState(int nKey)
{
	return m_OldKeyState[nKey];
}

inline SDL_bool CInputManager::GetCurKeyState(int nKey)
{
	return m_CurKeyState[nKey];
}