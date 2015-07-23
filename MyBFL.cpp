// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "MyBFL.h"
#include "Task/Task.h"
#include "Utils/CReadFileStreamUtil.h"
#include "Utils/CCommonHead.h"
#include "BaseData/CDataMgr.h"

UCDataMgr* UMyBFL::mDataMgr = nullptr;

void UMyBFL::init()
{
	 mDataMgr = UCDataMgr::StaticClass()->GetDefaultObject<UCDataMgr>();
}

UCDataMgr* UMyBFL::GetDataMgr()
{
	return mDataMgr;
}

UTask* UMyBFL::createTask()
{
	return UTask::StaticClass()->GetDefaultObject<UTask>();
}

bool UMyBFL::ReadFile_HeroData(FString _path)
{
	return mDataMgr->loadHeroData(_path);
}

bool UMyBFL::ReadFile_ItemData(FString _path)
{
	return mDataMgr->loadItemData(_path);
}

bool UMyBFL::ReadFile_Text(FString _path)
{
	return mDataMgr->loadText(_path);
}
