#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>

std::string Initialization();

class userProgress;

class gameModerator{ //manages all functions to run the game
private:
    const int totalGuessesAllowed = 8;
    char userGuess;
    int hangmanStatus = 0; //0 means alive, 1 means dead
public:
    int get_totalGuessesAllowed();
    char get_userGuess();
    int get_hangmanStatus();

    void displayHangman(userProgress& progress);
    void displayGuessesLeft(userProgress& progress);
    void displayLettersGuessed(userProgress& progress);
    void promptUser(userProgress& progress); //prompts user to enter a guess and stores it in userGuess as well as guess library
    void winCondition(userProgress& progress); //if user reaches total guesses allowed, they lose; if they complete the word, they win
};

/*class initialization{
public:
    std::vector<std::string> createDictionary();
    int generateRandomNumber(std::vector<std::string> dictionary);
    std::string generateWord();
};*/

class secretWord{
private:
    std::string secretWordWord;
    int wordLength;
public:
    secretWord(std::string word); //Constructor
    std::string get_secretWord();
    int get_wordLength();
};

class userProgress{
private:
    int numberOfGuesses = 0;
    std::string userWordState ={}; //showing users which letters fit where in the word and what they still need to guess
    std::vector<std::string> guessLibrary ={}; //contains all the letters the user has guessed
public:
    //userProgress(int numberOfGuesses, userWordState, guessLibrary)
    int get_numberOfGuesses();
    std::string get_userWordState(); //might change to vectors later
    std::vector<std::string> get_guessLibrary();

    void addtoGuessLibrary(char guess);
    void resetUserProgress();
    void countGuesses();

    void updateUserWordState(secretWord& userWord);

};