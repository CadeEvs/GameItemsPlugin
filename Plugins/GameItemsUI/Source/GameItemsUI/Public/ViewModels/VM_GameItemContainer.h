﻿// Copyright Bohdon Sayre, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_GameItemContainer.generated.h"

class UGameItem;
class UVM_GameItemSlot;
class UGameItemContainer;


/**
 * A view model for a game item container.
 */
UCLASS()
class GAMEITEMSUI_API UVM_GameItemContainer : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UGameItemContainer* GetContainer() const { return Container; }

	/** Set the container to use. */
	UFUNCTION(BlueprintCallable)
	void SetContainer(UGameItemContainer* NewContainer);

	/** Return the total number of slots in the container. */
	UFUNCTION(BlueprintPure, FieldNotify)
	int32 GetNumSlots() const;

	/** Return all items in the container. */
	UFUNCTION(BlueprintPure, FieldNotify)
	TArray<UGameItem*> GetItems() const;

	/** Return a slot view model for each slot in the container. Designed for use with list views. */
	UFUNCTION(BlueprintPure, FieldNotify)
	TArray<UVM_GameItemSlot*> GetSlotViewModels() const;

protected:
	/** The owning container. */
	UPROPERTY(Transient, BlueprintReadOnly, FieldNotify)
	UGameItemContainer* Container;

	/** The cached view models for each slot. */
	UPROPERTY(Transient)
	TArray<UVM_GameItemSlot*> SlotViewModels;

	void OnItemAdded(UGameItem* Item);
	void OnItemRemoved(UGameItem* Item);
	void OnNumSlotsChanged(int32 NewNumSlots, int32 OldNumSlots);
};
