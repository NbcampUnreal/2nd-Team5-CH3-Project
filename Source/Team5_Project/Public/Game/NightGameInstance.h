// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NightGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TEAM5_PROJECT_API UNightGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UNightGameInstance();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	TArray<int32> LevelDeathCounts; // ���� �� ���� Ƚ��

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	TArray<float> LevelClearTimes; // ���� �� Ŭ���� �ð�

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 TotalDeathCount; // �� ���� Ƚ��

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	float TotalClearTime; // ���� Ŭ������� �ɸ� �ð�

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Level")
	int32 CurrentLevelIndex; // ���� ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	TArray<FString> LevelNames; // ���� �̸�

	static const int32 MaxLevels = 2;

public:
	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddDeathCount(int32 DeathCount); // ��� �������� ���� Ƚ�� ���ϱ�

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddTotalTime(float TimeCount); // ���� Ŭ������� �ɸ� �ð� ���ϱ�(Ŭ���� �����ߴ� ������ �ð��� ���� ����)

	UFUNCTION(BlueprintCallable, Category = "Game")
	FString GetNextLevelName(); // ���� �̸� ��� 

	void SaveLevelStats(float ClearTime, int32 DeathCount); //���� ���

};
