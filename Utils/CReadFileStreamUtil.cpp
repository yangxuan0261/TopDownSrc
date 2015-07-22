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

	m_endianMode = endianMode;
	m_iOffset = 0;

	// Create buffer for file input
	uint32 BufferSize = FileReader->TotalSize();
	m_Data = (unsigned char*)FMemory::Malloc(BufferSize);
	//void* Buffer = FMemory::Malloc(BufferSize);
	FileReader->Serialize(m_Data, BufferSize);

	/*FString errorMsg = FString::Printf(TEXT("buff size : %d"), BufferSize);
	GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Yellow, errorMsg);*/

	return true;
}

void CReadFileStreamUtil::drop()
{
	delete this;
}

void CReadFileStreamUtil::readData(void* data, unsigned int sizeToRead)
{

	if (m_endianMode == ENUM_ENDIAN_MODE_LITTLE){
		//m_Data.copy((unsigned char*)data, sizeToRead);
		memcpy(data, m_Data + m_iOffset, sizeToRead);
	}
	else
	{
		unsigned char* data_ = m_Data;
		for (uint32 i = 0; i < sizeToRead; ++i){
			((unsigned char*)data)[sizeToRead - 1 - i] = data_[i + m_iOffset];
		}
	}
	m_iOffset += sizeToRead;
}

int32 CReadFileStreamUtil::read(unsigned char* buffer, uint32 sizeToRead){
	//memcpy(buffer, m_Data.getBytes() + m_iOffset, sizeToRead);
	unsigned char* data_ = m_Data;
	for (uint32 i = 0; i < sizeToRead; ++i){
		((unsigned char*)buffer)[i] = data_[i + m_iOffset];
	}
	m_iOffset += sizeToRead;
	return sizeToRead;
}