// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "SkillTemplate.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYBTTEST_API USkillTemplate : public UObject
{
	GENERATED_BODY()

public:
	USkillTemplate();
	virtual ~USkillTemplate();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	FString			mName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	FString			mDescr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	FString			mFilterVS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	uint8					mIsAim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	uint8					mTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	uint8					mIsStop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	uint8					mLogicType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mBuffId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	FString			mPkbefor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	FString			mBeforEvn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	FString			mEndEvn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	FString			mPkend;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	uint8					mAtkType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mCDTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mHpCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mMpCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = SkillTemplate)
	int32				mHeroOwner;

};
