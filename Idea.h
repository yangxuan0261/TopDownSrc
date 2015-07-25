// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "Object.h"
#include "Idea.generated.h"

class UTask;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MYBTTEST_API UIdea : public UObject
{
	GENERATED_BODY()

public:
	UIdea();
	virtual ~UIdea();


	UFUNCTION(BlueprintCallable, Category = Idea)
	virtual void think(float delta);

	UFUNCTION(BlueprintCallable, Category = Idea)
	int32 addTask(int32 a, int32 b);
	
	UFUNCTION(BlueprintCallable, Category = Idea)
	bool removeTask(int32 a);

	UFUNCTION(BlueprintCallable, Category = Idea)
	bool addTask2(UTask* _task);
	
	int32 mTest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Idea)
	TArray<UTask*> mTaskArr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Idea)
	TArray<UTask*> mTaskAddArr;

};

