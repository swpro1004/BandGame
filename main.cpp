#include "stdafx.h"

int main(int argc, char* argv[])
{
	CSystem* pSystem = new CSystem;	//�޸� �Ҵ�, ��ü ����

	pSystem->Initialize();	//pSyetem�ʱ�ȭ

	pSystem->Run();			//pSyetem����

	pSystem->Terminate();	//pSyetem����

	delete pSystem;	//��ü ����, �޸� ����

	return 0;
}

