// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFileManager.h"
#include "FileHelper.h"



bool UMyFileManager::SaveStringTextToFile(FString SaveDirectory, FString FName, FString SaveText, bool AllowOverWriting)
{
	if (!IFileManager::Get().DirectoryExists(*SaveDirectory)) {
		IFileManager::Get().MakeDirectory(*SaveDirectory);

		if (!IFileManager::Get().DirectoryExists(*SaveDirectory))
		{
			return false;
		}
	}

	SaveDirectory += "\\";
	SaveDirectory += FName;

	if (!AllowOverWriting) {
		if (IFileManager::Get().GetFileAgeSeconds(*SaveDirectory) > 0) {
			return false;
		}
	}

	return FFileHelper::SaveStringToFile(SaveText, *SaveDirectory);
}


FString UMyFileManager::LoadStringTextToFile(FString SaveDirectory, FString FName) {



	if (!IFileManager::Get().DirectoryExists(*SaveDirectory)) {
		IFileManager::Get().MakeDirectory(*SaveDirectory);

		if (!IFileManager::Get().DirectoryExists(*SaveDirectory))
		{
			return "";
		}
	}

	SaveDirectory += "\\";
	SaveDirectory += FName;

	FString result;
	FFileHelper::LoadFileToString(result, *SaveDirectory);
	return result;
}