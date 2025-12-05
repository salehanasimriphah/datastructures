#include <iostream>
#include <string>
using namespace std;


bool giveHint(const string& secretWord, string& maskedWord) {
    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (maskedWord[i] == '_') {
            maskedWord[i] = secretWord[i]; 
            cout << "\n?? HINT: Revealed letter '" << secretWord[i] << "' at position " << i + 1 << "." << endl;
            return true;
        }
    }
    cout << "\n? No more letters to reveal for a hint!" << endl;
    return false;
}

int main() {
    initializeGame();
    
    int totalScore = 0;
    
    while (!wordQueue.empty()) {
        string currentWord = wordQueue.front(); 
        wordQueue.pop(); 
        
        int roundScore = playRound(currentWord);
        
        if (roundScore == -1) { 
            cout << "\n?? Quitting game. Final score: " << totalScore << endl;
            break;
        }
        
        if (roundScore > 0) {
            totalScore += roundScore;
            scoreHistory.push_front(roundScore); 
        } else if (roundScore == 0) {
          
            scoreHistory.push_front(0); 
            
            if (!wordQueue.empty()) {
                cout << "\n?? Skipping to the next word in the Queue." << endl;
            }
        }
        
        if (wordQueue.empty()) {
            cout << "\n**ALL WORDS GUESSED!**" << endl;
        }
    } 
    return 0;
}
