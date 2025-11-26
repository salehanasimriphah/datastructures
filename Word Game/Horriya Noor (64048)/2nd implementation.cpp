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