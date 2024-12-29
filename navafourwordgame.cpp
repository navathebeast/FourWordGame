#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>
#include <set>
#include <cctype>

using namespace std;


int main() {
    //words in Dictionary_4letterwords.pdf as a string vector
    std:: vector<std::string> words = { "ALSO","ABLE","ACID","AGED","AWAY",
        "BABY","BACK","BANK","BEEN","BALL","BASE","BUSY","BEND","BELL","BIRD",
        "COME","CAME","CALM","CARD","COAT","CITY","CHAT","CASH","CROW","COOK",
        "COOL","DARK","EACH","EVIL","EVEN","EVER","FACE","FACT","FOUR","FIVE",
        "FAIR","FEEL","FELL","FIRE","FINE","FISH","GAME","GONE","GOLD","GIRL",
        "HAVE","HAIR","HERE","HEAR","INTO","IRON","JUMP","KICK","KILL","LIFE",
        "LIKE","LOVE","MAIN","MOVE","MEET","MORE","NOSE","NEAR","OPEN","ONLY",
        "PUSH","PULL","SELL","SALE"};

    // seed the random number generator
    random_device rd;
    mt19937 g(rd());

    // shuffle with the seed of the random number generator
    shuffle(words.begin(), words.end(), g);

    // pick the first 4 words
    vector<string> selectedWords(words.begin(), words.begin() + 4);
    // set of the original 4 words
    const set<string> originalWords(selectedWords.begin(), selectedWords.end());

    // print the first 4 words from the shuffled list, uncomment if you'd like to see them
    /*
    cout << "Randomly picked 4 words:" << endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << selectedWords[i] << endl;
    }
    */

    // initialize 4x4 grid
    char grid[4][4];

    // selectedWords (vector of strings) -> letters (vector of letters)
    vector<char> letters;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            letters.push_back(selectedWords[i][j]);
        }
    }

    shuffle(letters.begin(), letters.end(), g);

    // fill the grid
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            grid[i][j] = letters[i * 4 + j];
        }
    }

    // print the grid
    cout << "Grid with shuffled letters of 4 words, guess them! :) Please type your words in all caps" << endl;
    for (const auto & i : grid) {
        for (char j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    constexpr int maxAttempts = 3; //user has max 3 attempts for winning
    vector<string> userGuesses(4);
    bool guessedCorrectly = false;

    for (int attempt = 0; attempt < maxAttempts; ++attempt) {
        //going through each attempt
        cout << "\nAttempt " << (attempt + 1) << " out of " << maxAttempts << endl; //eg Attempt 1 out of 3
        cout << "Enter your guessed for the 4 words (one word per line):" << endl;
        for (int i = 0; i < 4; ++i) {
            cin >> userGuesses[i];
        }
            set<string> userGuessesSet(userGuesses.begin(), userGuesses.end());
            //set of guesses so can compare with original words

            if (userGuessesSet == originalWords) {
                cout << "You win! All the words in the grid have been guessed correctly." << endl;
                guessedCorrectly = true;
                break;
            }
            else {
                if (attempt != 2) {
                    //so doesnt print when last attempt lose scenario lol
                    cout << "Those weren't the words. Next attempt starts now." << endl;
                }
            }
        }

        if (!guessedCorrectly) {
            cout << "You lose :( The words were:" << endl;
            for (const auto &word: originalWords) {
                cout << word << endl;
            }
        }
        return 0;
    }


