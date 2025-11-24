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
    
}

int main(){
	cout<< playRound;
}