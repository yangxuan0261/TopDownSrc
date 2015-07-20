// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "BuffTemplate.generated.h"

/**
 * 
 */
UCLASS()
class MYBTTEST_API UBuffTemplate : public UObject
{
	GENERATED_BODY()
	
public:
	UBuffTemplate();
	virtual ~UBuffTemplate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BuffTemplate)
		int32	mskillId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BuffTemplate)
		FString	mNameStr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BuffTemplate)
		FString	mDescrStr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BuffTemplate)
		FString	mAttributeStr;
	
};
