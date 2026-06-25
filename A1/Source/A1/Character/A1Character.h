// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "A1NotifyInterface.h"
#include "Interface/A1NotifySkillInterface.h"
#include "A1Character.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;

UCLASS()
class A1_API AA1Character : public ACharacter, public IA1NotifyInterface, public IA1NotifySkillInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AA1Character();

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
	void SetDead();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UA1CharacterStatComponent> StatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UWidgetComponent> HpBarWidgetComponent;


public:
	void Input_Attack(const FInputActionValue& InputValue);
	void Input_Look(const FInputActionValue& InputValue);
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Skill(const FInputActionValue& InputValue);
public:
	UFUNCTION()
	void OnAttackMontaageEnded(UAnimMontage* Montage, bool bInterrupted);
	UFUNCTION()
	void OnSkillMontaageEnded(UAnimMontage* Montage, bool bInterrupted);
protected:
	UPROPERTY()
	TObjectPtr<class UA1MyAnimInstance> A1AnimInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Attack)
	uint8 bIsAttacking = false;

	uint8 bUseSkill = true;

	float SkillCoolTime = 5.0f;

	FTimerHandle SkillCoolTimerHandle;
public:
	virtual void AttackHitCheck(float AttackRange, float AttackRadius) override;
	virtual void SkillHitCheck(float SkillRange) override;
protected:
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> IMCShoulder;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> AttackAction;
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> JumpAction;
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> SkillAction;
};
