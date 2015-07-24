// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "MyCharacter.h"

#include "Idea.h"
#include "BaseData/CItemData.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AMyCharacter::~AMyCharacter()
{

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	idea = UIdea::StaticClass()->GetDefaultObject<UIdea>();
}

// Called every frame
void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

bool AMyCharacter::addTask(UTask* _task)
{
	//if (idea == nullptr)
	//	return false;

	//idea->addTask2(_task);
	//FString str = FString::Printf(TEXT("hello world - %d"), 123);
	//GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, str);

	//tmpItemData = NewObject<UCItemData>();
	//tmpItemData->mId = 123;
	//tmpItemData->mName = FString("hello world");
	return true;
}

bool AMyCharacter::removeTask()
{
	//FString str = FString::Printf(TEXT("hello world - %d, name:%s"), tmpItemData->mId, *(tmpItemData->mName));
	//GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, str);
	return true;
}

