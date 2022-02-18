#pragma once

#include "UObject/PrimaryAssetId.h"
#include "NPTypes.generated.h"

UENUM(BlueprintType)
enum class ENPAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Attack
};