// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>
#include "Engine/Engine.h"
/**
 * 
 */
class MYBTTEST_API CReadFileStreamUtil
{
public:

	enum ENUM_ENDIAN_MODE_BATTLE{
		ENUM_ENDIAN_MODE_BIG = 0,		//大端模式
		ENUM_ENDIAN_MODE_LITTLE			//小端模式
	};

	CReadFileStreamUtil();
	~CReadFileStreamUtil();

	bool readFileStream(FString filePath, ENUM_ENDIAN_MODE_BATTLE endianMode = ENUM_ENDIAN_MODE_BIG);
	void drop();

private:
	ENUM_ENDIAN_MODE_BATTLE m_endianMode;
	int m_iOffset;
	unsigned char* m_Data;
};
