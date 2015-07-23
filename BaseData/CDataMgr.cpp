// Fill out your copyright notice in the Description page of Project Settings.

//#include "BaseData/CHeroData.h"


#include "MyBTTest.h"
#include "CDataMgr.h"
#include "Utils/CReadFileStreamUtil.h"
#include "Utils/CCommonHead.h"

#include "BaseData/CHeroData.h" //包含其他继承Uobject的头文件一定要在本类头文件之后CDataMgr.h，否则包错
#include "BaseData/CItemData.h"

UCDataMgr::UCDataMgr()
{
	reset();
}

UCDataMgr::~UCDataMgr()
{
	reset();
}

void UCDataMgr::reset()
{
	mHeroDataMap.Empty();
	mItemDataMap.Empty();
	mTextArr.Empty();
}

bool UCDataMgr::loadHeroData(FString _path)
{
	CReadFileStreamUtil* stream = new CReadFileStreamUtil();
	bool ret = stream->readFileStream(_path, CReadFileStreamUtil::ENUM_ENDIAN_MODE_BIG);
	if (ret)
	{
		int16 count = stream->readInt16();
		for (int16 i = 0; i < count; i++)
		{
			UCHeroData* heroData = NewObject<UCHeroData>(); //
			heroData->mId = stream->readInt32();
			heroData->mType = stream->readInt8();
			heroData->mName = UTF8_TO_TCHAR(stream->readString().c_str());
			heroData->mDescr = UTF8_TO_TCHAR(stream->readString().c_str());
			heroData->mAtkType = stream->readInt8();
			heroData->mMoveSpeed = stream->readInt32();
			heroData->mAtkSpeed = stream->readInt32();

			mHeroDataMap.Add(heroData->mId, heroData);

		}
		//FString msg1 = FString::Printf(TEXT("--- mId:%d, mName:%s \n"), heroData->mId, *heroData->mName);
		//GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Yellow, msg1);
	}
	stream->drop();

	return ret;
}

bool UCDataMgr::loadItemData(FString _path)
{
	CReadFileStreamUtil* stream = new CReadFileStreamUtil();
	bool ret = stream->readFileStream(_path, CReadFileStreamUtil::ENUM_ENDIAN_MODE_BIG);
	if (ret)
	{
		int16 count = stream->readInt16();
		for (int16 i = 0; i < count; i++)
		{
			UCItemData* itemData = NewObject<UCItemData>(); //
			itemData->mId = stream->readInt32();
			itemData->mName = UTF8_TO_TCHAR(stream->readString().c_str());
			itemData->mDescr = UTF8_TO_TCHAR(stream->readString().c_str());
			itemData->mUseLv = stream->readInt32();
			itemData->mUseRemark = UTF8_TO_TCHAR(stream->readString().c_str());
			itemData->mCanAdd = stream->readBool();
			itemData->mIcon = stream->readInt32();
			itemData->mAttribute = UTF8_TO_TCHAR(stream->readString().c_str());

			mItemDataMap.Add(itemData->mId, itemData);
		}
	}
	stream->drop();

	return ret;
}

bool UCDataMgr::loadText(FString _path)
{
	CReadFileStreamUtil* stream = new CReadFileStreamUtil();
	bool ret = stream->readFileStream(_path, CReadFileStreamUtil::ENUM_ENDIAN_MODE_BIG);
	if (ret)
	{
		int16 count = stream->readInt16();
		for (int16 i = 0; i < count; i++)
		{
			FString content = UTF8_TO_TCHAR(stream->readString().c_str());
			mTextArr.Add(content);
		}
	}
	stream->drop();

	return ret;
}

UCHeroData* UCDataMgr::getHeroData(int32 _id)
{
	return mHeroDataMap.FindRef(_id);
}

UCItemData* UCDataMgr::getItemData(int32 _id)
{
	return mItemDataMap.FindRef(_id);
}



void UCDataMgr::printHeroMap()
{
	FString msg1 = FString::Printf(TEXT("--- map size:%d \n"), mHeroDataMap.Num());
	for (auto it = mHeroDataMap.CreateConstIterator(); it; ++it)
	{
		FString msg2 = FString::Printf(TEXT("--- mId:%d, mName:%s \n"), it->Key, *(it->Value->mName));
		msg1.Append(msg2);
	}
	GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Yellow, msg1);
}