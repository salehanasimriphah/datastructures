#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// --- GLOBAL DSA CONTAINERS ---

// Queue to hold the words for the game (FIFO: First-In, First-Out)
queue<string> wordQueue; 
// List to track the scores of previous rounds (Doubly Linked List)
list<int> scoreHistory; 

// --- GAME FUNCTIONS ---

/**
 *  Initializes the word queue and seeds the random generator.
 */
void initializeGame() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0))); 
    
    // Add words to the queue
    wordQueue.push("algorithm");
    wordQueue.push("structure");
    wordQueue.push("compiler");
    wordQueue.push("terminal");
    wordQueue.push("function");
    
    cout << "Welcome to the DSA Word Guesser!" << endl;
    cout << "Words loaded into the Queue." << endl;
}

/**
 * @brief Displays the score history stored in the list.
 */
void showScore() {
    if (scoreHistory.empty()) {
        cout << "\n? No scores recorded yet." << endl;
        return;
    }
    cout << "\n?? Score History (Most Recent First):" << endl;
    int gameNum = 1;
    // Iterate through the list
    for (int score : scoreHistory) { 
        cout << "  - Game " << gameNum++ << ": " << score << " points." << endl;
    }
}

/**
 * Provides a hint by revealing one unguessed letter.
 * @param secretWord The hidden word.
 * @param maskedWord The currently displayed word.
 * @return True if a hint was given, false otherwise.
 */
bool giveHint(const string& secretWord, string& maskedWord) {
    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (maskedWord[i] == '_') {
            maskedWord[i] = secretWord[i]; // Reveal the first unrevealed letter
            cout << "\n?? HINT: Revealed letter '" << secretWord[i] << "' at position " << i + 1 << "." << endl;
            return true;
        }
    }
    cout << "\n? No more letters to reveal for a hint!" << endl;
    return false;
}

/**
 *  The main game logic for a single round.
 * @param secretWord The word to guess.
 * @return The final score (attempts left).
 */
int playRound(const string& secretWord) {
    int maxAttempts = 7;
    int attemptsLeft = maxAttempts;
    string maskedWord(secretWord.length(), '_');
    set<char> guessedLetters; // Set for efficient checking of previously guessed letters
    
    cout << "\n--------------------------------------------------" << endl;
    cout << "?? Starting New Round! Word has " << secretWord.length() << " letters." << endl;

    while (attemptsLeft > 0 && maskedWord != secretWord) {
        cout << "\nWord: " << maskedWord << endl;
        cout << "Attempts Left: " << attemptsLeft << " | Guessed: ";
        for (char c : guessedLetters) cout << c << " ";
        cout << endl;
        
        cout << "Enter a letter, or an option (hint/quit/next/score): ";
        string input;
        cin >> input;
        
        // --- Option Handling ---
        if (input == "quit") return -1; // Special return for quit
        if (input == "next") return 0;  // Special return for next word
        if (input == "score") {
            showScore();
            continue;
        }
        if (input == "hint") {
            // Hint costs 1 attempt
            if (giveHint(secretWord, maskedWord)) {
                attemptsLeft--;
            }
            continue;
        }
        
        // --- Letter Guess Handling ---
        if (input.length() != 1 || !isalpha(input[0])) {
            cout << "Invalid input. Enter a single letter or an option." << endl;
            continue;
        }
        
        char guess = tolower(input[0]);
        if (guessedLetters.count(guess)) {
            cout << "You already guessed '" << guess << "'." << endl;
            continue;
        }
        guessedLetters.insert(guess);
        
        bool isCorrectGuess = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (tolower(secretWord[i]) == guess) {
                maskedWord[i] = secretWord[i]; 
                isCorrectGuess = true;
            }
        }
        
        if (isCorrectGuess) {
            cout << "? Good guess!" << endl;
        } else {
            attemptsLeft--;
            cout << "? Wrong guess!" << endl;
        }
    }
    
    // Check results
    if (maskedWord == secretWord) {
        cout << "\n**CONGRATULATIONS!** You guessed the word: " << secretWord << endl;
        return attemptsLeft; // Return remaining attempts as score
    } else {
        cout << "\n**GAME OVER!** The word was: " << secretWord << endl;
        return 0; // Loss score
    }
}

// --- MAIN FUNCTION ---

int main() {
    initializeGame();
    
    int totalScore = 0;
    
    while (!wordQueue.empty()) {
        string currentWord = wordQueue.front(); // Get the next word from the front of the Queue
        wordQueue.pop(); // Remove the word from the Queue
        
        int roundScore = playRound(currentWord);
        
        if (roundScore == -1) { // Quitting
            cout << "\n?? Quitting game. Final score: " << totalScore << endl;
            break;
        }
        
        if (roundScore > 0) { // Win or partial win (not quitting or next)
            totalScore += roundScore;
            scoreHistory.push_front(roundScore); // Add score to the front of the Linked List
        } else if (roundScore == 0) {
            // Either 'next' option or a loss, score is 0.
            scoreHistory.push_front(0); 
            
            // If the user chose 'next' but there are more words, continue.
            if (!wordQueue.empty()) {
                cout << "\n?? Skipping to the next word in the Queue." << endl;
            }
        }
        
        if (wordQueue.empty()) {
            cout << "\n**ALL WORDS GUESSED!**" << endl;
        }
    }
    
    if (wordQueue.empty()) {
        cout << "\n==============================================" << endl;
        cout << "?? Final Score: " << totalScore << " points." << endl;
        showScore();
        cout << "==============================================" << endl;
    }

    return 0;
}