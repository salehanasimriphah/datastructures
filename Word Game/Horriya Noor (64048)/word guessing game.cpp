#include <iostream>
#include <string>
#include <queue>
#include <list>   //for storing scores of players
#include <set>     //Used to store guessed letters, because it keeps elements unique, sorted, and allows quick searching.
using namespace std;
queue<string> wordQueue; //Yeh word list store karne ke liye hai.

list<int> scoreHistory; //Yeh har round ke score ko store karne ke liye hai.
// Making Circular Liked-List
class Player {
public:
string player_id;
int score;
Player* next;
/*Player constructor har naye player ka ID set karta hai, uska score 0 karta hai, aur next pointer ko nullptr rakhta hai 
taake baad mein circular linked list ke nodes properly connect ho saken. */
Player(const string& id) : player_id(id), score(0), next(nullptr) {}
};                      
class CircularLinkedList {
public:  //can be accessed from outside the CircularLinkedList class.
Player* head;  
CircularLinkedList() : head(nullptr) {} //: head(nullptr) uses an initializer list to set the head pointer to nullptr (a null pointer),list is initially empty.
void addPlayer(const string& id) {
Player* np = new Player(id);  //A pointer np (for New Player) is created to hold the address of this new node.
if (!head) {
head = np;   //If the list is empty, the new node np becomes the first and only node. The head pointer is set to point to np. 
np->next = head;
} else {
Player* t = head;
while (t->next != head) t = t->next;   //loop traverses the list to find the last node.
t->next = np; // The next pointer of the current last node (t) is updated to point to the new node (np).
np->next = head;  // The next pointer of the new node (np) is set to point to the head node.(making new node)
}
}
void showScores() {
if (!head) return;
Player* t = head;
cout << "\n[Player Scores]\n";
do {
cout << " " << t->player_id << " = " << t->score << endl;
t = t->next;
} while (t != head);
}
Player* findWinner(int winning_score) {
if (!head) return nullptr;
Player* t = head;
do {
if (t->score >= winning_score) return t;
t = t->next;
} while (t != head);
return nullptr;
}
};
void initializeGame() {
wordQueue.push("algorithm");
wordQueue.push("structure");
wordQueue.push("compiler");
wordQueue.push("terminal");
wordQueue.push("function");
cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^  Welcome to the DSA Word Guesser! ^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
cout << "____________________________ loaded into the Queue. ______________________________________" << endl;
}
// Score Formation
void showScore() {
if (scoreHistory.empty()) {
cout << "\nNo scores recorded yet." << endl;
return;
}
cout << "\nScore History (Most Recent First):" << endl;
int gameNum = 1;
// Iterating through the list
for (int score : scoreHistory) { 
cout << " - Game " << gameNum++ << ": " << score << " points." << endl;
}
}
// Hint Formation
bool giveHint(const string& secretWord, string& maskedWord) {
for (size_t i = 0; i < secretWord.length(); ++i) {
if (maskedWord[i] == '_') {
maskedWord[i] = secretWord[i]; 
cout << "\nHINT: Revealed letter '" << secretWord[i] << "' at position " << i + 1 << "." << endl;
return true;
}
}
cout << "\nNo more letters to reveal for a hint!" << endl;
return false;
}

// Attempts  and guess letters

