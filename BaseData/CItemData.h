// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "CItemData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MYBTTEST_API UCItemData : public UObject
{
	GENERATED_BODY()
	
public:
	UCItemData();
	virtual ~UCItemData();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		int32			mId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		FString		mName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		FString		mDescr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		int32			mUseLv;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		FString		mUseRemark;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		bool			mCanAdd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		int32				mIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ItemData)
		FString		mAttribute;
};
