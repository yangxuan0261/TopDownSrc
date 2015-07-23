// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "Object.h"
#include "CHeroData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYBTTEST_API UCHeroData : public UObject
{
	GENERATED_BODY()
	
public:
	UCHeroData();
	virtual ~UCHeroData();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HeroData)
		int32				mId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HeroData)
		uint8				mType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HeroData)
		FString			mName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HeroData)
		FString			mDescr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HeroData)
		uint8				mAtkType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HeroData)
		int32				mMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HeroData)
		int32				mAtkSpeed;
};

