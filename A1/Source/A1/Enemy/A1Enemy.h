// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/A1AIAttackInterface.h"
#include "A1NotifyInterface.h"
#include "A1Enemy.generated.h"

UCLASS()
class A1_API AA1Enemy : public ACharacter, public IA1AIAttackInterface, public IA1NotifyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AA1Enemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
public:
	void SetEnemyDead();
public:
	// IA1AIAttackInterface을(를) 통해 상속됨
	void AttackByAI() override;

	void SetAIAttackFinishedDelegate(const FAIAttackFinished& InOnAttackFinished) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UWidgetComponent> HpBarWidgetComponent;
public:
	UFUNCTION()
	void OnEnemyAttackMontageEnded(UAnimMontage* Montage, bool bIntgerrupted);
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UA1CharacterStatComponent> StatComponent;
public:
	UPROPERTY()
	TObjectPtr<class UA1MyAnimInstance> A1AnimInstance;

	FAIAttackFinished OnAiAttackFinished;

	// IA1NotifyInterface을(를) 통해 상속됨
	void AttackHitCheck(float AttackRange, float AttackRadius) override;
};
