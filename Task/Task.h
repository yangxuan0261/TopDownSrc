// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Task.generated.h"

/**
 * 
 */
UCLASS()
class MYBTTEST_API UTask : public UObject
{
	GENERATED_BODY()
	
public:
	UTask();
	virtual ~UTask();
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Task)
	//static UTask* createTask();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Task)
	bool isStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Task)
	bool isOver;

};
