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
	CReadFileStreamUtil* rfs = new CReadFileStreamUtil();
	rfs->readFileStream(_path);
	rfs->drop();
	return true;
}