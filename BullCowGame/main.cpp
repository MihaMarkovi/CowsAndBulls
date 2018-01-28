//
//  main.cpp
//  BullCowGame
//
//  Created by Miha Markovič on 26. 01. 18.
//  Copyright © 2018 Miha Markovič. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuessAndPrintBack();

int main(int argc, const char * argv[]) {
    
    PrintIntro();
    PlayGame();
    
    return 0;
}

void PrintIntro() {
    // uvod
    constexpr int WORLD_LENGTH = 5;
    cout << "Welcome to bulls and cows" << endl;
    cout << "Can you guess the world with " << WORLD_LENGTH;
    cout << " characters" << endl;
    return;
}

string GetGuessAndPrintBack() {
    
    //vprasaj igralca
    string Guess = "";
    cout << "Type your answer here: ";
    getline(cin, Guess);
    
    //odgovori
    cout << "You typed " << Guess;
    cout << " in your console" << endl;
    
    return Guess;
}

void PlayGame(){
    
    constexpr int NUMBER_OF_TURNS = 5;
    for(int count = 1; count <= NUMBER_OF_TURNS; count++){
        GetGuessAndPrintBack();
        cout << endl;
    }
    
}
