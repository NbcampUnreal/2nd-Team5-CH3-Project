
#include "Weapon/NightWeaponSniper.h"


ANightWeaponSniper::ANightWeaponSniper()
{
	MaxBullet = 5;
	CurrentBullet = 5;
	WeaponType = "Sniper";
	Range = 5000.0f;
	Zoomtimes = 3;
}

//�������� �ܹ�
void ANightWeaponSniper::Fire()
{
	if (CurrentBullet == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("No Ammo"));
	}

	if (CurrentBullet != 0)
	{
		CurrentBullet--;
		UE_LOG(LogTemp, Error, TEXT("Ammo:%d"), CurrentBullet);
	}
	//delay �߰�?
}


void ANightWeaponSniper::Reload()
{
	CurrentBullet = MaxBullet;
}

void ANightWeaponSniper::ZoomIn()
{
	//ĳ������ ī�޶� ������Ʈ�� transform �� �̿�
}

void ANightWeaponSniper::ZoomOut()
{
	//ĳ������ ī�޶� ������Ʈ�� transform �� �̿�
}