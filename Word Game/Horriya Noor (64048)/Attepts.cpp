#include <iostream>
#include <string>
using namespace std;

// attempts

int playRound(const string& secretWord) {
    int maxAttempts = 7;
    int attemptsLeft = maxAttempts;
    string maskedWord(secretWord.length(), '_');
    set<char> guessedLetters; 
    
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
    
        if (input == "quit") return -1; 
        if (input == "next") return 0;  
        if (input == "score") {
            showScore();
            continue;
        }
        if (input == "hint") {
   
            if (giveHint(secretWord, maskedWord)) {
                attemptsLeft--;
            }
            continue;
        }
		
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
    
    // Checking results
    if (maskedWord == secretWord) {
        cout << "\n**CONGRATULATIONS!** You guessed the word: " << secretWord << endl;
        return attemptsLeft; 
    } else {
        cout << "\n**GAME OVER!** The word was: " << secretWord << endl;
        return 0; 
    }
}

int main (){
		 int roundScore = playRound(currentWord);
	return 0;
}

