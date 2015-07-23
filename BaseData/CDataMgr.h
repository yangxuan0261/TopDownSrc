// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class UCHeroData;
class UCItemData;

#include "Object.h"
#include "CDataMgr.generated.h" // "xxx.generated.h" should be always last include


/**
 * 
 */
UCLASS(Blueprintable)
class MYBTTEST_API UCDataMgr : public UObject
{
	GENERATED_BODY()
	
public:
	UCDataMgr();
	virtual ~UCDataMgr();
	void reset();

public:
	UFUNCTION(BlueprintCallable, Category = DataMgr)
		bool loadHeroData(FString _path);

	UFUNCTION(BlueprintCallable, Category = DataMgr)
		bool loadItemData(FString _path);

	UFUNCTION(BlueprintCallable, Category = DataMgr)
		bool loadText(FString _path);

public:
	UFUNCTION(BlueprintCallable, Category = DataMgr)
	UCHeroData* getHeroData(int32 _id);

	UFUNCTION(BlueprintCallable, Category = DataMgr)
	UCItemData* getItemData(int32 _id);

	UFUNCTION(BlueprintCallable, Category = DataMgr)
	void printHeroMap();
	
public:
	TMap<int32, UCHeroData*>			mHeroDataMap; //蓝图不支持TMap
	TMap<int32, UCItemData*>			mItemDataMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DataMgr)
		TArray<FString>								mTextArr; //蓝图支持TArray
};

