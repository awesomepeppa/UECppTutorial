// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentReachEndPointSignature, bool, IsTopEndpoint);

UCLASS( ClassGroup=(CppTutorial), meta=(BlueprintSpawnableComponent) )
class CPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove);

	UFUNCTION(BlueprintCallable)
	void ResetMovement();

	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	friend class FMoveComponentVisualizer;

	//offset to move
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	//speed
	UPROPERTY(EditAnywhere)
	float Speed = 1.0f;

	//Enable the movement of the component
	UPROPERTY(EditAnywhere)
	bool MoveEnable = true;

	// On Extreme reached event
	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndpointReached; 

	//computed locations
	FVector StartRelativeLocation;
	FVector MoveOffsetNorm;
	float MaxDistance = 0.0f;
	float CurDistance = 0.0f;
	int MoveDirection = 1; 
};
