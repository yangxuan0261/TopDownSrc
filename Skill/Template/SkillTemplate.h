// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "SkillTemplate.generated.h"

/**
 * 
 */
UCLASS()
class MYBTTEST_API USkillTemplate : public UObject
{
	GENERATED_BODY()

public:
	USkillTemplate();
	virtual ~USkillTemplate();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillTemplate)
	int32	mskillId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillTemplate)
	FString	mNameStr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillTemplate)
	FString	mDescrStr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkillTemplate)
	FString	mAttributeStr;

};
