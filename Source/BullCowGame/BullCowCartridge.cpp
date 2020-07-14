// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows"));
    PrintLine(TEXT("Press Tab and Enter to continue..."));

    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (Lives > 0) {
        if (Input == HiddenWord) {
            PrintLine(TEXT("Win"));
        } else {
            PrintLine(TEXT("Fuck off"));
            Lives--;
        }
    }
    if (Lives == 0) {
        PrintLine(TEXT("You've done."));
    }
    PrintLine(TEXT("%d lives left"), Lives);
    PrintLine(TEXT("HiddenWord is %i long"), HiddenWord.Len());
    PrintLine(TEXT("HiddenWord is %s"), *HiddenWord); // PrintLine 需要運用指標才能找到string的array  i.g.cake -> [c, a, k, e, \0]
    PrintLine(Input);
}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    Lives = 5;
}
