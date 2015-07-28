// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "CSkillDataMgr.h"

#include "Utils/CReadFileStreamUtil.h"
#include "Utils/CCommonHead.h"
#include "Template/SkillTemplate.h"

UCSkillDataMgr::UCSkillDataMgr()
{
}

UCSkillDataMgr::~UCSkillDataMgr()
{
}

bool UCSkillDataMgr::loadSkillData(FString _path)
{
	CReadFileStreamUtil* stream = new CReadFileStreamUtil();
	bool ret = stream->readFileStream(_path, CReadFileStreamUtil::ENUM_ENDIAN_MODE_BIG);
	if (ret)
	{
		int16 count = stream->readInt16();
		for (int16 i = 0; i < count; i++)
		{
			USkillTemplate* skillData = NewObject<USkillTemplate>(); //
			skillData->AddToRoot(); //·ÀÖ¹gc»ØÊÕ
			skillData->mId = stream->readInt32();
			skillData->mName = UTF8_TO_TCHAR(stream->readString().c_str());
			skillData->mDescr = UTF8_TO_TCHAR(stream->readString().c_str());
			skillData->mFilterVS = UTF8_TO_TCHAR(stream->readString().c_str());
			skillData->mIsAim = stream->readInt8();
			skillData->mTarget = stream->readInt8();
			skillData->mIsStop = stream->readInt8();
			skillData->mDistance = stream->readInt32();
			skillData->mLogicType = stream->readInt8();
			skillData->mBuffId = stream->readInt32();
			skillData->mPkbefor = UTF8_TO_TCHAR(stream->readString().c_str());
			skillData->mBeforEvn = UTF8_TO_TCHAR(stream->readString().c_str());
			skillData->mEndEvn = UTF8_TO_TCHAR(stream->readString().c_str());
			skillData->mPkend = UTF8_TO_TCHAR(stream->readString().c_str());
			skillData->mAtkType = stream->readInt8();
			skillData->mCDTime = stream->readInt32();
			skillData->mHpCost = stream->readInt32();
			skillData->mMpCost = stream->readInt32();
			skillData->mIcon = stream->readInt32();
			skillData->mHeroOwner = stream->readInt32();

			mSkillDataMap.Add(skillData->mId, skillData);
		}
	}
	stream->drop();

	return ret;
}

bool UCSkillDataMgr::loadBuffData(FString _path)
{
	return true;
}

USkillTemplate* UCSkillDataMgr::getSkillData(int32 _id)
{
	return mSkillDataMap.FindRef(_id);
}

USkillTemplate* UCSkillDataMgr::getBuffData(int32 _id)
{
	return nullptr;
}

void UCSkillDataMgr::printSkillMap()
{
	FString msg1 = FString::Printf(TEXT("--- map size:%d \n"), mSkillDataMap.Num());
	for (auto it = mSkillDataMap.CreateConstIterator(); it; ++it)
	{
		FString msg2 = FString::Printf(TEXT("--- mId:%d, mName:%s \n"), it->Key, *(it->Value->mName));
		msg1.Append(msg2);
	}
	GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Yellow, msg1);
}