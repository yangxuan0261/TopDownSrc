// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBFL.generated.h"

class UTask;
class UCDataMgr;

/**
 * 
 */
UCLASS()
class MYBTTEST_API UMyBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyBFL")
		static void init();

	UFUNCTION(BlueprintCallable, Category = "MyBFL")
	static UTask* createTask();
	
	UFUNCTION(BlueprintCallable, Category = "MyBFL")
		static bool ReadFile_HeroData(FString _path);

	UFUNCTION(BlueprintCallable, Category = "MyBFL")
		static bool ReadFile_ItemData(FString _path);

	UFUNCTION(BlueprintCallable, Category = "MyBFL")
		static UCDataMgr* GetDataMgr();


private:
	static UCDataMgr* mDataMgr;
};

