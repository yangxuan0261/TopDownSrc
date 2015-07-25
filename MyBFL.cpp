// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "MyBFL.h"

#include "Task/Task.h"
#include "Utils/CReadFileStreamUtil.h"
#include "Utils/CCommonHead.h"
#include "BaseData/CDataMgr.h"
#include "Skill/CSkillDataMgr.h"

UCDataMgr* UMyBFL::mDataMgr = nullptr;
UCSkillDataMgr* UMyBFL::mSkillDataMgr = nullptr;

void UMyBFL::initAllGlobalMgr()
{
	mDataMgr = UCDataMgr::StaticClass()->GetDefaultObject<UCDataMgr>();
	mSkillDataMgr = UCSkillDataMgr::StaticClass()->GetDefaultObject<UCSkillDataMgr>();
}

UCDataMgr* UMyBFL::GetDataMgr()
{
	return mDataMgr;
}

UCSkillDataMgr* UMyBFL::GetSkillDataMgr()
{
	return mSkillDataMgr;
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

bool UMyBFL::ReadFile_SkillData(FString _path)
{
	return mSkillDataMgr->loadSkillData(_path);
}
