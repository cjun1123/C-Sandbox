#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Hangman.h"

//Game Moderator Functions

int gameModerator::get_totalGuessesAllowed(){
    return totalGuessesAllowed;
}

char gameModerator::get_userGuess(){
    return userGuess;
}

int gameModerator::get_hangmanStatus(){
    return hangmanStatus;
}

void gameModerator::displayHangman(userProgress& progress){
    switch (progress.get_numberOfGuesses()){
        case 0:
            std::cout << "Good job! No wrong guesses so far. Hangman is fine!" << std::endl;
            break;
        case 1:
            std::cout << "  O  " << std::endl;
            break;
        case 2:
            std::cout << "  O  " << std::endl;
            std::cout << "  |  " << std::endl;
            std::cout << "  |  " << std::endl;
            break;
        case 3:
            std::cout << "  O  " << std::endl;
            std::cout << " /|  " << std::endl;
            std::cout << "  |  " << std::endl;
            break;
        case 4:
            std::cout << "  O  " << std::endl;
            std::cout << " /|\\ " << std::endl;
            std::cout << "  |  " << std::endl;
            break;
        case 5:
            std::cout << "  O  " << std::endl;
            std::cout << " /|\\ " << std::endl;
            std::cout << "  |  " << std::endl;
            std::cout << " /   " << std::endl;
            break;
        case 6:
            std::cout << "  O  " << std::endl;
            std::cout << " /|\\ " << std::endl;
            std::cout << "  |  " << std::endl;
            std::cout << " / \\ " << std::endl;
            break;
        case 7:
            std::cout << "  O  " << std::endl;
            std::cout << " /|\\ " << std::endl;
            std::cout << "  |  " << std::endl;
            std::cout << " / \\ " << std::endl;
            std::cout << " o   " << std::endl;
            break;
        case 8:
            std::cout << "  O  " << std::endl;
            std::cout << " /|\\ " << std::endl;
            std::cout << "  |  " << std::endl;
            std::cout << " / \\ " << std::endl;
            std::cout << " o o " << std::endl;
            break;
    }
}

void gameModerator::displayGuessesLeft(userProgress& progress){
    auto guessesLeft = get_totalGuessesAllowed() - progress.get_numberOfGuesses();
    std::cout << "You have " << guessesLeft << " guesses left." << std::flush << std::endl;
}

void gameModerator::displayLettersGuessed(userProgress& progress){
    std::cout << "Letters Guessed: "; 
 
    const auto& library = progress.get_guessLibrary();
    
    for (int i = 0; i < library.size(); i++){
        std::cout << library[i] << std::flush;
    };
    std::cout << std::endl;
}

void gameModerator::promptUser(userProgress& progress){
    std::cout << "Guess a letter" << std::endl;
    std::cin >> userGuess;
    progress.addtoGuessLibrary(userGuess);
}

void gameModerator::winCondition(userProgress& progress){
    if (progress.get_numberOfGuesses() == totalGuessesAllowed){
        std::cout << "Game over! Hangman is dead :(" << std::endl;
        hangmanStatus = 1;
    }
}

//Initialization

std::string Initialization(){
    //Create Dictionary
    std::ifstream inFile;
    std::string str;
    std::vector<std::string> dictionary;

    inFile.open("/workspaces/C-Sandbox/Projects/Hangman/words_alpha.txt");

    if (inFile.fail()){
        std::cout << std::endl << "File not found!" << std::endl;
    }
    else {
        while (!inFile.eof()){
            getline(inFile, str);
            dictionary.push_back(str);
        }
    }

    //Generate Random Number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, dictionary.size());

    //Generate Random Word
    int num = distrib(gen);
    return dictionary[num];
}

/*int initialization::generateRandomNumber(std::vector<std::string> dictionary){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, dictionary.size());

    return distrib(gen);
    
};

std::vector<std::string> initialization::createDictionary(){
    std::ifstream inFile;
    std::string str;
    std::vector<std::string> dictionary;

    inFile.open("people.txt");

    if (inFile.fail()){
        std::cout << std::endl << "File not found!" << std::endl;
    }
    else {
        while (!inFile.eof()){
            getline(inFile, str);
            dictionary.push_back(str);
        }
    }
    return dictionary;
}

std::string initialization::generateWord(){
    std::ifstream inFile;
    std::string str;
    std::vector<std::string> dictionary;
    int num;

    dictionary = initialization::createDictionary();

    num = initialization::generateRandomNumber(dictionary);

    return dictionary[num];
}*/


//Secret Word Functions
secretWord::secretWord(std::string word){
    secretWordWord = word;
    wordLength = word.length();
}

std::string secretWord::get_secretWord(){
    return secretWordWord;
}

int secretWord::get_wordLength(){
    return secretWordWord.length();
}

//User Progress Functions
int userProgress::get_numberOfGuesses(){
    return numberOfGuesses;
}
std::string userProgress::get_userWordState(){
    return userWordState;
}
std::vector<std::string> userProgress::get_guessLibrary(){
    return guessLibrary;
}

void userProgress::addtoGuessLibrary(char guess){
    std::string libraryGuess = guess + std::string(" ,");
    guessLibrary.push_back(libraryGuess);
}

void userProgress::resetUserProgress(){
    userWordState = "";
    guessLibrary = {};
    numberOfGuesses = 0;
}

void userProgress::countGuesses(){
    numberOfGuesses++;
}

void userProgress::updateUserWordState(secretWord& userWord){
    char letter;
    std::string word = userWord.get_secretWord();

    for (int j = 0; j < guessLibrary.size(); j++){ //change it because it checks the first, prints the first just fine, then checks the second and prints the whole thing. loop needs to take the existing updated word and search through that...
        for (int i = 0; i < userWord.get_wordLength(); i++){
            if (guessLibrary[j][0] == word[i]){ //guess library has 'char ,' in each slot, so referencing the first char of the individual string should be fine
                std::cout << word[i] << std::flush;
            }
            else{
                std::cout << "_" << std::flush;
            }
        }
    }
}