// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyFileManager.generated.h"

/**
 * 
 */
UCLASS()
class ROGUELIGHT_API UMyFileManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
	UFUNCTION(BlueprintCallable, Category = "FileManagerBPLibrary")
	static FString LoadStringTextToFile(FString SaveDirectory, FString FName);


	UFUNCTION(BlueprintCallable, Category = "FileManagerBPLibrary")
	static bool SaveStringTextToFile(FString SaveDirectory, FString FName, FString SaveText, bool AllowOverWriting = false);

};
