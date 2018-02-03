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

class FBullCowGame{
public:
    void Reset();
    int GetMaxTries();
    int GetCurrentTry();
    bool IsGameWon();
    bool CheckGuessValidity(std::string);
    
    
private:
    int MyCurrentTry;
    int MyMaxTries;
};
