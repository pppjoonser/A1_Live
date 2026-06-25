// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify/AnimNotify_SkillHitCheck.h"
#include "Interface/A1NotifySkillInterface.h"

UAnimNotify_SkillHitCheck::UAnimNotify_SkillHitCheck()
{

}

void UAnimNotify_SkillHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp)
	{
		IA1NotifySkillInterface* AttacActor = Cast<IA1NotifySkillInterface>(MeshComp->GetOwner());
		if (AttacActor)
		{
			AttacActor->SkillHitCheck(SkillRange);
		}
	}
}
