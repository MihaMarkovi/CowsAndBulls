//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Miha Markovič on 1. 02. 18.
//  Copyright © 2018 Miha Markovič. All rights reserved.
//

/* This is console executeable, that makes use of BullCow class.,
 This acts as MVC pattern, and is responsible for a user interaction.
 For game logic see FBullCowGame class.
*/
#include "FBullCowGame.hpp"

using int32 = int;

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return static_cast<int>(MyHiddenWord.length()); }

void FBullCowGame::Reset(){
    
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "donkey";
    
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    return;
    
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
    return EWordStatus::OK; //TODO make actual error
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // incriment the turn number
    MyCurrentTry++;
    
    // setup a return variable
    FBullCowCount BullCowCount;
    
    // loop through all letters in the guess
    int32 HiddenWordLength = static_cast<int32>(MyHiddenWord.length());
    for(int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++){
        
        // compare letters against the hidden word
        for(int32 GChar = 0; GChar < HiddenWordLength; GChar++){
            
            // if they match then
            if(Guess[GChar] == MyHiddenWord[MHWChar]){
                
                // increments bulls if they're in the same place
                if(MHWChar == GChar){
                    
                    BullCowCount.Bulls++;
                }
                else {
                    BullCowCount.Cows++;
                }
            // increment cows if not
            }
        }
    }
    return BullCowCount;
};
