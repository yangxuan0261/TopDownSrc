// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyText.generated.h"

DECLARE_DELEGATE_OneParam(FStringDelegate,const FString&);
DECLARE_MULTICAST_DELEGATE_OneParam(FSMDelegate, const FString&);

UCLASS()
class MYBTTEST_API AMyText : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyText();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
		int32 CountdownTime;

	UPROPERTY(EditAnywhere)
		UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay();

	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();

	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle;
	

	//TODO: delegate test
	FStringDelegate mWriteLogDelegate;
	FSMDelegate mMDWriteLog;
	void WriteLog(const FString& _str);
	void WriteLog2(const FString& _str);
	void WriteLog3(const FString& _str);
};
