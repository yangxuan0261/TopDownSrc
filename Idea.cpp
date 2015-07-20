// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBTTest.h"
#include "Idea.h"




UIdea::UIdea()
{
	mTest = 100;
}

UIdea::~UIdea()
{
}

void UIdea::think(float delta)
{

}

int32 UIdea::addTask(int32 a, int32 b)
{
	return a + b + mTest;
}

bool UIdea::removeTask(int32 a)
{
	//mTaskArr.RemoveAt(a);
	return true;
}

bool UIdea::addTask2(UTask* _task)
{
	mTaskArr.Add(_task);
	return true;
}
