#include "stdafx.h"


CFrameSkip::CFrameSkip()
{
	SetFramePerSec(60.0f);
}


CFrameSkip::~CFrameSkip()
{
}

void CFrameSkip::SetFramePerSec(float fps)
{
	m_fTimer = 0.0f;
	m_fFPS = 0.0f;
	m_fAcculTime = 0.0f;
	m_nFrameCount = 0;
	m_fLimitFPS = fps;
	m_fSecPerFrame = 1.0f / fps;
}

// ���ϴ� �����Ӻ��� �ʹ� ������, 
// false�� ��ȯ�ؼ� �ڵ带 ���۽�Ű�� �ʵ��� �Ѵ�. 
// dt�� '��'���� (�и��� �ƴ�!!!) 
bool CFrameSkip::Update(float dt)
{
	m_fTimer += dt;
	m_fAcculTime += dt;

	if (m_fTimer < 0)
	{
		if ((float)m_nFrameCount / m_fAcculTime != 0.0f)
		{
			m_fFPS = (float)m_nFrameCount / m_fAcculTime;
			m_fAcculTime = 0;
			m_nFrameCount = 0;
		}
		return false;
	}

	// �������ӿ� �ش��ϴ� �ð��� ����. 
	m_fTimer -= m_fSecPerFrame;
	m_nFrameCount += 1;

	return true;
}

// Update�Ŀ� ȣ���ؼ� frame skip�� �����ؾ� �ϴ��� �˻��Ѵ�. 
// frame skip�� �Ͼ�� �Ѵٸ� true�� ��ȯ�Ѵ�. 
bool CFrameSkip::IsFrameSkip()
{
	return (m_fTimer >= 0);
}
