#pragma once

#include "InGame/Weapons/SWeapon.h"
#include "SWeaponReloadable.generated.h"

UCLASS()
class SURVIVE_API ASWeaponReloadable : public ASWeapon
{
	GENERATED_BODY()

private:

	float timeLastReload; //Keeps track of the time passed since the weapon started to reload

protected:

	UPROPERTY(EditAnywhere, Category = Ammo) float reloadTime; //The reload time it takes to reload this weapon
	UPROPERTY(EditAnywhere, Category = Ammo) int32 slotAmmo; //The maximum ammo for slot
	UPROPERTY(EditAnywhere, Category = Ammo) int32 currentAmmo; //The current ammo in the slot

public:

	ASWeaponReloadable();
	~ASWeaponReloadable();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void Use() override;
	virtual bool CanBeUsed() override;

	virtual void Reload();

	UFUNCTION(BlueprintImplementableEvent, Category = Reload) 
		void OnReload();
};
