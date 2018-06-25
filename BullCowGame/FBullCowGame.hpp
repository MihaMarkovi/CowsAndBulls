//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Miha Markovič on 1. 02. 18.
//  Copyright © 2018 Miha Markovič. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#endif /* FBullCowGame_hpp */

using int32 = int;
using FString = std::string;

//all values initialized to zero
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus
{
    OK,
    Not_ISOGRAM
};

class FBullCowGame{
public:
    FBullCowGame(); //constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    bool IsGameWon() const;
    EWordStatus CheckGuessValidity(FString) const;
    
    void Reset(); //TODO make more rich return value
    FBullCowCount SubmitGuess(FString);
    
private:
    //see constructor
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};
