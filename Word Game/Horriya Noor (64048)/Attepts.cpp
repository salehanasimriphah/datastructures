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
        }   }
    
}

int main(){
	cout<< playRound;

}