int playRound(const string& secretWord) {
int maxAttempts = 7;
int attemptsLeft = maxAttempts;
string maskedWord(secretWord.length(), '_');
set<char> guessedLetters; // checking efficiency of previously guessed letters
cout << "\n--------------------------------------------------" << endl;
cout << ",,,,,,,,,,, Starting New Round!,,,,,,,,,,,,,,,\n  Word has " << secretWord.length() << " letters." << endl;
while (attemptsLeft > 0 && maskedWord != secretWord) {
cout << "\nWord: " << maskedWord << endl;
cout << "Attempts Left: " << attemptsLeft << " | Guessed: ";
for (char c : guessedLetters) cout << c << " ";
cout << endl;
cout << "Enter a letter, or an option (hint/quit/next/score): ";
string input;
cin >> input;
// --- Option Handling ---
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
cout << "----------------Invalid input. Enter a single letter or an option.-------------------" << endl;
continue;
}
char guess = tolower(input[0]);
if (guessedLetters.count(guess)) {
cout << "**************** You already guessed ******************************'" << guess << "'." << endl;
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
cout << "*************************** Good guess! ******************************" << endl;
} else {
attemptsLeft--;
cout << "---------------------------- Wrong guess! ----------------------------" << endl;
}
}
// Checking results
if (maskedWord == secretWord) {
cout << "\n********CONGRATULATIONS!**********  You guessed the word: " << secretWord << endl;
return attemptsLeft; 
} else {
cout << "\n**GAME OVER!** The word was: " << secretWord << endl;
return 0; 
}
}
int playRoundMultiplayer(const string& secretWord, CircularLinkedList& players, Player*& current) {
int maxAttempts = 7;
int attemptsLeft = maxAttempts;
string maskedWord(secretWord.length(), '_');
set<char> guessedLetters;
cout << "\n--------------------------------------------------" << endl;
cout << "Multiplayer Round! Word has " << secretWord.length() << " letters." << endl;
while (attemptsLeft > 0 && maskedWord != secretWord) {
cout << "\nWord: " << maskedWord << endl;
cout << " ^^/ Attempts Left: " << attemptsLeft << " | Current: " << current->player_id << endl;
cout << "Guessed Letters: ";
for (char c : guessedLetters) cout << c << " ";
cout << endl;
cout << "\n" << current->player_id << endl;
cout << "===> Enter a letter or option (hint/quit/next/score): ";
string input;
cin >> input;
if (input == "quit") return -1; 
if (input == "next") { 
cout << current->player_id << " skipped the word.\n";
return 0;
}
if (input == "score") {
players.showScores();
continue;
}
if (input == "hint") {
if (giveHint(secretWord, maskedWord)) {
attemptsLeft--;
cout << "Hint used. Attempts decreased by 1.\n";
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
// Checking guess
bool isCorrect = false;
int revealedCount = 0;
for (size_t i = 0; i < secretWord.length(); ++i) {
if (tolower(secretWord[i]) == guess) {
if (maskedWord[i] == '_') {
maskedWord[i] = secretWord[i];
isCorrect = true;
revealedCount++;
}
}
}
if (isCorrect) {
current->score += revealedCount; 
cout << "Correct! " << current->player_id << " gains " << revealedCount << " point(s).\n";
} else {
attemptsLeft--;
cout << " ^^?  Wrong Attempt by " << current->player_id << "!\n";
cout << "((((((((((((((((You lost your Turn..... !))))))))))))))))\n";
cout << ".............Next Players Turn!!!....... \n";
current = current->next; 
}
players.showScores();
}
// Round ended: check result
if (maskedWord == secretWord) {
cout << "\n********CONGRATS!******** \n  Word guessed: " << secretWord << endl;
// giving bonus to the player who completed the word
cout << current->player_id << " gets +2 bonus points for completing the word!\n";
current->score += 2;
players.showScores();
return 1;
} else {
cout << "\n**ROUND OVER!** Attempts exhausted. The word was: " << secretWord << endl;
return 0; 
}
}
int main() {
    initializeGame();

    cout << "\nChoose mode: (1) Single-player  (2) Multiplayer\nEnter 1 or 2: ";
    int mode = 1;
    cin >> mode;

    if (mode == 1) {
        // single-player (original behaviour)
        int totalScore = 0;
        while (!wordQueue.empty()) {
            string currentWord = wordQueue.front();
            wordQueue.pop();

            int roundScore = playRound(currentWord);

            if (roundScore == -1) {
                cout << "\nQuitting game. Final score: " << totalScore << endl;
                break;
            }

            if (roundScore > 0) {
                totalScore += roundScore;
                scoreHistory.push_front(roundScore);
            } else {
                scoreHistory.push_front(0);
                if (!wordQueue.empty()) cout << "\nSkipping to the next word in the Queue." << endl;
            }

            if (wordQueue.empty()) cout << "\n*ALL WORDS GUESSED!*" << endl;
        }

        cout << "\n==============================================" << endl;
        cout << "Final Score: " << totalScore << " points." << endl;
        showScore();
        cout << "==============================================" << endl;
    } 
    else {
        // Multiplayer mode
        CircularLinkedList players;
        
        // CHANGE: Take number of players from user instead of fixed 3
        int numPlayers;
        cout << "\nEnter number of players: ";
        cin >> numPlayers;
        
        // Create players based on user input
        for (int i = 1; i <= numPlayers; i++) {
            players.addPlayer("Player " + to_string(i));
        }

        Player* current = players.head;

        cout << "\nMultiplayer mode started. Players will take turns. Wrong guess -> turn passes." << endl;

        while (!wordQueue.empty()) {
            string currentWord = wordQueue.front();
            wordQueue.pop();

            int res = playRoundMultiplayer(currentWord, players, current);
            if (res == -1) {
                cout << "\nMultiplayer aborted by user.\n";
                break;
            }

            if (wordQueue.empty()) cout << "\n*ALL WORDS DONE!*\n";
        }

        cout << "\nMultiplayer finished. Final scores:\n";
        players.showScores();

        int winning_score = 5;
        Player* winner = players.findWinner(winning_score);
        if (winner) {
            cout << "\nWinner (reached " << winning_score << "): " << winner->player_id << " with " << winner->score << " points.\n";
        } else {
            if (players.head) {
                Player* t = players.head->next;
                Player* best = players.head;
                do {
                    if (t->score > best->score) best = t;
                    t = t->next;
                } while (t != players.head);
                cout << "\nTop scorer: " << best->player_id << " with " << best->score << " points.\n";
            }
        }
    }

    return 0;
}
