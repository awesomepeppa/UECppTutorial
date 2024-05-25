// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(CppTutorial), meta=(BlueprintSpawnableComponent) )
class CPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//offset to move
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	//speed
	UPROPERTY(EditAnywhere)
	float Speed = 1.0f;

	//computed locations
	FVector StartRelativeLocation;
	FVector MoveOffsetNorm;
	float MaxDistance = 0.0f;
	float CurDistance = 0.0f;
	int MoveDirection = 1; 
};
