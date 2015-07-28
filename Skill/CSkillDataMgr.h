// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class USkillTemplate;
class UBuffTemplate;

#include "Object.h"
#include "CSkillDataMgr.generated.h"

/**
 * 
 */
UCLASS()
class MYBTTEST_API UCSkillDataMgr : public UObject
{
	GENERATED_BODY()
	
public:
	UCSkillDataMgr();
	virtual ~UCSkillDataMgr();
	void reset();

public:
	UFUNCTION(BlueprintCallable, Category = SkillDataMgr)
		bool loadSkillData(FString _path);

	UFUNCTION(BlueprintCallable, Category = SkillDataMgr)
		bool loadBuffData(FString _path);

public:
	UFUNCTION(BlueprintCallable, Category = SkillDataMgr)
		USkillTemplate* getSkillData(int32 _id);

	UFUNCTION(BlueprintCallable, Category = SkillDataMgr)
		USkillTemplate* getBuffData(int32 _id);

	UFUNCTION(BlueprintCallable, Category = SkillDataMgr)
		int32 getSkillDataMapLength() { return mSkillDataMap.Num(); }

	UFUNCTION(BlueprintCallable, Category = SkillDataMgr)
		void printSkillMap();

public:
	TMap<int32, USkillTemplate*>			mSkillDataMap; //À¶Í¼²»Ö§³ÖTMap
	
};
