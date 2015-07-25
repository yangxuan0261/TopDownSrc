// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBFL.generated.h"

class UTask;
class UCDataMgr;
class UCSkillDataMgr;

/**
 * 
 */
UCLASS()
class MYBTTEST_API UMyBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static void initAllGlobalMgr();

	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static UCDataMgr* GetDataMgr();

	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static UCSkillDataMgr* GetSkillDataMgr();

	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static UTask* createTask();
	
	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static bool ReadFile_HeroData(FString _path);

	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static bool ReadFile_ItemData(FString _path);

	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static bool ReadFile_Text(FString _path);

	UFUNCTION(BlueprintCallable, Category = "MyGlobalMgr")
	static bool ReadFile_SkillData(FString _path);

private:
	static UCDataMgr* mDataMgr;
	static UCSkillDataMgr* mSkillDataMgr;
};

