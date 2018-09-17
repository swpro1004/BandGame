#include "stdafx.h"

int main(int argc, char* argv[])
{
	CSystem* pSystem = new CSystem;	//메모리 할당, 객체 생성

	pSystem->Initialize();	//pSyetem초기화

	pSystem->Run();			//pSyetem실행

	pSystem->Terminate();	//pSyetem종룍

	delete pSystem;	//객체 삭제, 메모리 정리

	return 0;
}

