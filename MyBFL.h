// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Utils/CReadFileStreamUtil.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBFL.generated.h"

class UTask;

/**
 * 
 */
UCLASS()
class MYBTTEST_API UMyBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MyBFL")
	static UTask* createTask();
	
	UFUNCTION(BlueprintCallable, Category = "MyBFL")
		static bool ReadFile(FString _path);
};
