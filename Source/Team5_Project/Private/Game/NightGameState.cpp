// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/NightGameState.h"
#include "Game/NightGameInstance.h"
#include <Kismet/GameplayStatics.h>

#include "Actors/NightDungeon_Doorway.h"

ANightGameState::ANightGameState()
{
    DeathCount = 0;
    //    CurrentLevelIndex = 0;
    OverlapTriggerCount = 0;
}

void ANightGameState::BeginPlay()
{
    Super::BeginPlay();
}

void ANightGameState::OnPlayerDeath()
{
    DeathCount++;
}

void ANightGameState::EndLevel()
{
    float ClearTime = GetWorld()->GetTimeSeconds();

    UNightGameInstance* GameInstance = Cast<UNightGameInstance>(GetGameInstance());
    if (GameInstance)
    {
        GameInstance->SaveLevelStats(ClearTime, DeathCount);
    }
}

void ANightGameState::OnGameFinished()
{
    // 현재 HUD 가져오기
    /*
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
    }
    */
}

void ANightGameState::IncreaseOverlapTriggerCount()
{
    OverlapTriggerCount++;

    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap %d"), OverlapTriggerCount));

    if (OverlapTriggerCount >= 5)
    {
        EndLevel();
        OpenTheGate();
        //LoadNextLevel();
    }
}

void ANightGameState::LoadNextLevel()
{
    UNightGameInstance* GameInstance = Cast<UNightGameInstance>(GetGameInstance());
    if (GameInstance)
    {
        int32 LevelCount = GameInstance->LevelNames.Num();
        int32 NextIndex = GameInstance->CurrentLevelIndex + 1;

        UE_LOG(LogTemp, Warning, TEXT("Current Level Index: %d"), GameInstance->CurrentLevelIndex);
        UE_LOG(LogTemp, Warning, TEXT("Total Levels: %d"), LevelCount);
        UE_LOG(LogTemp, Warning, TEXT("Next Level Index: %d"), NextIndex);

        if (NextIndex >= LevelCount)
        {
            UE_LOG(LogTemp, Error, TEXT("Game End"));
            return;
        }

        GameInstance->CurrentLevelIndex = NextIndex;
        FString NextLevelName = GameInstance->LevelNames[NextIndex]; 

        UE_LOG(LogTemp, Warning, TEXT("Next Level: %s"), *NextLevelName);

        if (!NextLevelName.IsEmpty())
        {
            UGameplayStatics::OpenLevel(GetWorld(), FName(*NextLevelName));
        }
    }
}

void ANightGameState::OpenTheGate()
{
    ANightDungeon_Doorway* FoundDoorway = Cast<ANightDungeon_Doorway>(UGameplayStatics::GetActorOfClass(GetWorld(), ANightDungeon_Doorway::StaticClass())); // 게임 월드에서 ANightDungeon_Doorway 클래스의 액터를 검색
    if (FoundDoorway) // 발견된 경우
    {
        FoundDoorway->OpenDoors(); // 문을 여는 동작 호출
    }
}
