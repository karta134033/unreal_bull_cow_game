// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Press Tab and Enter to continue..."));
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (game_over) {
        ClearScreen();
        InitGame();
    } else {
        Guess(Input);
    }
}

void UBullCowCartridge::Guess(FString Input) {
    if (Lives > 0) {
        if (Input == HiddenWord) {
            PrintLine(TEXT("You Win"));
            EndGame();
        } else {
            --Lives;
            PrintLine(TEXT("Fuck off"));
            PrintLine(TEXT("%d lives left"), Lives);
        }
    }
    if (Lives == 0) {
        PrintLine(TEXT("Game Over"));
        EndGame();
    }
    // PrintLine(TEXT("HiddenWord is %s"), *HiddenWord); // PrintLine 需要運用指標才能找到string的array  i.g.cake -> [c, a, k, e, \0]
    PrintLine(Input);
}

void UBullCowCartridge::InitGame() {
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    game_over = false;
    PrintLine(TEXT("Welcome to Bull Cows"));
    PrintLine(TEXT("The hidden word is %i long"), HiddenWord.Len());
}

void UBullCowCartridge::EndGame() {
    game_over = true;
    PrintLine(TEXT("Press enter to play again."));
}
