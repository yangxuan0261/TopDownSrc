// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyCharTypes.generated.h"

UENUM(BlueprintType)
namespace ECharTeam
{
	enum Type
	{
		Unknown,
		Player,
		Enemy,
		MAX
	};
}

USTRUCT(BlueprintType)
struct FPawnData
{
	GENERATED_USTRUCT_BODY()

	/** minimal attack damage */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 AttackMin;

	/** maximum attack damage */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		int32 AttackMax;

	/** range of pawn attack */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		int32 AttackDistance;
	  
	/** damage reduction */
	/** damage reduction aaaaaaaaa */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		int32 DamageReduction;

	/** maximum health increase */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		int32 MaxHealthBonus;

	/** health change every 5 seconds */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		int32 HealthRegen;

	/** movement speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		float Speed;

	/** defaults */
	FPawnData()
	{
		AttackMin = 5;
		AttackMax = 10;
		DamageReduction = 0;
		MaxHealthBonus = 0;
		HealthRegen = 10;
		Speed = 0.0;
		AttackDistance = 100;
	}
};

USTRUCT(BlueprintType)
struct FBuffData
{
	GENERATED_USTRUCT_BODY()

	/** additive values */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FPawnData PawnData;

	/** set to ignore buff duration, not time limited */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Buff)
		uint8 bInfiniteDuration : 1;

	/** buff duration in seconds */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Buff)
		float Duration;

	/** runtime: buff ending time calculated when it's added */
	float EndTime;

	/** defaults */
	FBuffData()
	{
		bInfiniteDuration = false;
		Duration = 20.0f;
		EndTime = 0.0f;
	}

};