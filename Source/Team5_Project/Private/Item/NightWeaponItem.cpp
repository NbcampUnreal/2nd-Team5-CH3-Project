#include "Item/NightWeaponItem.h"

ANightWeaponItem::ANightWeaponItem()
{
   
    
    ItemType = "DefaultWeapon";
}

void ANightWeaponItem::ActivateItem(AActor* Activator)
{
    // �÷��̾� �±� Ȯ��
    if (Activator && Activator->ActorHasTag("Player"))
    {
        //����� �޽���
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Player gained Weapon!")));

    
        DestroyItem();
    }
}