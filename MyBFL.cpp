// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "MyBFL.h"
#include "Task/Task.h"

UTask* UMyBFL::createTask()
{
	return UTask::StaticClass()->GetDefaultObject<UTask>();
}


bool UMyBFL::ReadFile(FString _path)
{
	CReadFileStreamUtil* stream = new CReadFileStreamUtil();
	stream->readFileStream(_path, CReadFileStreamUtil::ENUM_ENDIAN_MODE_BIG);
	if (stream)
	{
		int16 count = stream->readInt16();
		FString msg1 = FString::Printf(TEXT("--- count : %d \n"), count);
		for (int16 i = 0; i < count; i++)
		{
			int16 id = stream->readInt32();
			int16 icon = stream->readInt16();
			int16 lv = stream->readInt16();

			FString msg2 = FString::Printf(TEXT("--- id:%d, icon:%d, lv:%d \n"), id, icon, lv);
			//GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Yellow, msg2);
			msg1.Append(msg2);
		}
		GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Yellow, msg1);
	}
	stream->drop();

	return true;
}