// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "CReadFileStreamUtil.h"

CReadFileStreamUtil::CReadFileStreamUtil()
{
}

CReadFileStreamUtil::~CReadFileStreamUtil()
{
}

bool CReadFileStreamUtil::readFileStream(FString filePath, ENUM_ENDIAN_MODE_BATTLE endianMode)
{
	TUniquePtr<FArchive> FileReader(IFileManager::Get().CreateFileReader(*filePath));
	if (!FileReader)
	{
		FString errorMsg = FString::Printf(TEXT("errorMsg - readFileStream path : %s"), *filePath);
		GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Red, errorMsg);
		return false;
	}
	return true;
}

void CReadFileStreamUtil::drop()
{
	delete this;
}