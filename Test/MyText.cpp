// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "MyText.h"


// Sets default values
AMyText::AMyText()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	CountdownText->SetTextRenderColor(FColor(0, 255, 0, 255));
	RootComponent = CountdownText;

	CountdownTime = 3;
}

//TODO: hello world Called when the game starts or when spawned
void AMyText::BeginPlay()
{
	Super::BeginPlay();
	UpdateTimerDisplay();
	//GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AMyText::AdvanceTimer, 1.0f, true);
	
	//TODO: delegate test
	mWriteLogDelegate.BindUObject(this, &AMyText::WriteLog);
	mMDWriteLog.AddUObject(this, &AMyText::WriteLog2);
	mMDWriteLog.AddUObject(this, &AMyText::WriteLog3);
}

// Called every frame
void AMyText::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMyText::UpdateTimerDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
}

void AMyText::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		// We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//Perform any special actions we want to do when the timer ends.
		CountdownHasFinished();
	}
}

void AMyText::CountdownHasFinished_Implementation()
{
	//Change to a special readout
	CountdownText->SetText(TEXT("GO!"));
	
	FString str = FString::Printf(TEXT("hello world - %d"), 123);

	//TODO: delegate test
	//mWriteLogDelegate.Execute(str);
	mMDWriteLog.Broadcast(str);
}

void AMyText::WriteLog(const FString& _str)
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, _str);
}

void AMyText::WriteLog2(const FString& _str)
{
	FString str = _str + FString(TEXT("- WriteLog2"));
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, str);
}


void AMyText::WriteLog3(const FString& _str)
{
	FString str = _str + FString(TEXT("- WriteLog3"));
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, str);
}