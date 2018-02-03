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

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

int main(int argc, const char * argv[]) {
    
    bool bPlayAgain = false;
    
    do{
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain);
    return 0;
}

void PrintIntro() {
    // uvod
    constexpr int WORLD_LENGTH = 5;
    std::cout << "Welcome to bulls and cows" << std::endl;
    std::cout << "Can you guess the world with " << WORLD_LENGTH;
    std::cout << " characters" << std::endl;
    return;
}

std::string GetGuess() {
    
    //vprasaj igralca
    std::string Guess = "";
    std::cout << "Type your answer here: ";
    std::getline(std::cin, Guess);
    
    return Guess;
}

void PlayGame(){
    
    FBullCowGame BCGame;
    int MaxTries = BCGame.GetMaxTries();
    
    for(int count = 1; count <= MaxTries; count++){
        std::string Guess =GetGuess();
        std::cout << std::endl;
        //odgovori
        std::cout << "You typed " << Guess;
        std::cout << " in your console" << std::endl;
    }
    
}

bool AskToPlayAgain(){
    std::cout << "Do you want to play again (y/n): ";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');
}
