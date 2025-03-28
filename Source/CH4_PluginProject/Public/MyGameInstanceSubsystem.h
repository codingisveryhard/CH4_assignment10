// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CH4_PLUGINPROJECT_API UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "User Data")
    void SetUserInstanceName(const FString& NewName);

    UFUNCTION(BlueprintPure, Category = "User Data")
    FString GetUserInstanceName() const;

private:
    FString UserName;
};
