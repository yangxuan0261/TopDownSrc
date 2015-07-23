// Fill out your copyright notice in the Description page of Project Settings.

#ifndef __CREAD_FILE_STREAM_UTIL__
#define __CREAD_FILE_STREAM_UTIL__ 

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

	bool readFileStream(FString filePath, ENUM_ENDIAN_MODE_BATTLE endianMode = ENUM_ENDIAN_MODE_LITTLE);
	void drop();

	inline bool readBool(){ return readInt8() != 0; }
	inline int32 readInt32(){ return read<int32>(); }
	inline int16 readInt16(){ return read<int16>(); }
	inline int8 readInt8(){ return read<int8>(); }
	inline uint32 readUnsignedInt(){ return read<uint32>(); }
	inline std::string readString()
	{
		static char buffer[65535];
		memset(buffer, 0x0, 65535);
		uint32 len = readUnsignedInt();

		read((unsigned char*)buffer, len);

		std::string str(buffer);
		return str;
	}
private:
	template <typename T> T read()
	{
		T value;
		readData(&value, sizeof(value));
		return value;
	}

	void readData(void* data, unsigned int sizeToRead);
	virtual int32 read(unsigned char* buffer, uint32 sizeToRead);

private:
	ENUM_ENDIAN_MODE_BATTLE m_endianMode;
	int m_iOffset;
	unsigned char* m_Data;
	void* tmp;

};

#endif __CREAD_FILE_STREAM_UTIL__

