#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <ctime>
using namespace std;


void initializeGame() {
 
    srand(static_cast<unsigned int>(time(0))); 

    wordQueue.push("algorithm");
    wordQueue.push("structure");
    wordQueue.push("compiler");
    wordQueue.push("terminal");
    wordQueue.push("function");
    
    cout << "Welcome to the DSA Word Guesser!" << endl;
    cout << "Words loaded into the Queue." << endl;
}

int main(){
	cout << initializeGame;
}