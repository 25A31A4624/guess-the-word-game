#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
    vector<string> words = {
        "apple", "computer", "school",
        "program", "keyboard", "science",
        "college", "engineer"
    };

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(0, words.size() - 1);

    string secretWord = words[dis(gen)];
    string guessed(secretWord.length(), '_');

    int attempts = 6;
    char letter;
    bool found;

    cout << "===== Guess The Word Game =====\n";

    while (attempts > 0 && guessed != secretWord) {
        cout << "\nWord: ";

        for (char ch : guessed)
            cout << ch << " ";

        cout << "\nAttempts left: " << attempts;
        cout << "\nEnter a letter: ";
        cin >> letter;

        found = false;

        for (int i = 0; i < secretWord.length(); i++) {
            if (secretWord[i] == letter) {
                guessed[i] = letter;
                found = true;
            }
        }

        if (!found) {
            cout << "Wrong guess!";
            attempts--;
        } else {
            cout << "Correct guess!";
        }
    }

    if (guessed == secretWord)
        cout << "\n\nYou guessed the word: " << secretWord;
    else
        cout << "\n\nGame Over! Word was: " << secretWord;

    return 0;
}
