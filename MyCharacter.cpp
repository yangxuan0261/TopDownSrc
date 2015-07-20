// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "MyCharacter.h"
#include "Idea.h"


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
	if (idea == nullptr)
		return false;

	idea->addTask2(_task);
	return true;
}

