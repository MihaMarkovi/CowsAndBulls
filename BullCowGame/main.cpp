//
//  main.cpp
//  BullCowGame
//
//  Created by Miha Markovič on 26. 01. 18.
//  Copyright © 2018 Miha Markovič. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using int32 = int;
using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main(int32 argc, const char * argv[]) {
    
    bool bPlayAgain = false;
    
    do{
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain);
    return 0; //exit the application
}


void PrintIntro()
{
    std::cout << "Welcome to bulls and cows" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " characters" << std::endl;
    return;
}

void PlayGame(){
    
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    for(int32 count = 1; count <= MaxTries; count++){
        FText Guess =GetGuess(); // TODO check loop
        //print validate guess
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
        std::cout << " Cows = " << BullCowCount.Cows << std::endl;

        
        //std::cout << "You typed " << Guess;
    }
    //TODO summarise game
}

FText GetGuess() {
    
    //vprasaj igralca
    int32 CurrentTry = BCGame.GetCurrentTry();
    FText Guess = "";
    std::cout << " Try ";
    std::cout << CurrentTry << std::endl;
    std::cout << " Type your answer here: ";
    std::getline(std::cin, Guess);
    
    return Guess;
}

bool AskToPlayAgain(){
    std::cout << " Do you want to play again (y/n): ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
