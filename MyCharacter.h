// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UIdea;
class UTask;

UCLASS()
class MYBTTEST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	virtual ~AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = MyCharFunc)
	bool addTask(UTask* _task);

public:
	//TSubclassOf<UIdea> idea = UIdea::StaticClass();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyCharMember)
	 UIdea* idea;


};
