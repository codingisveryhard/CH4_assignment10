// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"

void UMyGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UserName = TEXT("Unknown");
}

void UMyGameInstanceSubsystem::Deinitialize()
{
    Super::Deinitialize();
}

void UMyGameInstanceSubsystem::SetUserInstanceName(const FString& NewName)
{
    UserName = NewName;
    UE_LOG(LogTemp, Log, TEXT("UserName set to: %s"), *UserName);
}

FString UMyGameInstanceSubsystem::GetUserInstanceName() const
{
    return UserName;
}
