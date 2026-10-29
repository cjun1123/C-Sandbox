#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Hangman.h"

int main(){
    //Generate Secret Word
    secretWord newWord = secretWord(Initialization());

    //Declare the user and game moderator
    userProgress newProgress;
    gameModerator newModerator;

    while (newModerator.get_hangmanStatus() == 0){
        newModerator.promptUser(newProgress);
        for (const auto& word : newProgress.get_guessLibrary()) {
            std::cout << word << " ";
        }
        std::cout << newProgress.get_guessLibrary().size() << std::endl;
        std::cout << newProgress.get_guessLibrary()[0][0] << std::endl;
        std::cout << typeid(newProgress.get_guessLibrary()[0][0]).name() << std::endl;
        newProgress.countGuesses();
        std::cout << newProgress.get_numberOfGuesses();
        
        newProgress.updateUserWordState(newWord);
        std::cout << newWord.get_secretWord() << std::endl;

        newModerator.displayGuessesLeft(newProgress);
        newModerator.displayLettersGuessed(newProgress);
        newModerator.displayHangman(newProgress);

        newModerator.winCondition(newProgress);
    }
    
    return 0;
}