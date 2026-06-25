// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify/AnimNotify_AttackHitCheck.h"
#include "A1/A1NotifyInterface.h"

UAnimNotify_AttackHitCheck::UAnimNotify_AttackHitCheck()
{
}

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp)
	{
		IA1NotifyInterface* AttacActor = Cast<IA1NotifyInterface>(MeshComp->GetOwner());
		if (AttacActor)
		{
			AttacActor->AttackHitCheck(AttackRange, AttackRadius);
		}
	}
}
