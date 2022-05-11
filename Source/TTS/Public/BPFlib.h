// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFlib.generated.h"

/**
 * 
 */
UCLASS()
class TTS_API UBPFlib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "TTS", meta = (DisplayName = "Start", Keywords = "Text To Speech"))
		static void Start();
	UFUNCTION(BlueprintCallable, Category = "TTS", meta = (DisplayName = "Quit", Keywords = "Text To Speech"))
			static void Quit();
	UFUNCTION(BlueprintCallable, Category = "TTS", meta = (DisplayName = "Speeak", Keywords = "Text To Speech"))
			static void Speak(const FString&Str);
};
